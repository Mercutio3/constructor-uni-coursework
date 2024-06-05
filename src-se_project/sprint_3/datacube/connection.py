import requests
from datacube.errors import WCPSConnectionError
from datacube.datacube import Datacube
import xml.etree.ElementTree as ET

class WCPSConnection:
    def __init__(self, url):
        # Initialize WCPSConnection object with WCPS server URL
        self.url = url

    def check_connection(self):
        # Send GET request to server to check if it's reachable
        # Raise an exception for HTTP errors
        try:
            response = requests.get(self.url)
            response.raise_for_status()  
            return True  # Connection successful
        except requests.exceptions.RequestException as e:
            # Handle connection errors
            return False  # Connection failed

    def get_coverage_details(self, endpoint):
        # Construct full URL
        full_url = self.url + endpoint
        
        # Send GET request to URL
        response = requests.get(full_url)
        
        # Check response status, parse if successful
        if response.status_code == 200:
            # Assuming server responds with XML-formatted data
            root = ET.fromstring(response.content)
            
            namespaces = {
                'wcs20': 'http://www.opengis.net/wcs/2.0',
                'wcs21': 'http://www.opengis.net/wcs/2.1',
                'cis11': 'http://www.opengis.net/cis/1.1/gml',
                'gml': 'http://www.opengis.net/gml',
                'swe': 'http://www.opengis.net/swe/2.0'
            }
            
            # Extract coverage name, axes' names and ranges
            coverage_name = root.find('.//wcs20:CoverageId', namespaces=namespaces).text

            # Extract AxisExtents
            axis_labels = []
            ranges = []
            for axis_extent in root.findall('.//cis11:AxisExtent', namespaces=namespaces):
                axis_labels.append(axis_extent.get('axisLabel'))
                ranges.append([axis_extent.get('lowerBound'),axis_extent.get('upperBound')])
                
            return Datacube(coverage_name, axis_labels, ranges)
        else:
            return None, None, None

    def execute_query(self, query):
        try:
            # Send POST request to server to execute WCPS query
            response = requests.post(self.url, data=query)

            # Check if request was successful (status code 200)
            if response.status_code == 200:
                return response.text  # Return response text
            else:
                # If request not successful, print error status code
                print(f"Error: {response.status_code}")
                return None  # Return None
        except requests.exceptions.RequestException as e:
            # Handle connection errors
            raise WCPSConnectionError(f"Error executing query: {e}")  # Raise WCPSConnectionError with error message

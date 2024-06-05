# Necessary imports
import sys
sys.path.append("..")
from datacube.connection import WCPSConnection
from datacube.datacube import Datacube

# Define server endpoint
serverUrl = "https://ows.rasdaman.org/rasdaman/ows"

### First example ###

# Create WCPSConnection object with the user-defined URL
db_connection = WCPSConnection(serverUrl)

# Create a datacube with details from specified coverage
avgLandTempEndpoint = "?&SERVICE=WCS&VERSION=2.10&REQUEST=DescribeCoverage&COVERAGEID=AvgLandTemp&outputType=GeneralGridCoverage"
AvgLandTempDatacube = db_connection.get_coverage_details(avgLandTempEndpoint)

# Register actions as access() calls based on axis name and access value
actions = [
    AvgLandTempDatacube.access("Lat", 53.08),
    AvgLandTempDatacube.access("Long", 8.80),
    AvgLandTempDatacube.access("ansi", "2014-07")
]

# Generate query based on actions provided
query = AvgLandTempDatacube.generate_query(actions)

# Execute query through a POST request to the server
result = db_connection.execute_query(query)


### Second example ###

# Create a second WCPS connection object
db_connection2 = WCPSConnection(serverUrl)

# Create another datacube with details from specified coverage
avgLandTempEndpoint = "?&SERVICE=WCS&VERSION=2.10REQUEST=DescribeCoverageCOVERAGEID=AvgLandTempoutputType=GeneralGridCoverge"
AvgLandTempDatacube2 = db_connection2.get_coverage_details(avgLandTempEndpoint)

# Alternative way of encoding actions as access() calls
encodeActions = [AvgLandTempDatacube2.access("Lat", 53.08), AvgLandTempDatacube2.access("Long", 8.80), AvgLandTempDatacube2.subset("ansi", "2014-01", "2014-12")]
actions = [AvglandTempDatacube2.encode(encodeActions, "text/csv")]

# Generate query based on provided actions
query = AvgLandTempDatacube2.generate_query(actions)

# Execute query through a POST request to the server
result = db_connection2.execute_query(query)
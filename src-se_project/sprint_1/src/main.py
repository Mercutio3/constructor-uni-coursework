# Main method file to test library

import sys
sys.path.append("../src")
from wdc import wdc

if __name__ == "__main__":
    # Define server URL of choice
    serverUrl = "https://ows.rasdaman.org/rasdaman/ows"
    
    # Initialize library object and one DataCube
    wdc = wdc(serverUrl)
    dbo = wdc.createDBO()

    # Add operations (queries) to the DataCube
    dbo.addOperation("for $c in (AvgLandTemp) return 1")
    dbo.addOperation("for $c in (AvgLandTemp) return 2")
    dbo.addOperation("for $c in (AvgLandTemp) return 10")
    
    # Send a single query of choice to server, print result
    dbo.executeOperation(1)
    dbo.executeOperation(3)

    # Execute all queries stored in the DataCube, print results
    dbo.executeAllOperations()

    print("Success.")
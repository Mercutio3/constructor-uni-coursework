# Python library to handle connection and datacube object
# URL associated with an instance of WDC will be used for 
# all connections and datacubes.

from dbc import dbc
from dbo import dbo

class wdc:
    # Initialize database connection object with user-specified URL
    def __init__(self, server_url):
        self.dbc = dbc(server_url)

    # Create DataCube object
    def createDBO(self):
        return dbo(self.dbc)
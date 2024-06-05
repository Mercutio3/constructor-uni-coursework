import pytest
from datacube.connection import WCPSConnection
from datacube.datacube import Datacube

@pytest.fixture
def db():
    server_url = "https://ows.rasdaman.org/rasdaman/ows"

    return WCPSConnection(server_url)

def test_get_coverage_details(db):
    dc = db.get_coverage_details("?&SERVICE=WCS&VERSION=2.1.0&REQUEST=DescribeCoverage&COVERAGEID=AvgLandTemp&outputType=GeneralGridCoverage")

    assert type(dc) == Datacube

def test_check_connection(db):
    assert type(db.check_connection())==bool
    
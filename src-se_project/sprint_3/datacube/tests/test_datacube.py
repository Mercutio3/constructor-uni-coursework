import pytest
from datacube.datacube import Datacube

@pytest.fixture
def dc():
    coverageName = "AvgTempLand"
    axesNames = ["Lat", "Long", "ansi"]
    axesRanges = [[-90, 90], [-180, 180], ["2000-02-01T00:00:00.000Z","2015-06-01T00:00:00.000Z"]]

    return Datacube(coverageName, axesNames, axesRanges)

def test_initialization(dc):
    expectedAxesRanges = {
        "Lat" : (-90, 90),
        "Long": (-180, 180),
        "ansi" : (dc.convert_to_iso("2000-02-01T00:00:00.000Z"), dc.convert_to_iso("2015-06-01T00:00:00.000Z")),
    }

    assert dc.coverageName == "AvgTempLand"
    assert dc.axesRanges["Lat"] == expectedAxesRanges["Lat"]
    assert dc.axesRanges["Long"] == expectedAxesRanges["Long"]
    assert dc.axesRanges["ansi"] == expectedAxesRanges["ansi"]

def test_access(dc):
    assert dc.access("Lat", -70) == "Lat(-70)"
    assert dc.access("ansi", "2014-01") == 'ansi("2014-01")'

def test_subset(dc):
    assert dc.subset("Lat", -90, -70) == "Lat(-90:-70)"
    assert dc.subset("ansi", "2014-01" , "2014-12") == 'ansi("2014-01":"2014-12")'

def test_generate_query(dc):
    assert dc.generate_query([dc.access("Lat", -90)]) == f"for $c in (AvgTempLand) return ($c[Lat(-90)])"
    assert dc.generate_query([dc.access("Lat", -90), dc.access("Long", -180)]) == f"for $c in (AvgTempLand) return ($c[Lat(-90),Long(-180)])"
    assert dc.generate_query([dc.access("Lat", -90), dc.subset("ansi", "2014-01" , "2014-12")]) == f'for $c in (AvgTempLand) return ($c[Lat(-90),ansi("2014-01":"2014-12")])'
    assert dc.generate_query([dc.encode([dc.access("Lat", -90), dc.access("Long", -180)], "image/png")]) == f'for $c in (AvgTempLand) return (encode($c[Lat(-90),Long(-180)],"image/png"))'
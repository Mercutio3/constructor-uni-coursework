import unittest
from unittest.mock import patch
import sys
sys.path.append("../src")
from wdc import wdc
from dbc import dbc

class TestWdc(unittest.TestCase):
    def test_create_dbo(self):
        # Mock a dbc instance for testing purposes
        mock_dbc = dbc

        # Mock the dbc class to return the mock_dbc instance
        with unittest.mock.patch('wdc.dbc', return_value=mock_dbc):
            # Initialize a WDC instance
            wdc_instance = wdc('https://ows.rasdaman.org/rasdaman/ows')

            # Create a DBO instance using the wdc instance
            dbo_instance = wdc_instance.createDBO()

            # Assert that the returned DBO instance is not None
            self.assertIsNotNone(dbo_instance)

            # Assert that the DBO instance uses the mocked dbc instance
            self.assertEqual(dbo_instance.dbc, mock_dbc)

if __name__ == '__main__':
    unittest.main()

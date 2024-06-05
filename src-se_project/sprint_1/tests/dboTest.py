import unittest
import sys
sys.path.append("../src")
from dbo import dbo
from dbc import dbc

class TestDbo(unittest.TestCase):
    def setUp(self):
        # Mock a dbc instance for testing purposes
        self.dbc = dbc

        # Initialize a DBO instance with the mocked dbc
        self.dbo = dbo(self.dbc)

    def test_add_operation(self):
        # Add some operations
        self.dbo.addOperation("for $c in (AvgLandTemp) return 1")
        self.dbo.addOperation("for $c in (AvgLandTemp) return 2")

        # Assert that the operations array contains the added operations
        self.assertEqual(self.dbo.operations, ["for $c in (AvgLandTemp) return 1", "for $c in (AvgLandTemp) return 2"])

    def test_execute_operation(self):
        # Add a mock response for the dbc.query method
        self.dbc.query.return_value = b'Successful response'

        # Add an operation
        self.dbo.addOperation("for $c in (AvgLandTemp) return 1")

        # Execute the operation
        self.dbo.executeOperation(1)

        # Assert that dbc.query is called with the correct query
        self.dbc.query.assert_called_once_with("for $c in (AvgLandTemp) return 1")

    def test_execute_all_operations(self):
        # Add mock responses for the dbc.query method
        self.dbc.query.side_effect = [b'Response 1', b'Response 2']

        # Add some operations
        self.dbo.addOperation("for $c in (AvgLandTemp) return 1")
        self.dbo.addOperation("for $c in (AvgLandTemp) return 2")

        # Execute all operations
        self.dbo.executeAllOperations()

        # Assert that dbc.query is called with the correct queries
        self.assertEqual(self.dbc.query.call_count, 2)
        self.dbc.query.assert_any_call("for $c in (AvgLandTemp) return 1")
        self.dbc.query.assert_any_call("for $c in (AvgLandTemp) return 2")

if __name__ == '__main__':
    unittest.main()

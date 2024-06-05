import unittest
from unittest.mock import patch
import sys
sys.path.append("../src")
from dbc import dbc

class TestDbc(unittest.TestCase):
    def setUp(self):
        # Initialize a DBC instance with the correct URL for testing
        self.dbc = dbc('https://ows.rasdaman.org/rasdaman/ows')

    @patch('requests.post')
    def test_query_success(self, mock_post):
        # Mocking the response of requests.post for a successful request
        mock_post.return_value.status_code = 200
        mock_post.return_value.content = b'Successful response'
        
        # Test the query method with a sample query
        response = self.dbc.query('for $c in (AvgLandTemp) return 1')
        
        # Assert that the response is as expected   
        self.assertEqual(response, b'Successful response')
        
        # Assert that the HTTP request URL is printed
        self.assertTrue(mock_post.called)
        self.assertTrue(mock_post.call_args[1]['params']['query'], 'SELECT * FROM table')

    @patch('requests.post')
    def test_query_failure(self, mock_post):
        # Mocking the response of requests.post for a failed request
        mock_post.return_value.status_code = 404
        mock_post.return_value.text = 'Not Found'
        
        # Test the query method with a sample query that should fail
        with self.assertRaises(Exception) as context:
            self.dbc.query('SELECT * FROM table')
        
        # Assert that the error message is as expected
        self.assertTrue('Error: 404, Not Found' in str(context.exception))
        
        # Assert that the HTTP request URL is printed even in case of failure
        self.assertTrue(mock_post.called)
        self.assertTrue(mock_post.call_args[1]['params']['query'], 'SELECT * FROM table')

    @patch('requests.post')
    def test_query_empty_query(self, mock_post):
        # Test the query method with an empty query
        with self.assertRaises(Exception) as context:
            self.dbc.query('')
        
        # Assert that the error message is as expected
        self.assertTrue('Error: 400' in str(context.exception))
        
        # Assert that no HTTP request is made
        self.assertFalse(mock_post.called)

    @patch('requests.post')
    def test_query_invalid_url(self, mock_post):
        # Test the query method with an invalid URL
        self.dbc.url = 'invalid_url'
        with self.assertRaises(Exception) as context:
            self.dbc.query('SELECT * FROM table')
        
        # Assert that the error message is as expected
        self.assertTrue('Error: Invalid URL' in str(context.exception))
        
        # Assert that no HTTP request is made
        self.assertFalse(mock_post.called)

if __name__ == '__main__':
    unittest.main()

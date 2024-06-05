# Datacube Object
# Stores operations (queries) in the operations array

class dbo:
    # Initialize dbc corresponding to this dbo and the operations array
    def __init__(self, dbc):
        self.dbc = dbc
        self.operations = []

    # Add query to operation array
    def addOperation(self, operation):
        self.operations.append(operation)
    
    def executeOperation(self, index):
        print("Executing query "+str(index))
        # Print query for debugging purposes
        print("Query: "+self.operations[index-1])
        
        # Initiate query sending, return result
        result = self.dbc.query(self.operations[index-1])
        print("Result:", result.decode('utf-8'))
        print("----------")

    def executeAllOperations(self):
        # Simple for loop to execute all queries, compensates for index shift
        for i in range(0,len(self.operations)):
            self.executeOperation(i+1)

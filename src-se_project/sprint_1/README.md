# Datacube Library Project

## About the project

This project is an implementation of a Python library that provides an interface to interact with a WCPS server. It implements a datacube object with some methods which generate WCPS queries, send them to the server, fetch results, and update internal state accordingly.

## Getting Started

### Structure

In the "src" folder you can find three files:
* dbc, the database connection object responsible for connection to the server. 
* dbo, the datacube object itself, which holds queries and can execute them.
* wdc, the main library file which creates and manages the other two objects.

In the "src" folder you can find the "main.py" file which is the main interaction interface.

### Prerequisites

Depending on your Python build, you might have to install some libraries before using.
* requests
  ```sh
  pip install requests owslib numpy scipy matplotlib
  ```

## Usage

As mentioned before, the user interacts with the library through the main.py file.

### Setting URL and creating DataCubes

To create a DataCube, you must first create an instance of the WDC library. Each WDC has a single server URL associated with it.

Now, to create a DBO (DataCube), simply call WDC's createDBO() method.

When you create a WDC, a DBC will be automatically created and associated with it. All DataCubes created with a WDC will use this DBC.

### Adding Operations

To add an operation to a DataCube, call the respective DataCube's addOperation() method. It takes a string parameter, which is where you enter your WCPS query. A DataCube can store an unlimited amount of queries. These are internally stored in an array.

### Executing Operations

You have to options here. One is to execute an individual operation with the executeOperation() method. Simply call this method and pass the index of the query you wish to run. For ease of use, indexing starts with 1, NOT 0.

The other option is to execute all operations stored in the datacube. Simply call the executeAllOperations() method. It will execute all queries in ascending index order.

## Testing

Testing your code is crucial to ensure its correctness and robustness. This project provides classes to handle database connections (`dbc`), datacube operations (`dbo`), and a higher-level interface (`wdc`) to manage these components. Below is a guide on how to test and interact with these classes:

#### 1. `dbc`:

The `dbc` class facilitates database connections and querying. Here's how to interact with it:

- **Purpose**: Establish and manage connections to a database server.
- **How to Interact**: 
  - Create a `dbc` instance by providing the URL of the database server.
  - Use the `query` method to send SQL queries to the server.
- **Testing**: Refer to the provided test cases in the `dbcTest.py` file to ensure that the `dbc` class functions correctly.

#### 2. `dbo`:

The `dbo` class represents a datacube object and stores operations to be executed. Here's how to interact with it:

- **Purpose**: Store and execute operations (queries) on a datacube.
- **How to Interact**: 
  - Create a `dbo` instance by providing a `dbc` instance.
  - Add operations using the `addOperation` method.
  - Execute individual operations using the `executeOperation` method or execute all operations using the `executeAllOperations` method.
- **Testing**: Refer to the provided test cases in the `dboTest.py` file to ensure that the `dbo` class functions correctly.

#### 3. `wdc`:

The `wdc` class acts as a higher-level interface to manage database connections and datacube objects. Here's how to interact with it:

- **Purpose**: Manage `dbc` and `dbo` instances, providing a streamlined interface.
- **How to Interact**: 
  - Create a `wdc` instance by providing the URL of the database server.
  - Use the `createDBO` method to create `dbo` instances associated with the `wdc` instance.
- **Testing**: Refer to the provided test cases in the `wdcTest.py` file to ensure that the `wdc` class functions correctly.

#### Running Tests:

To test the functionality of the provided classes:
- Ensure all necessary files (`dbc.py`, `dbo.py`, `wdc.py`) are in the `src` folder.
- Execute the test script (e.g., `python dbcTest.py`) in your terminal.

### Testing

Testing your code is crucial to ensure its correctness and robustness. This project provides classes to handle database connections (`dbc`), datacube operations (`dbo`), and a higher-level interface (`wdc`) to manage these components. Below is a guide on how to test and interact with these classes:

#### 1. `dbc`:

The `dbc` class facilitates database connections and querying. Here's how to interact with it:

- **Purpose**: Establish and manage connections to a database server.
- **How to Interact**: 
  - Create a `dbc` instance by providing the URL of the database server.
  - Use the `query` method to send SQL queries to the server.
- **Testing**: Refer to the provided test cases in the `dbcTest.py` file to ensure that the `dbc` class functions correctly.

#### 2. `dbo`:

The `dbo` class represents a datacube object and stores operations to be executed. Here's how to interact with it:

- **Purpose**: Store and execute operations (queries) on a datacube.
- **How to Interact**: 
  - Create a `dbo` instance by providing a `dbc` instance.
  - Add operations using the `addOperation` method.
  - Execute individual operations using the `executeOperation` method or execute all operations using the `executeAllOperations` method.
- **Testing**: Refer to the provided test cases in the `dboTest.py` file to ensure that the `dbo` class functions correctly.

#### 3. `wdc`:

The `wdc` class acts as a higher-level interface to manage database connections and datacube objects. Here's how to interact with it:

- **Purpose**: Manage `dbc` and `dbo` instances, providing a streamlined interface.
- **How to Interact**: 
  - Create a `wdc` instance by providing the URL of the database server.
  - Use the `createDBO` method to create `dbo` instances associated with the `wdc` instance.
- **Testing**: Refer to the provided test cases in the `wdcTest.py` file to ensure that the `wdc` class functions correctly.

#### Running Tests:

To test the functionality of the provided classes:
- Ensure all necessary files (`dbc.py`, `dbo.py`, `wdc.py`) are in the `src` folder.
- Execute the test script (e.g., `python dbcTest.py`) in your terminal.

## Roadmap

The following are some features or development milestones that have added, and features that should be added in the next sprints.

- [x] Initialization of DBO, DBC, and WDC.
- [x] Working main.py file
- [x] Working skeleton code
- [x] Succesful connection to server
- [x] Very basic version of library
    - [x] Ability to execute a single basic query
    - [x] Ability to execute mulitple basic queries
    - [x] Well commented and documented
- [ ] Complete Jupyter Notebook
- [ ] Ability to process image queries
- [ ] Runtime interaction with user
- [ ] Exception handling for improper query syntax

## Contact

### Sprint 1

Santiago Dominguez - sdominguezham@constructor.university

Muslim Bayemirov - mbayemirov@constructor.university

### Sprint 2

### Sprint 3
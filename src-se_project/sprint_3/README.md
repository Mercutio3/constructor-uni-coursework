# Introduction

This project is an implementation of a Python library that provides an interface to interact with a WCPS server. It implements a datacube object with some methods which generate WCPS queries, send them to the server, fetch results, and update internal state accordingly.

## !!! Changes from sprint_2 to sprint_3 !!! *** MUST READ ***

Sprint 3 contributors: Santiago Dominguez and Kais Amro

The code received from Sprint_2 had very little functionality implemented; documentation was poor and the project structure was messy. 

Given that this is only a half-sprint, and given that the provided test files were succesful with reproducible results, most of the effort in this sprint has gone to cleaning up the project and leaving it in a more readable, usable, and professional shape before the deadline. Some functionality has still been added, though. See list below.

**The following is a list of changes made to the repository for Sprint_3:**

* As per the development roadmap in the "future" section of Sprint_2's README, the min(), max(), and avg() methods have been added:

    * The min() method retrieves the minimum value along a specified axis using a WCPS query. It has an axis parameter and returns the minimum value as a string. If the axis is not valid, a ValueError is raised.

    * Similarly, the max() method fetches the maximum value from a specified axis via a WCPS query. It has an axis parameter and returns the maximum value as a string. If the axis is not valid, a ValueError is raised.

    * Finally, The avg() method computes the average value along a designated axis with a WCPS query. It has an axis parameter and returns the average value as a string. If the axis is not valid, a ValueError is raised.

* The first and second sprints completely lacked a Jupyter Notebook, so it has been written and added.

* This README file has also been drastically improved to be much more readable and comprehensive.

* A "requirements.txt" file has been added to the root directory to make library importation in the Jupyter notebook much cleaner.

* Some files, most notably the \tests directory, have been relocated.

* A WCPS_Playground.py file has been created in the root directory to actually run the "intended usage" code left by Sprint_2 in the README. For regular users, the Jupyter Notebook is the preferred way of doing it.

* The get_mean_summer_airtemp() method has been added, which calculates the mean air temperature from June through August, filters the data, and prepares it for external visualization.

* As per the Sprint_2 future roadmap, methods from the __Datacube__ class that are too specific and unfinished like the get_3d_to_1d_subset() and the def get_3d_to_2d_subset()  have been deleted.

* Fixed syntax for better understanding and view.

* Some comments have been improved for clarity.

<br>

# Project Structure and Prerequisites

## File Structure

```
\--Sprint3_Pair6\
|---------\----\--notebook\
|         |           |---datacube.ipynb
|         |----\--datacube\
|         |           |---connection.py
|         |           |---datacube.py
|         |           |---errors.py
|         |--------\--tests\
|         |             |---test_connection.py
|         |             |---test_datacube.py
|-------- .gitignore
|-------- LICENSE.md
|-------- Pipfile
|-------- Pipfile.lock
|-------- README.md
|-------- requirements.txt
|-------- WCPS_Playground.py
```

## Important files and Libraries

The [datacube](datacube) directory is where the implementation of the library resides. In it, there are these files:

- [\_\_init\_\_.py](./datacube/__init__.py): Any code that is written in here will be run upon importing the library. Because of this, it's a good idea to keep it as light as possible.

- [connection.py](./datacube/connection.py): This file contains the implementation of the __WCPSConnection__ object. The object is used to connect to the WCPS server and get the coverages from it in the form of the "datacube" object.

- [datacube.py](./datacube/datacube.py): This file contains the implementation of the __Databcube__ object. The object is used to send queries to the WCPS server about the coverage it represents.

<br>

The [tests](tests) directory is where all the tests happen. Here is a short description for all of the files:

- [\_\_int\_\_.py](./tests/__init__.py): This file contains setup code for running the tests.

- [test_connection.py](./tests/test_connection.py): Test cases for the __WCPSConnection__ object.

- [test_datacube.py](tests/test_datacube.py): Test cases for the __Datacube__ object.

<br>

## Installation Guide

    # Clone the repository.
    https://github.com/Constructor-Uni-SE-non-official/Sprint3_Pair6.git

    # cd to the root directory Sprint3_Pair6.

Follow the usage example to be able to use the functionalities of the package [jupyter_notebook][1].

[1]: https://github.com/Constructor-Uni-SE-non-official/Sprint3_Pair6/blob/main/notebook/datacube.ipynb "jupyter_notebook"


### Setting Up a Virtual Environment

This project uses pipenv to manage the enviroment.

To install all the needed modules, just run:
```
pipenv install
```

Or if this doesn't work, you can try installing pipenv with higher permissions:
```
sudo -H pip install -U pipenv 
```

To activate the environment, just run:
```
pipenv shell
```

Finally, if you wish to deactivate the virtual environment, just run:
```
deactivate
```
<br>

# Tests

All testing-related files are found in the \tests directory inside the root folder. There are two files, test_connection.py and test_datacube.py, which test the connection and datacube classes respectively.

There is a known bug in python where test files cannot read packages outside the test folder. To avoid this, the library used to make the unit tests is Pytest. To run the unit tests, simply cd to the root folder in your terminal and use this command in the root folder:

```
pytest
```
For more information on using Pytest, refer to the Pytest documentation.

<br>

# Usage

The general idea for this implementation of "wdc" is for it be used in this way:
```
from wdc.dbc import WCPSConnection
from wdc.dbo import Datacube

serverUrl = "https://ows.rasdaman.org/rasdaman/ows"
db_connection = WCPSConnection(serverUrl)

avgLandTempEndpoint = "?&SERVICE=WCS&VERSION=2.10&REQUEST=DescribeCoverage&COVERAGEID=AvgLandTemp&outputType=GeneralGridCoverage"
AvgLandTempDatacube = db_connection.get_coverage_details(avgLandTempEndpoint)

actions = [
    AvgLandTempDatacube.access("Lat", 53.08),
    AvgLandTempDatacube.access("Long", 8.80),
    AvgLandTempDatacube.access("ansi", "2014-07")
]
query = AvgLandTempDatacube.generate_query(actions)

result = db_connection.execute_query(query)
```

The query generated and executed would be this:
```
for $c in (AvgLandTemp) return ($c[Lat(53.08), Long(8.80), ansi("2014-07")])
```

And this:
```
import database_connection from wdc.dbc
import datacube from wdc.dbo

serverUrl = "https://ows.rasdaman.org/rasdaman/ows"
db_connection = database_connection(serverUrl)

avgLandTempEndpoint = "?&SERVICE=WCS&VERSION=2.10REQUEST=DescribeCoverageCOVERAGEID=AvgLandTempoutputType=GeneralGridCoverge"
AvgLandTempDatacube = db_connection.get_capability(avgLandTempEndpoint)

encodeActions = [AvgLandTempDatacube.access("Lat", 53.08), AvgLandTempDatacube.access("Long", 8.80), AvgLandTempDatacube.subset("ansi", "2014-01", "2014-12")]
actions = [AvglandTempDatacube.encode(encodeActions, "text/csv")]
query = AvgLandTempDatacube.generate_query(actions)

result = db_connection.execute_query(query)
```

Would generate and execute this query:

```
for $c in (AvgLandTemp) return (encode($c[Lat(53.08),Long(8.80),ansi("2014-01":"2014-12")],"text/csv"))
```

Demonstrations of both methods can be found in the Jupyter Notebook.

<br>

## Implemented Features

### `WCPSConnection` object:

- `__init__(self, url)`: Initializes a `WCPSConnection` object with the URL of the server.

- `get_coverage_details(self, endpoint)`: Generates a datacube object based on the coverage requested by the user and returns it.

- `execute_query(self, query)`: Given a query, it executes it and returns the result.

### `Datacube` object:

- `__init__(self, coverageName, axesNames, axesRanges)`: Initializes a datacube object based on the `coverageName`, the `axesNames` of that coverage, and the `axesRanges` of each of the axes.

- `generate_query(self, actions)`: Builds the query based on the result of `actions` given to it and returns it.

- `access(self, axis, accessValue)`: Given an `axis` and an `accessValue`, it checks whether `accessValue` is within the range of that `axis` and returns the substring `axis(accessValue)`.

- `subset(self, axis, startRange, endRange)`: Given an `axis`, `startRange`, and `endRange`, it checks whether the range `startRange:endRange` is within the range of `axis` and returns `axis(startRange:endRange)`.

- `encode(self, actions, returnType)`: Given `actions` and a `returnType`, it builds the substring for the query of the format `encode($c[actions], returnType)`.

<br>

## Future

Here is a list of that need to be worked on in the future:
- Methods such as process(), aggregate(), fuse(), and so on, can be implemented for the __Datacube__ class.

- Remove other methods that are too specific from __Datacube__ class, if any.

- A validator for the query that has been generated by __generate_query()__, if this is within the scope of the project

- More error checks for already implemented functions such as the \_\_init\_\_() method of __Datacube__ class.
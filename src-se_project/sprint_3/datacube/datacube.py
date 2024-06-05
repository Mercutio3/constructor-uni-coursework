from dateutil.parser import parse

class Datacube:
    def __init__(self, coverageName, axesNames, axesRanges):
        # Initialize Datacube object with coverage name, axis names, and ranges
        self.coverageName = coverageName
        self.axesNames = axesNames
        self.axesRanges = axesRanges
        self.axesRanges = {}

        # Iterate through axis names and ranges
        # Convert dates to datetime objects if necessary
        for axisName, axisRange in zip(axesNames, axesRanges):
            if type(axisRange[0]) == str:
                axisRange[0] = self.convert_to_iso(axisRange[0])
                axisRange[1] = self.convert_to_iso(axisRange[1])
            self.axesRanges[axisName] = (axisRange[0], axisRange[1])

    # Generate query based on actions provided
    def generate_query(self, actions):
        query = f"for $c in ({self.coverageName}) return ("
        if actions[0].startswith("encode"):
            query += actions[0]
        else:
            query += "$c["
            for index, action in enumerate(actions):
                query += action
                if index != len(actions) - 1:
                    query += ','
            query += ']'
        query += ')'
        return query

    # Encode data based on specified actions and result type
    def encode(self, actions, resultType):
        query = "encode("
        query += "$c["
        for index, action in enumerate(actions):
            query += action
            if index != len(actions) - 1:
                query += ','
        query += ']'
        query += f',"{resultType}"'
        query += ')'
        return query
        
    # Subset data based on axis name and range
    def subset(self, axisName, rangeStart, rangeEnd):
        try:
            if axisName not in self.axesRanges:
                raise KeyError(f"The coverage does not contain axis {axisName}")
            if type(rangeStart) == str:
                rangeStartISO = self.convert_to_iso(rangeStart)
                rangeEndISO = self.convert_to_iso(rangeEnd)
                if (rangeStartISO < self.axesRanges[axisName][0]) or (rangeEndISO > self.axesRanges[axisName][1]):
                    raise IndexError(f"The range {rangeStart}:{rangeEnd} is not confined within the range of axis {axisName} of the coverage")
                return f'{axisName}("{rangeStart}":"{rangeEnd}")'
            if (rangeStart < self.axesRanges[axisName][0]) or (rangeEnd > self.axesRanges[axisName][1]):
                raise IndexError(f"The range {rangeStart}:{rangeEnd} is not confined within the range of axis {axisName} of the coverage")
            return f"{axisName}({rangeStart}:{rangeEnd})"
        except (KeyError, IndexError) as error:
            raise error
    
    # Access data based on axis name and access value
    def access(self, axisName, accessValue):
        try:
            if axisName not in self.axesRanges:
                raise KeyError(f"The coverage does not contain axis {axisName}")
            if type(accessValue) == str:
                accessValueISO = self.convert_to_iso(accessValue)
                if (accessValueISO < self.axesRanges[axisName][0]) or (accessValueISO > self.axesRanges[axisName][1]):
                    raise IndexError(f"The value {accessValue} is out of range")
                return f'{axisName}("{accessValue}")'
            if(accessValue < self.axesRanges[axisName][0]) or (accessValue > self.axesRanges[axisName][1]):
                raise IndexError(f"The value {accessValue} is out of range")
            return f"{axisName}({accessValue})"
        except (KeyError, IndexError, ValueError) as error:
            raise error

    # Convert date to ISO format
    def convert_to_iso(self, date):
        try:
            parsed_date = parse(date)
            iso_date = parsed_date.strftime("%Y-%m-%dT%H:%M:%S.%fZ")
            return iso_date
        except ValueError:
            raise ValueError(f"Unable to convert {date} into ISO date format")


# Other methods for basic queries and specific queries

# Retrieve minimum value along specified axis using a WCPS query
    def min(self, axis):
        # Validate axis name
        if axis not in self.axesNames:
            raise ValueError(f"Invalid axis naming {axis} valid axes are {self.axesNames}")
        
        # Generate WCPS query 
        query = f"for $c in ({self.coverageName}) return min($c[{axis}])"
        
        # Execute the query
        result = db_connection.execute_query(query)
        return result
    
# Fetches maximum value from specified axis via a WCPS query
    def max(self, axis):
        # Validate axis name
        if axis not in self.axesNames:
            raise ValueError(f"Invalid axis name of {axis} valid axes is {self.axesNames}")

        # Generate WCPS query 
        query = f"for $c in ({self.coverageName}) return max($c[{axis}])"
        
        # Execute the query
        result = db_connection.execute_query(query)
        return result

# Computes average value along designated axis with a WCPS query
    def avg(self, axis):
        # Validate axis name
        if axis not in self.axesNames:
            raise ValueError(f"Invalid axis name of {axis} valid axes is {self.axesNames}")
        
        # Generate WCPS query 
        query = f"for $c in ({self.coverageName}) return avg($c[{axis}])"

        # Execute the query
        result = db_connection.execute_query(query)
        return result

    
    def process(self):
        ...
    def aggregate(self):
        ...
    def fuse(self):
        ...
    def scale(self):
        ...
    
    # Specific queries (left for reference, consider removing)

    def get_mean_summer_airtemp(self):
        
        # summer months
        summer_data = [entry for entry in self.data if entry['month'] in [6, 7, 8]]
        # Calculate the mean temperature
        if not summer_data:
            raise ValueError("No summer data available")
        total_temp = sum(entry['temperature'] for entry in summer_data)
        mean_temp = total_temp / len(summer_data)

        return (mean_temp, summer_data)


    def get_min_avg_land_temp(self):
        ...

    def get_single_value_avg_land_temp(self):
        ...

    def get_celsius_to_kelvin_csv(self):
        ...

    def get_max_avg_land_temp(self):
        ...

    def get_avg_land_temp(self):
        ...

    def get_temp_greater_than_15_count(self):
        ...

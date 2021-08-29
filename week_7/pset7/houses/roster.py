from cs50 import SQL
from sys import argv
import sys

# terminates the programs if the args not equals 2
if len(argv) != 2:
     sys.exit("Error")   

db = SQL("sqlite:///students.db")

# reading the required data from the students table ordered by last name and the first name
# db.execute retruns a lists of dictionaries
TableList = db.execute("SELECT DISTINCT first, middle, last, birth FROM students WHERE students.house = ? ORDER BY last, first", argv[1])

# iterates over every dictionary in the list
for dic in TableList:
    
    first = dic["first"]
    middle = dic["middle"]
    last = dic["last"]
    birth = dic["birth"]
    
    # checks if the person has a middle name or not to display the correct output without (null) value
    if middle == None:
        print(f"{first} {last}, born {birth}")
    else:
        print(f"{first} {middle} {last}, born {birth}")

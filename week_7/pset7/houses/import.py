from cs50 import SQL
import csv
import sys
from sys import argv

# terminates the programs if the args not equals
if len(argv) != 2:
     sys.exit("Error")   

db = SQL("sqlite:///students.db")

# opens the given csv file 
with open(argv[1], "r") as name:
    
    reader = csv.DictReader(name)
    
    line_count = 0
    # Iterate over csv file
    for row in reader:
        # continue if the first row in the csv file (skip the header)
        #if line_count == 0:
            #line_count += 1 
            #continue
        #else:
        # splits the name of the person 
        FullNameList = row["name"].split()

        house = row["house"]
        birth = int(row["birth"])
        
        # indicates wether the person has a middle name or not
        if len(FullNameList) == 2:
            # inserting the data in the table 
            db.execute("INSERT INTO students(first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)",
                      FullNameList[0], None, FullNameList[1], house, birth)
        elif len(FullNameList) == 3:
            # inserting the data in the table 
            db.execute("INSERT INTO students(first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)",
                      FullNameList[0], FullNameList[1], FullNameList[2], house, birth)
            
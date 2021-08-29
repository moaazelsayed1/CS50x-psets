import csv
from sys import argv
import cs50

# opens the second arg (the dna sequance) [list]
seq = open(argv[2])
list = seq.read()

 

# veriables to store the longest sequance of each STR
fixed_AGATC = 0
fixed_AATG = 0
fixed_TATC = 0

# veriables to store the current number of repeated items of each STR 
current_AGATC = 0
current_AATG = 0
current_TATC = 0

inner1 = 0
inner2 = 0
inner3 = 0
outer = 0

# iterates over the sequance list
for i in range(0 , len(list)):
    outer += 1
    
    # if codition to compute the consecutive sequance of AGATC in fixed_AGATC
    if list[i : i+5] == "AGATC":
        inner1 += 1
        current_AGATC += 1
        if current_AGATC > fixed_AGATC:
            fixed_AGATC = current_AGATC
    elif outer - inner1 == 5:
        current_AGATC = 0
    
    # if codition to compute the consecutive sequance of AATG in fixed_AATG
    if list[i : i+4] == "AATG":
        inner2 += 1
        current_AATG += 1
        if current_AATG > fixed_AATG:
            fixed_AATG = current_AATG
    elif outer - inner2 == 4 :
        current_AATG = 0
    
    # if codition to compute the consecutive sequance of TATC in fixed_TATC
    if list[i : i+4] == "TATC":
        inner3 += 1
        current_TATC += 1
        if current_TATC > fixed_TATC:
            fixed_TATC = current_TATC
    elif outer - inner3 == 4:
        current_TATC = 0
        
print(fixed_AGATC)
print(fixed_AATG)
print(fixed_TATC)
# print(list)

# compares the fixed-veriables with the database (csv file)

# opens the second arg as a CSV file
with open(argv[1]) as csv_file:
    data = csv.reader(csv_file, delimiter=',')
    line_count = 0 
    for row in data:
        if line_count == 0:
            line_count += 1
        elif fixed_AGATC == int(row[1]) and fixed_AATG == int(row[2]) and fixed_TATC == int(row[3]):
            print(row[0])
            break
        elif line_count > 2:
            print("no match")
        else:
            line_count += 1

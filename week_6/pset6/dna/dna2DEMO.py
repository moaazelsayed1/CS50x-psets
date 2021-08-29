import csv
from sys import argv


with open(argv[1], "r") as csv_file:
    data = csv.reader(csv_file, delimiter=',')
    header = next(data)
    
 

    
print(header)

count = 0
d = {} #Empty dictionary to add values into

for i in header:
    if i == "name":
        continue
    else:
        d[i] = 0
        count+=1
    
d[header[1]] += 2
print(d.get(header[1]))

dicts = {
    "AGATC" : 0,
    "TTTTTTCT" : 0,
    "AATG" : 0,
    "TCTAG" : 0,
    "GATA" : 0,
    "TATC" : 0,
    "GAAA" : 0,
    "TCTG" : 0,
}

with open(argv[1], "r") as csv_file:
        data = csv.reader(csv_file, delimiter=',')
        line_count = 0 
        for row in data:
            count = 0
            if line_count == 0:
                line_count += 1
            else:
                for STR in header:
                    if STR == "name":
                        continue
                    else:
                        count += 1
                        if dic.get(STR) ==  int(row[count]):
                            if count == len(header) - 1:
                                print(row[0])
                                return
                        else:
                            line_count += 1
                            break
        else:
            print("No match")
    
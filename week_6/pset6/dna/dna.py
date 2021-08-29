import csv
from sys import argv


def main():
    # reads the header of a csv file into a list
    with open(argv[1], "r") as csv_file:
        data = csv.reader(csv_file, delimiter=',')
        header = next(data)
    
    dic = creat_dic(header)
    
    dic = repeated_consecutively_str_count(header, dic)
     
    output = comparision(dic, header)
    print(output)

# a finction to iterate over the header[] list and create the dictionary of STRs


def creat_dic(header):
    # empty dictionary to be filled with STRs
    d = {} 
    
    for STR in header:
        if STR == "name":
            continue
        else:
            d[STR] = 0
    return d


# a function iterates over the sequance list to compute repeated consecutively strs


def repeated_consecutively_str_count(header, dic):
    
    # opens the second arg (the dna sequance) [list]
    seq = open(argv[2], "r")
    list = seq.read()

    # a loop through header[] list
    for i in header:
        
        # veriables to store the longest sequance of each STR
        fixed = 0 
        
        # veriables to store the current number of repeated items of each STR
        current = 0
         
        if i == "name":
            continue
        else:
            for x in range(0, len(list)):
                if list[x: len(i) + x] == i:
                    current += 1
                    if current > fixed:
                        fixed = current
                    if list[len(i) + x: len(i) + x + len(i)] != i:
                        current = 0
        dic[i] = fixed     
    return dic


# compares the values of repeated consecutively strs iv [dic] and the csv file


def comparision(dic, header):
    # opens arg[1] as a csv file
    with open(argv[1], "r") as csv_file:
        data = csv.reader(csv_file, delimiter=',')
        line_count = 0 
        # for every row in the csv file compare every STR value with the STR value in [dic]
        for row in data:
            # a variable like a cursur in the row so we can iterate over it
            count = 0
            
            # passes the frist line in the csv file [header]
            if line_count == 0:
                line_count += 1
            else:
                # iterates over header[] list to compare every STR with its parallel in the csv file
                for STR in header:
                    # passes the frist element in header[] ("name")
                    if STR == "name":
                        continue
                    else:
                        count += 1
                        if dic.get(STR) == int(row[count]):
                            if count == len(header) - 1:
                                return row[0]
                        # else move to the next row in the csv file
                        else:
                            line_count += 1
                            break
        else:
            return "No match"
    
    
main()

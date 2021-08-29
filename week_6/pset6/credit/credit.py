from cs50 import get_int

# some constants to get the first/second digit from the left
T = 1000000000000
F = 10000000000000
S1 = 1000000000000000
S2 = 100000000000000

# gets credit card number
while True:
    ccnumber = get_int("Number: ")
    if str(ccnumber).isdigit() == True:
        break
# saves credit card number
cc = ccnumber

# sum of odd places
sum1 = 0

# sum of even places
sum2 = 0

# the total sum
total = 0

# implements Luhn’s Algorithm
for i in range(1, len(str(ccnumber)) + 1):
    if i % 2 == 1:
        sum1 += cc % 10

    else:
        j = (cc % 10) * 2

        # sum of digits in numbers between 10:20
        if j in range(10, 20):
            sum2 += (j % 10) + int(j / 10)

        else:
            sum2 += j

    cc = int(cc / 10)

total = sum1 + sum2

# indicates credit type [VUSA, AMEX, MASTERCARD, or INVALID]
if (total % 10 == 0):
    if (len(str(ccnumber)) == 13 or len(str(ccnumber)) == 16) and (int(ccnumber / T) == 4 or int(ccnumber / S1) == 4):
        print("VISA")
    elif (len(str(ccnumber)) == 15) and (int(ccnumber / F) == 34 or int(ccnumber / F) == 37):
        print("AMEX")
    elif (len(str(ccnumber)) == 16) and (int(ccnumber / S2) == 51 or int(ccnumber / S2) == 52 or int(ccnumber / S2) == 53 or int(ccnumber / S2) == 54 or int(ccnumber / S2) == 55):
        print("MASTERCARD")
    else:
        print("INVALID")
else:
    print("INVALID")
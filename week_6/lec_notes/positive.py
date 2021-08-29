from cs50 import get_int

def main():
    i = get_positive_nom()
    print(i)
    
def get_positive_nom():
    while True:
        x = get_int("Enter a positive number: ")
        if x > 0:
             break
             
    return x
             
main()

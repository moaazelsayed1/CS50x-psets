from cs50 import get_int


def main():
    # draws the shape
    height = get_positive_integer()
    # the raws
    for i in range(0, height):
        # draws the frist indentation
        for s in range(0, (height - 1) - i):
            print(" ", end = "")
        # the first tringle
        for j in range(0, i + 1):
            print("#", end = "")
        # space between the two tringles
        for s in range(0, 2):
            print(" ", end = "")
        # the second tringle
        for j in range(0, i + 1):
            print("#", end = "")
        # makes raws
        print()

# gets an integer in range [0:8]
 
def get_positive_integer():
    while True:
        n = get_int("Height: ")
        if n > 0 and n < 9:
            break
    return n

 
main()
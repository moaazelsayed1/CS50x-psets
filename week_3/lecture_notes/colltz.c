#include <stdio.h>
#include <cs50.h>

int collatz(int m);

int main(void)
{
    int n = get_int("N: ");

    collatz(n);
    printf ("%i\n", collatz(n));

}

int collatz(int m)
{

    if (m == 1)
    {
        return 0;
    }

    if (m % 2 == 0)
    {

        return 1 +  collatz (m / 2);   //I got it! After completing the Collatz's algorithm, the collatz function
        //in the base case will eventually return 0, so we can use its return value as a counter at this point.
        //After that, the next function refers to the function that returned 0 and adds 1 to it.
        //The next function takes the value of the function that returned 1 and adds 1 to it, and so on in recursion.
        //The number returned by the last function will be the total number of functions involved in the recursion.



    }
    else
    {

       return 1 + collatz((3 * m) + 1);
    }

}
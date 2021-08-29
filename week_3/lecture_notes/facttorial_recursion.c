#include <cs50.h>
#include <stdio.h>

int fact(int num);


int main(void)
{
    int n = get_int("N: ");
    fact(n);
    printf("%i\n", fact(n));
}
int fact(int num)
{
    if (num == 1)
    {
        return 1;
    }
    else
    {
        return num * fact(num-1);
    }
}
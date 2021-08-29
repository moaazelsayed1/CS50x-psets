#include <stdio.h>
#include <cs50.h>

int feb(int m);

int main(void)
{
    int n = get_int("N: ");
    feb(n);
    printf("%i\n", feb(n));
}

int feb(int m)
{
    if (m == 1)
        return 0;
     if (m == 2)
     {
        return 1;
     }
    return feb(m - 1) + feb (m - 2);

}
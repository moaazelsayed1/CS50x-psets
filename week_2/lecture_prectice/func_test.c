#include <stdio.h>
#include <cs50.h>
#define bool _Bool

bool valid_triengle (float a, float b, float c);

int main (void)
{
   float a,b,c;
    do
    {
        a = get_float("frist side: ");
        b = get_float("second side: ");
        c= get_float("third side: ");
    }
    while (a < 1 && b < 1 && c < 1);
    valid_triengle(a, b,   c);
    printf("%d\n", valid_triengle(a, b, c));
}
bool valid_triengle (float a, float b, float c)
{
    if (a + b > c)
    {
        return true;
    }
    else 
    {
        return false;
    }
}

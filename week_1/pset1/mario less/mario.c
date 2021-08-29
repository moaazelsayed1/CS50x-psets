#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Height: "); //taking the hight from user
    }
    while (n < 1 || n > 8);
    //building the pyramid
    for (int i = 0; i < n; i++)  //rows loop
    {
        for (int k = 0; k < (n - 1) - i ; k++)   //spaces loop
        {
            printf(" ");
        }
        for (int j = 0 ; j < i + 1 ; j++) //hashes loop #
        {
            printf("#");
        }
        printf("\n");
    }
}

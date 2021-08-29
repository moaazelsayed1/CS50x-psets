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
    //building the pyramids
    for (int i = 0; i < n; i++)  //rows loop
    {
        int k;
        for (k = 0; k < (n - 1) - i ; k++)   //spaces loop
        {
            printf(" ");
        }

        for (int j = 0 ; j < i + 1 ; j++)  //left pyramid
        {
            printf("#");
        }
        for (int w = 0; w < 2; w++)   //2spaces loop
        {
            printf(" ");
        }
        for (int z = 0; z < i + 1; z++)   //right loop
        {
            printf("#");
        }

        printf("\n");
    }

}

#include <cs50.h>
#include <stdio.h>

void draw(int n);


int main(void)
{
    int hight = get_int ("hight: ");

    draw(hight);
}

void draw(int n)
{
    if (n == 0)
    {
        return;
    }
    else
    {
        draw(n-1);
    }

    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
    printf("\n");
}
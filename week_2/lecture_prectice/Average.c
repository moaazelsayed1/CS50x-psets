#include <stdio.h>
#include <cs50.h>

float Average(int length,int array[]);

int main(void )
{
    int n = get_int("Number of scores: ");
    int scores[n];
    for (int i = 0; i < n; i++)
    {
        scores[i] = get_int("score %i: ",i+1);
    }
    printf("Average = %.1f\n",Average(n, scores));
}
float Average(int length,int array[])
{
    int sum = 0;
    for (int i = 0; i < length; i++)
    {
        sum += array[i];
    }
    return (float) sum/ (float) length;

}

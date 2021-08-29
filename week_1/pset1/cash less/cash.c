#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float dollars;
    do
    {
        dollars = get_float("Change owed: ");   //change of the user
    }
    while (dollars < 0); 
    
    int cents = round(dollars * 100);
    int  coins = 0; 
    while (cents >= 25)  //counting the quarters (25¢)
    {
        cents -= 25;
        coins++;
    }
    while (cents >= 10 && cents < 25) //counting the dimes (10¢)
    {
        cents -= 10;
        coins++;
    }
    while (cents >= 5 && cents < 10)  //counting the nickels  (5¢)
    {
        cents -= 5;
        coins++;
    }
    while (cents >= 1 && cents < 5)  //counting the pennies  (1¢)
    { 
        cents -= 1 ;
        coins++;
    }
    printf("%i\n", coins); //number of coins 
}
 
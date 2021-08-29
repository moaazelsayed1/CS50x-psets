#include <stdio.h>
#include <cs50.h>
#define T 1000000000000   // number of digits including the one = number of digits of divisor
#define F 10000000000000
#define S1 1000000000000000
#define S2 100000000000000

int main(void)
{
    long ccnumber = get_long("Number: ");
    long cc = ccnumber;
    int count = 0;
    // indictes the length of the ccnumber
    while (cc != 0)
    {
        cc /= 10;
        count++;
    }
    /* printf("%i\n", count);
     printf("%ld\n", cc); */
    int sum1 = 0;
    int sum2 = 0;
    int t = 0;
    int s = 0;
    long number = ccnumber; //saving credit card number

    for (int n = 1; n <= count; n++) // doing the checksum
    {
        if (n % 2 == 1)
        {
            int i = ccnumber % 10; //taking the odds
            sum1 += i;    // sumation of odd digits (1,3,5,...)
        }
        else
        {
            int j = (ccnumber % 10) * 2;
            if (j >= 10 && j < 20) //check if the number contains of 2 digits or no
            {
                t += j % 10; //sums the last (second) digit
                s += j / 10; //sums the frist digit
            }
            else
            {
                sum2 += j;  //sums the even digits of one digit(2,4,6,8)
            }
        }
        ccnumber /= 10;  //replace the last place by the second-to-last digit
    }
    int lsum = sum1 + sum2 + s + t;

    // the card type
    if ((lsum % 10 == 0)  && (count == 13 || count == 16 || count == 15))
    {
        if ((count == 13  ||  count == 16) && (number / T == 4 || number / S1 == 4))
        {
            printf("VISA\n");
        }
        else if ((count == 15) && (number / F == 34 || number / F == 37))
        {
            printf("AMEX\n");
        }
        else if ((count == 16) && (number / S2 == 51 || number / S2 == 52 ||
                                   number / S2 == 53 || number / S2 == 54 || number / S2 == 55))
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
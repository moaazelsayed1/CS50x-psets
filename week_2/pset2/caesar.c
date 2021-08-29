#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


int main(int argc, string argv[]) // get the key through a command line
{
    if (argc == 2)
    {
        int n = strlen(argv[1]);   // determination of characters number in the second place 
        for (int i = 0; i < n; i++)  // making sure that the kay has only nombers
        {
            if (argv [1][i] < '0' || argv [1][i] > '9')
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }

        }
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    int key = atoi(argv[1]);   //converting the key to intiger so we can use it in the mathimatical formulas
    string s = get_string("plaintext: ");  //the original text
    for (int i = 0, n = strlen(s); i < n; i++)   //cypherating the original text
    {
        if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z'))
        {
            if (isupper(s[i]))
            {
                s[i] = (((s[i] - 65) + key) % 26) + 65;  //shifting ascci code and apllying the key U
            }
            else
            {
                s[i] = (((s[i] - 97) + key) % 26) + 97;  //shifting ascci code and apllying the key L
            }
        }
    }
    printf("ciphertext: %s\n", s);  
}

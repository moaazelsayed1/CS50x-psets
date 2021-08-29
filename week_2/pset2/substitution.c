#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


int main(int argc, string argv[])  // gets the alphabet index as a command line argument
{
    if (argc == 2)                 // checks if the elements of argv[] equals 2
    {
        int n = strlen(argv[1]);  //the length of argv[1] which must = 26
        if (n != 26)
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }
        //checking if the kay forms of letters only
        else
        {
            for (int i = 0; i < n; i++)
            {
                if ((argv[1][i] >= 'A' && argv[1][i] <= 'Z') || (argv[1][i] >= 'a' && argv[1][i] <= 'z'))
                {
                    // printf("true\n");
                }
                else
                {
                    printf("Key must contain 26 characters.\n");
                    return 1;
                }
            }
        }
    }
    else
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    // preventing duplicated characters in key
    int k = 0;
    int count = 0;
    for (int i = argv[1][k]; k < 26; k++)    // loop iterates over the alphabet index one by one
    {
        for (int j = k + 1 ; j <= 26 - k; j++)  // loop iterates over the alphabet index start by the second
            // place after the previous letter in the previous iteration.
        {
            if (argv [1][k] == argv[1][j])
            {
                count++;              // if count == 1 then there are duplicated characters in key
            }
        }

    }
    //printf("%i\n",count);
    if (count > 0)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    // cypher the input
    string s = get_string("plaintext: ");  // words to be encrypted
    printf("ciphertext: ");
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if ((s[i] >= 'A' && s[i] <= 'Z'))   // checks whether the plaintext is upper or lower case
        {
            //int x = s[i] - 65;
            if (isupper(argv[1][s[i] - 65]))  // if the place of s[i](which is uppercase) in argv[] contains an uppercase letter
            {
                printf("%c", argv[1][(s[i] - 65)]);  // then print argv[]
            }
            else if (islower(argv[1][s[i] - 65]))
            {
                char x = argv[1][s[i] - 65];
                printf("%c", x - 32);            // else: convert the lowercase to uppercase and print it.
            }

        }
        else if ((s[i] >= 'a' && s[i] <= 'z'))  // checks whether the plaintext is upper or lower case
        {
            if (islower(argv[1][s[i] - 97]))        // if the place of s[i](which is lowecase) in argv[] contains an lowercase letter
            {
                printf("%c", argv[1][s[i] - 97]);    // then print argv[]
            }
            else if (isupper(argv[1][s[i] - 97]))
            {
                char x = argv[1][s[i] - 97];
                printf("%c", x + 32);             // else: convert the uppercase to lowercase and print it.
            }

        }
        else
        {
            printf("%c", s[i]);  // if the plaintext contains non-letter character then print it whithout any change.
        }

    }
    printf("\n");
}

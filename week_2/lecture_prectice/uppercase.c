#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    string s = get_string("input: " );
    printf("output: ");
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (s[i] >= 'a' &&  s[i] <= 'z')
        {
            printf("%c",  toupper(s[i]));
        }
        else
        {
            printf("%c",s[i]);
        }
    }
    printf("\n");
}
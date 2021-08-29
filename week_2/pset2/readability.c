#include <stdio.h>
#include <cs50.h>
#include <string.h>

int countletters(string s);
int countwords(string x);
int countsentences(string y);

int main(void)
{
    string text = get_string("text: ");             // getting the text
    int words = countwords(text);                   // words per the whole paragraph
    int letters = countletters(text);               // letters per the whole paragraph
    int sentences = countsentences(text);           // sentences per the whole paragraph
    
    printf("%d" ,words);
    // letters per 100 words
    float L = (100 / (float)words) * (float)letters;
    // sentences per 100words
    float S = (100 / (float)words) * (float)sentences;
    // The Coleman-Liau index
    float index = (0.0588 * L) - (0.296 * S) - 15.8;
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index <= 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %.0f\n", index);
    }

}
// calculating the whole letters
int countletters(string s)
{
    int L = 0;
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z'))
        {
            L++;
        }
    }
    return L;
}
// calculating the whole words
int countwords(string x)
{
    int W = 1;
    for (int i = 0, n = strlen(x); i < n; i++)
    {
        if (x[i] == ' ')
        {
            W++;
        }
    }
    return W;
}
// calculating the whole sentences (.)(?)(!)
int countsentences(string y)
{
    int S = 0;
    for (int i = 0, n = strlen(y); i < n; i++)
    {
        if (y[i] == '.' || y[i] == '!' || y[i] == '?')
        {
            S++;
        }
    }
    return S;
}

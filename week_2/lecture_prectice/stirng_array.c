#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string names[4];
    names[0] = "EMMA";
    names[1] = "RODRIGE";
    names[2] = "BRIAN";
    names[3] = "DAVID";
    printf("%s\n", names[0]);
    printf("%c%c%c%c%i\n",names[0][0],names[0][1],names[0][2],names[0][3],names[0][4]);
}
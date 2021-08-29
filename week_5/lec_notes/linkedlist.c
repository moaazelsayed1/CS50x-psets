#include <stdio.h>

typedef struct node 
{
    int number;
    struct node* next;
}
node;

int main(void)
{
    node *list = NULL;
    node *n = malloc(sizeof(node));
    if (n != NULL)
    {
         n -> number = 2;
        n -> next = NULL;
    }
    list = n;
    node* tmp = list;
    while (tmp -> next != NULL)
    {
        tmp = temp -> next;
    }
    node *n = malloc(sizeof(node));
    if (n != NULL)
    {
         n -> number = 4;
        n -> next = NULL;
    }
    tmp -> next = n;
}
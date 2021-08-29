#include <stdio.h>

node* insert(head,x)

int main(void)
{
    insert(head,x);
}

node* insert(head,x)
{
    node* n = malloc(sizeof(node));
    if (n != NULL)
    {
        n -> number = x;
        n -> next = head;
        head = n;
    }
    return head;
}
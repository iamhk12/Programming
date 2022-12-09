#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int data;
    struct node *prev, *next;
};
struct node *head = NULL;

void insertathead(struct node *head, int value)
{
    if (head == NULL)
    {
        head->data = value;
        head->prev = NULL;
        head->next = NULL;
    }
    else
    {
        struct node *new = (struct node *)malloc(sizeof(struct node));
        new->data = value;
        head->prev = new;
        new->next = head;
        head = new;
    }
}

void printDLL(struct node *head)
{
    struct node *ptr;
    ptr = head;
    if (ptr == NULL)
        printf("\nNOTHING TO PRINT");
    else
    {
        while (ptr != NULL)
        {
            printf("\n%d", ptr->data);
            ptr = ptr->next;
        }
    }
}

int main()
{

    insertathead(head, 5);
    insertathead(head, 6);
    insertathead(head, 10);
    insertathead(head, 19);
    insertathead(head, 50);

    printDLL(head);
}
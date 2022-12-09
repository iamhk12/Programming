#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *head;

void insertbegin()
{
    int item;
    printf("Enter the value to be inserted :: ");
    scanf("%d", &item);

    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));

    ptr->data = item;
    ptr->next = head;
    head = ptr;
}

void insertend()
{
    int item;
    printf("Enter the value to be inserted :: ");
    scanf("%d", &item);

    struct node *ptr;

    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));

    ptr = head;
    while (ptr->next == NULL)
    {
        ptr = ptr->next;
    }

    ptr->next = newnode;
    newnode->data = item;
    newnode->next = NULL;
}
void deletefirst()
{
    int deleted;
    struct node *ptr;
    if (head == NULL)
        printf("\nUNDERFLOW !!!");
    else
    {

        ptr = head;
        deleted = ptr->data;
        head = head->next;
        free(ptr);
    }
    printf("%d is deleted from linked list", deleted);
}

void deletelast()
{
    struct node *ptr, *ptr1;
    ptr = head;

    if (head == NULL)
        printf("\nUNDERFLOW !!!");
    else
    {
        while (ptr->next != NULL)
        {
            ptr1 = ptr;
            ptr = ptr->next;
        }

        ptr1->next = NULL;
        free(ptr);
    }
}

void display()
{
    struct node *ptr;
    printf("\n printing values...\n");
    ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

int main()
{
    int choice;
    char yn = 'Y';
    while (yn == 'Y' || yn == 'y')
    {
        printf("\n1.INSERT element at beginning\n2.INSERT element at last\n3.DELETE element from first \n4.DELETE element from last\n5.Display linked list\n\nEnter your choice::");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1: // insertbegin
            insertbegin();
            break;
        case 2: // insertend
            insertend();
            break;
        case 3:
            deletefirst();
            break;
        case 4:
            deletelast();
            break;
        case 5: // display
            display();
            break;
        default:
            printf("\nINVALID INPUT");
            break;
        }
        printf("\nPRESS Y TO CONTINUE");
        scanf("%c",&yn);
    }
}

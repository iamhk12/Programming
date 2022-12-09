#include <stdio.h>
#include <conio.h>
#define MAX 5
int STACK[5];
int top = -1, data;

void push()
{
    if (top == MAX - 1)
        printf("stack is full");
    else
    {
        printf("Enter element to be pushed:\n");
        scanf("%d", &data);
        top = top + 1;
        STACK[top] = data;
    }
}

void pop()
{
    int popped_item;
    if (top == -1)
    {
        printf("stack is empty");
    }
    else
    {
        popped_item = STACK[top];
        top = top - 1;
        printf("%d popped ",popped_item);
    }
}

void display()
{
    int i;
    if (top == -1)
        printf("\n stack is empty");
    else
    {
        printf("\nDisplaying stack elements:");
        for (i = top; i >= 0; i--)
        {
            printf("\n%d", STACK[i]);
        }
    }
}

void main()
{
    int choice, a;
    char loop = 'Y';
    while ((loop == 'Y') || (loop == 'y'))
    {
        printf("1.push\n 2.pop\n 3.display\n 4.exit\n");
        printf("Enter choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        default:
            printf("exit");
            break;
        } // end of switch
        printf("\nEnter Y to continue and any other key to exit:\n");
        loop = getch();
    } // end of while
    getch();
}
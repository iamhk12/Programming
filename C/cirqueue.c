#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10
int queue[MAX];
int front = -1;
int rear = -1;

void enqueue(int x)
{
    if (front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
        queue[rear] = x;
    }
    else if ((rear + 1) % MAX == front)
    {
        printf("\nStack overflow condition");
    }
    else
    {
        rear = (rear + 1) % MAX;
        queue[rear] = x;
    }
}

int dequeue()
{
    int ans;
    if (front == -1 && rear == -1)
    {
        printf("\n Stack underflow condition");
        return -1;
    }
    else if (front == rear)
    {
        ans = queue[front];
        front = -1;
        rear = -1;
        return ans;
    }
    else
    {
        ans = queue[front];
        front = (front + 1) % MAX;
        return ans;
    }
}

void display()
{
    if (rear == -1 && front == -1)
        printf("\nNothing to print in queue");
    else
    {
        int i;
        for (i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main()
{
    bool start = true;
    int x, n;

    while (true)
    {
        printf("\nOperation to be performed: \n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n\n Enter your choice:: ");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            printf("\nEnter the value to be insered in the queue :: ");
            scanf("%d", &x);
            enqueue(x);
            break;
        case 2:
            printf("\nThe value deleted from queue is :: %d", dequeue());
            break;
        case 3:
            printf("\nDisplaying Queue:: \n");
            display();
            break;
        case 4:
            exit(1);
        default:
            printf("\nInvalid I/P !!!");
            exit(1);
        }
    }
    return 0;
}

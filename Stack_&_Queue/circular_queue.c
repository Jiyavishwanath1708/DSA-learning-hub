// Program: Circular Queue Implementation using Array

#include <stdio.h>
#include <stdlib.h>

// Global variables
int queue[50];
int front = -1;
int rear = -1;
int max;

// Function declarations
void enqueue();
void dequeue();
void peek();
void display();

// Enqueue operation
void enqueue()
{
    int item;

    printf("Enter data: ");
    scanf("%d", &item);

    if ((rear + 1) % max == front)
    {
        printf("Queue Overflow\n");
    }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = item;
    }
    else
    {
        rear = (rear + 1) % max;
        queue[rear] = item;
    }
}

// Dequeue operation
void dequeue()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue Underflow\n");
    }
    else if (front == rear)
    {
        printf("Deleted Element: %d\n", queue[front]);
        front = rear = -1;
    }
    else
    {
        printf("Deleted Element: %d\n", queue[front]);
        front = (front + 1) % max;
    }
}

// Peek operation
void peek()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        printf("Front Element: %d\n", queue[front]);
    }
}

// Display queue
void display()
{
    int i = front;

    if (front == -1 && rear == -1)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        while (i != rear)
        {
            printf("[%d] ", queue[i]);
            i = (i + 1) % max;
        }
        printf("[%d]\n", queue[rear]);
    }
}

// Main function
int main()
{
    int choice;

    printf("Enter maximum size of queue: ");
    scanf("%d", &max);

    while (1)
    {
        printf("\n----- Main Menu -----\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                enqueue();
                break;

            case 2:
                dequeue();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid Choice\n");
        }
    }

    return 0;
}
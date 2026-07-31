// Program: Stack Implementation using Array

#include <stdio.h>
#include <stdlib.h>

// Global variables
int top = -1;
int maxstk, stack[20];

// Function declarations
void push();
void pop();
void peek();
void display();
void reverse();

// Push operation
void push()
{
    int item;

    if (top == maxstk - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        printf("Enter item: ");
        scanf("%d", &item);

        top++;
        stack[top] = item;
    }
}

// Pop operation
void pop()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        printf("Deleted Element: %d\n", stack[top]);
        top--;
    }
}

// Peek operation
void peek()
{
    if (top == -1)
    {
        printf("Stack is Empty\n");
    }
    else
    {
        printf("Top Element: %d\n", stack[top]);
    }
}

// Display stack from bottom to top
void reverse()
{
    int i;

    if (top == -1)
    {
        printf("Stack is Empty\n");
    }
    else
    {
        for (i = 0; i <= top; i++)
        {
            printf("Element: %d\n", stack[i]);
        }
    }
}

// Display stack from top to bottom
void display()
{
    int i;

    if (top == -1)
    {
        printf("Stack is Empty\n");
    }
    else
    {
        for (i = top; i >= 0; i--)
        {
            printf("Element: %d\n", stack[i]);
        }
    }
}

// Main function
int main()
{
    int choice;

    printf("Enter maximum number of elements: ");
    scanf("%d", &maxstk);

    while (1)
    {
        printf("\n----- Main Menu -----\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Reverse Display\n");
        printf("5. Display\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
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
                peek();
                break;

            case 4:
                reverse();
                break;

            case 5:
                display();
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid Choice\n");
        }
    }

    return 0;
}
// Program: Doubly Linked List Creation

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL, *temp;

// Create Doubly Linked List
void create()
{
    int choice = 1;

    while (choice)
    {
        struct node *newnode = (struct node *)malloc(sizeof(struct node));

        printf("Enter data: ");
        scanf("%d", &newnode->data);

        newnode->next = NULL;
        newnode->prev = NULL;

        if (head == NULL)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
        }

        printf("Do you want to continue (1/0): ");
        scanf("%d", &choice);
    }
}

// Display Doubly Linked List
void display()
{
    temp = head;

    if (head == NULL)
    {
        printf("\nList is empty.\n");
        return;
    }

    printf("\nDoubly Linked List:\n");

    while (temp != NULL)
    {
        printf("|%d| <-> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

// Main function
int main()
{
    create();
    display();

    return 0;
}
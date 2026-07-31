// Program: Linked List Creation

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL, *newnode, *temp;

// Create Linked List
void create()
{
    int choice = 1;

    while (choice)
    {
        newnode = (struct node *)malloc(sizeof(struct node));

        printf("Enter data: ");
        scanf("%d", &newnode->data);

        newnode->next = NULL;

        if (head == NULL)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }

        printf("Do you want to continue? (1/0): ");
        scanf("%d", &choice);
    }
}

// Display Linked List
void display()
{
    temp = head;

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    printf("\nLinked List:\n");

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
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
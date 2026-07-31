// Program: Circular Linked List Creation

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL, *newnode, *temp;

// Create circular linked list
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
            temp->next = head;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
            temp->next = head;
        }

        printf("Do you want to continue (1/0): ");
        scanf("%d", &choice);
    }
}

// Display circular linked list
void display()
{
    if (head == NULL)
    {
        printf("List is Empty\n");
        return;
    }

    temp = head;

    printf("\nCircular Linked List:\n");

    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("(HEAD)\n");
}

// Main function
int main()
{
    create();
    display();

    return 0;
}
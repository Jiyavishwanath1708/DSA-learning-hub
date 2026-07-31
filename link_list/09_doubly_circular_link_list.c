// Program: Circular Doubly Linked List

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL, *newnode, *temp;

// Insert at beginning
void insert_begin()
{
    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    if (head == NULL)
    {
        head = newnode;
        newnode->next = head;
        newnode->prev = head;
    }
    else
    {
        temp = head;

        while (temp->next != head)
        {
            temp = temp->next;
        }

        newnode->next = head;
        newnode->prev = temp;
        temp->next = newnode;
        head->prev = newnode;
        head = newnode;
    }

    printf("Node inserted at beginning.\n");
}

// Insert at end
void insert_end()
{
    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    if (head == NULL)
    {
        head = newnode;
        newnode->next = head;
        newnode->prev = head;
    }
    else
    {
        temp = head;

        while (temp->next != head)
        {
            temp = temp->next;
        }

        temp->next = newnode;
        newnode->prev = temp;
        newnode->next = head;
        head->prev = newnode;
    }

    printf("Node inserted at end.\n");
}

// Delete from beginning
void delete_begin()
{
    struct node *last;

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    if (head->next == head)
    {
        free(head);
        head = NULL;
    }
    else
    {
        last = head->prev;
        temp = head;

        head = head->next;
        head->prev = last;
        last->next = head;

        free(temp);
    }

    printf("Node deleted from beginning.\n");
}

// Delete from end
void delete_end()
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    if (head->next == head)
    {
        free(head);
        head = NULL;
    }
    else
    {
        temp = head->prev;

        temp->prev->next = head;
        head->prev = temp->prev;

        free(temp);
    }

    printf("Node deleted from end.\n");
}

// Display
void display()
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    temp = head;

    printf("\nCircular Doubly Linked List:\n");

    do
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("(HEAD)\n");
}

// Main function
int main()
{
    int choice;

    while (1)
    {
        printf("\n----- Circular Doubly Linked List -----\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete from Beginning\n");
        printf("4. Delete from End\n");
        printf("5. Display\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                insert_begin();
                break;

            case 2:
                insert_end();
                break;

            case 3:
                delete_begin();
                break;

            case 4:
                delete_end();
                break;

            case 5:
                display();
                break;

            case 6:
                return 0;

            default:
                printf("Invalid Choice\n");
        }
    }

    return 0;
}
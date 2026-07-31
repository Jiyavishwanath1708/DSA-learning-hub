// Program: Circular Singly Linked List Operations

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL, *newnode, *temp;

// Insert at beginning
void in_beg()
{
    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    if (head == NULL)
    {
        head = newnode;
        newnode->next = head;
    }
    else
    {
        temp = head;

        while (temp->next != head)
        {
            temp = temp->next;
        }

        newnode->next = head;
        temp->next = newnode;
        head = newnode;
    }

    printf("Node inserted at beginning.\n");
}

// Insert at end
void in_end()
{
    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    if (head == NULL)
    {
        head = newnode;
        newnode->next = head;
    }
    else
    {
        temp = head;

        while (temp->next != head)
        {
            temp = temp->next;
        }

        temp->next = newnode;
        newnode->next = head;
    }

    printf("Node inserted at end.\n");
}

// Delete from beginning
void del_beg()
{
    struct node *last;

    if (head == NULL)
    {
        printf("List is empty.\n");
    }
    else if (head->next == head)
    {
        free(head);
        head = NULL;
    }
    else
    {
        temp = head;
        last = head;

        while (last->next != head)
        {
            last = last->next;
        }

        head = head->next;
        last->next = head;

        free(temp);
    }

    printf("Node deleted from beginning.\n");
}

// Delete from end
void del_end()
{
    struct node *prev;

    if (head == NULL)
    {
        printf("List is empty.\n");
    }
    else if (head->next == head)
    {
        free(head);
        head = NULL;
    }
    else
    {
        temp = head;

        while (temp->next != head)
        {
            prev = temp;
            temp = temp->next;
        }

        prev->next = head;
        free(temp);
    }

    printf("Node deleted from end.\n");
}

// Display list
void display()
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    temp = head;

    printf("Circular Linked List:\n");

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
    int choice;

    while (1)
    {
        printf("\n----- Circular Singly Linked List -----\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete from Beginning\n");
        printf("4. Delete from End\n");
        printf("5. Display\n");
        printf("6. Exit\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                in_beg();
                break;

            case 2:
                in_end();
                break;

            case 3:
                del_beg();
                break;

            case 4:
                del_end();
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
// Program: Doubly Linked List Operations

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL, *newnode;

// Insert at beginning
void begininsert()
{
    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->prev = NULL;

    if (head == NULL)
    {
        newnode->next = NULL;
        head = newnode;
    }
    else
    {
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }

    printf("Node inserted at beginning.\n");
}

// Insert at end
void lastinsert()
{
    struct node *temp = head;

    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->next = NULL;

    if (head == NULL)
    {
        newnode->prev = NULL;
        head = newnode;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        newnode->prev = temp;
        temp->next = newnode;
    }

    printf("Node inserted at end.\n");
}

// Insert at position
void insert()
{
    struct node *temp = head;
    int pos, i = 1;

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    printf("Enter position: ");
    scanf("%d", &pos);

    if (pos == 1)
    {
        begininsert();
        return;
    }

    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    while (i < pos - 1 && temp->next != NULL)
    {
        temp = temp->next;
        i++;
    }

    newnode->next = temp->next;
    newnode->prev = temp;

    if (temp->next != NULL)
    {
        temp->next->prev = newnode;
    }

    temp->next = newnode;

    printf("Node inserted successfully.\n");
}

// Delete from beginning
void begin_delete()
{
    struct node *temp = head;

    if (head == NULL)
    {
        printf("List is empty.\n");
    }
    else if (head->next == NULL)
    {
        free(head);
        head = NULL;
    }
    else
    {
        head = head->next;
        head->prev = NULL;
        free(temp);
    }

    printf("Node deleted from beginning.\n");
}

// Delete from end
void last_delete()
{
    struct node *temp = head;

    if (head == NULL)
    {
        printf("List is empty.\n");
    }
    else if (head->next == NULL)
    {
        free(head);
        head = NULL;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->prev->next = NULL;
        free(temp);
    }

    printf("Node deleted from end.\n");
}

// Delete from position
void random_delete()
{
    struct node *temp = head;
    int pos, i = 1;

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    printf("Enter position: ");
    scanf("%d", &pos);

    if (pos == 1)
    {
        begin_delete();
        return;
    }

    while (i < pos && temp != NULL)
    {
        temp = temp->next;
        i++;
    }

    if (temp == NULL)
    {
        printf("Invalid position.\n");
        return;
    }

    if (temp->next == NULL)
    {
        temp->prev->next = NULL;
    }
    else
    {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }

    free(temp);

    printf("Node deleted successfully.\n");
}

// Display list
void display()
{
    struct node *temp = head;

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    printf("\nDoubly Linked List:\n");

    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

// Main function
int main()
{
    int choice;

    do
    {
        printf("\n----- Doubly Linked List -----\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete from Position\n");
        printf("7. Display\n");
        printf("8. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                begininsert();
                break;

            case 2:
                lastinsert();
                break;

            case 3:
                insert();
                break;

            case 4:
                begin_delete();
                break;

            case 5:
                last_delete();
                break;

            case 6:
                random_delete();
                break;

            case 7:
                display();
                break;

            case 8:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid Choice\n");
        }

    } while (choice != 8);

    return 0;
}
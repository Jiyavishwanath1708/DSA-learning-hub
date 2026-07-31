// Program: Singly Linked List Operations

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

    newnode->next = head;
    head = newnode;

    printf("Node inserted at beginning.\n");
}

// Insert at end
void in_end()
{
    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->next = NULL;

    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }

    printf("Node inserted at end.\n");
}

// Insert at position
void in_pos()
{
    int pos, i;

    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    printf("Enter position: ");
    scanf("%d", &pos);

    if (pos == 1)
    {
        newnode->next = head;
        head = newnode;
        return;
    }

    temp = head;

    for (i = 1; i < pos - 1; i++)
    {
        if (temp == NULL)
        {
            printf("Invalid position.\n");
            free(newnode);
            return;
        }
        temp = temp->next;
    }

    newnode->next = temp->next;
    temp->next = newnode;

    printf("Node inserted successfully.\n");
}

// Delete from beginning
void del_beg()
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    temp = head;
    head = head->next;
    free(temp);

    printf("Node deleted from beginning.\n");
}

// Delete from end
void del_end()
{
    struct node *prev;

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    if (head->next == NULL)
    {
        free(head);
        head = NULL;
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            prev = temp;
            temp = temp->next;
        }

        prev->next = NULL;
        free(temp);
    }

    printf("Node deleted from end.\n");
}

// Delete from position
void del_pos()
{
    struct node *nextnode;
    int pos, i;

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    printf("Enter position: ");
    scanf("%d", &pos);

    if (pos == 1)
    {
        temp = head;
        head = head->next;
        free(temp);
        return;
    }

    temp = head;

    for (i = 1; i < pos - 1; i++)
    {
        temp = temp->next;
    }

    nextnode = temp->next;
    temp->next = nextnode->next;
    free(nextnode);

    printf("Node deleted successfully.\n");
}

// Search element
void search()
{
    int key, pos = 1, found = 0;

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    temp = head;

    while (temp != NULL)
    {
        if (temp->data == key)
        {
            printf("Element found at position %d\n", pos);
            found = 1;
            break;
        }

        temp = temp->next;
        pos++;
    }

    if (!found)
    {
        printf("Element not found.\n");
    }
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

    printf("Linked List:\n");

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
    int choice;

    while (1)
    {
        printf("\n----- Singly Linked List -----\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete from Position\n");
        printf("7. Search\n");
        printf("8. Display\n");
        printf("9. Exit\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1: in_beg(); break;
            case 2: in_end(); break;
            case 3: in_pos(); break;
            case 4: del_beg(); break;
            case 5: del_end(); break;
            case 6: del_pos(); break;
            case 7: search(); break;
            case 8: display(); break;
            case 9: return 0;
            default: printf("Invalid Choice\n");
        }
    }
}
#include <stdio.h>
#include <stdlib.h>

// Structure of a node
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root = NULL;
struct node *temp;

// Function declarations
struct node *createNode(int data);
void insert(int data);
struct node *deleteNode(struct node *root, int key);
struct node *smallestNode(struct node *root);
struct node *largestNode(struct node *root);
void inorder(struct node *root);
void preorder(struct node *root);
void postorder(struct node *root);
int getData();

int main()
{
    int choice, data;
    struct node *result = NULL;

    while (1)
    {
        printf("\n------ Binary Search Tree ------\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Largest Node\n");
        printf("4. Smallest Node\n");
        printf("5. Inorder Traversal\n");
        printf("6. Postorder Traversal\n");
        printf("7. Preorder Traversal\n");
        printf("8. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                data = getData();
                insert(data);
                break;

            case 2:
                data = getData();
                root = deleteNode(root, data);
                break;

            case 3:
                result = largestNode(root);

                if (result != NULL)
                    printf("Largest Node = %d\n", result->data);
                else
                    printf("Tree is empty.\n");

                break;

            case 4:
                result = smallestNode(root);

                if (result != NULL)
                    printf("Smallest Node = %d\n", result->data);
                else
                    printf("Tree is empty.\n");

                break;

            case 5:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;

            case 6:
                printf("Postorder Traversal: ");
                postorder(root);
                printf("\n");
                break;

            case 7:
                printf("Preorder Traversal: ");
                preorder(root);
                printf("\n");
                break;

            case 8:
                printf("Program Ended.\n");
                return 0;

            default:
                printf("Invalid Choice.\n");
        }
    }
}

// Create a new node
struct node *createNode(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Insert a node
void insert(int data)
{
    struct node *newNode = createNode(data);
    struct node *temp = root;
    struct node *prev = NULL;

    if (root == NULL)
    {
        root = newNode;
        printf("Node inserted successfully.\n");
        return;
    }

    while (temp != NULL)
    {
        prev = temp;

        if (data > temp->data)
            temp = temp->right;
        else
            temp = temp->left;
    }

    if (data > prev->data)
        prev->right = newNode;
    else
        prev->left = newNode;

    printf("Node inserted successfully.\n");
}

// Delete a node
struct node *deleteNode(struct node *root, int key)
{
    if (root == NULL)
        return root;

    if (key < root->data)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        if (root->left == NULL)
        {
            temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            temp = root->left;
            free(root);
            return temp;
        }

        temp = largestNode(root->left);
        root->data = temp->data;
        root->left = deleteNode(root->left, temp->data);
    }

    return root;
}

// Find the smallest node
struct node *smallestNode(struct node *root)
{
    struct node *current = root;

    while (current != NULL && current->left != NULL)
        current = current->left;

    return current;
}

// Find the largest node
struct node *largestNode(struct node *root)
{
    struct node *current = root;

    while (current != NULL && current->right != NULL)
        current = current->right;

    return current;
}

// Inorder Traversal
void inorder(struct node *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Preorder Traversal
void preorder(struct node *root)
{
    if (root == NULL)
        return;

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// Postorder Traversal
void postorder(struct node *root)
{
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

// Read data from the user
int getData()
{
    int data;

    printf("Enter Data: ");
    scanf("%d", &data);

    return data;
}
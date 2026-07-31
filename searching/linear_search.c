#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[20], i, n, key;

    // Read the number of elements
    printf("How many elements do you want to enter? ");
    scanf("%d", &n);

    // Read array elements
    printf("Enter the elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    // Read the element to search
    printf("Enter the element to search: ");
    scanf("%d", &key);

    // Search for the element
    for (i = 0; i < n; i++)
    {
        if (a[i] == key)
        {
            printf("Element found at position %d.\n", i + 1);
            return 0;
        }
    }

    // Display if the element is not found
    printf("Element not found.\n");

    return 0;
}
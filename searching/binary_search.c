#include <stdio.h>

int main()
{
    int a[20], i, n, start, end, mid, key;

    // Read the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Read array elements
    printf("Enter the elements in ascending order:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    // Check whether the array is sorted
    for (i = 0; i < n - 1; i++)
    {
        if (a[i] > a[i + 1])
        {
            printf("Please enter the elements in ascending order.\n");
            return 0;
        }
    }

    // Read the element to search
    printf("Enter the element to search: ");
    scanf("%d", &key);

    start = 0;
    end = n - 1;

    // Perform binary search
    while (start <= end)
    {
        mid = (start + end) / 2;

        if (a[mid] == key)
        {
            printf("Element found at position %d.\n", mid + 1);
            return 0;
        }
        else if (a[mid] < key)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    // Display if the element is not found
    printf("Element not found.\n");

    return 0;
}
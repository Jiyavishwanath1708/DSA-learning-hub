// Program: Dynamic Memory Reallocation using realloc()

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, n1, i, *ptr;

    printf("Enter total number of values: ");
    scanf("%d", &n);

    ptr = (int *)calloc(n, sizeof(int));

    if (ptr == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter values:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &ptr[i]);
    }

    printf("Current values:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", ptr[i]);
    }

    printf("\nEnter updated size: ");
    scanf("%d", &n1);

    ptr = (int *)realloc(ptr, n1 * sizeof(int));

    if (ptr == NULL)
    {
        printf("Memory reallocation failed.\n");
        return 1;
    }

    if (n1 > n)
    {
        printf("Enter additional values:\n");
        for (i = n; i < n1; i++)
        {
            scanf("%d", &ptr[i]);
        }
    }

    printf("Updated values:\n");
    for (i = 0; i < n1; i++)
    {
        printf("%d ", ptr[i]);
    }

    free(ptr);

    return 0;
}
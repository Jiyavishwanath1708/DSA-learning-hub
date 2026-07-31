// Program: Dynamic Memory Allocation using malloc()

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, *ptr;

    printf("Enter total number of values: ");
    scanf("%d", &n);

    ptr = (int *)malloc(n * sizeof(int));

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

    printf("Entered values are:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", ptr[i]);
    }

    free(ptr);

    return 0;
}
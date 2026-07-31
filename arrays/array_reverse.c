// Write a C program to reverse an array using pointers.

#include <stdio.h>

int main()
{
    int a[100], n, i, *p;

    printf("How many elements do you want to enter? ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    p = a + n - 1;

    printf("\nReversed array:\n");
    for(i = 0; i < n; i++)
    {
        printf("%d ", *(p - i));
    }

    printf("\n");

    return 0;
}
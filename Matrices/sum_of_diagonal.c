// Write a C program to find the sum of the diagonal elements of a 2D array

#include <stdio.h>

int main()
{
    int a[10][10];
    int n, i, j, sum = 0;

    printf("Enter total number of rows: ");
    scanf("%d", &n);

    printf("Enter elements of the matrix:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    printf("\n***** Diagonal Elements *****\n");
    for(i = 0; i < n; i++)
    {
        printf("%d ", a[i][i]);
        sum += a[i][i];
    }

    printf("\n\nDiagonal Sum = %d\n", sum);

    return 0;
}
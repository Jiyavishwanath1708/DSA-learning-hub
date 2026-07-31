#include <stdio.h>

int main()
{
    int a[10][10], rows, columns, i, j, sum = 0;

    // Read the number of rows and columns
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &columns);

    // Read matrix elements
    printf("Enter the matrix elements:\n");
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < columns; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    // Display the matrix
    printf("\nMatrix:\n");
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < columns; j++)
        {
            printf("%d ", a[i][j]);
            sum += a[i][j];
        }
        printf("\n");
    }

    // Display the sum of all elements
    printf("\nSum of all elements = %d\n", sum);

    return 0;
}
// Write a C program for Sparse Matrix Representation

#include <stdio.h>

int main()
{
    int matrix[10][10];
    int i, j, r, c;

    printf("Enter total number of rows and columns: ");
    scanf("%d%d", &r, &c);

    printf("\nEnter matrix elements:\n");
    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("\nSparse Matrix Representation (ROW COL VALUE):\n");

    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            if(matrix[i][j] != 0)
            {
                printf("%d %d %d\n", i, j, matrix[i][j]);
            }
        }
    }

    return 0;
}
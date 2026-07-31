#include <stdio.h>

int main()
{
    int pos, max, val, i, choice, n, a[10], x;

    printf("How many elements do you want to enter? ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    do
    {
        printf("\n******** MENU ********\n");
        printf("1. Insert\n");
        printf("2. Remove\n");
        printf("3. Search\n");
        printf("4. Display\n");
        printf("5. Maximum Value\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &x);

                printf("Enter position (1 to %d): ", n + 1);
                scanf("%d", &pos);

                if(pos < 1 || pos > n + 1)
                {
                    printf("Invalid Position\n");
                    break;
                }

                for(i = n - 1; i >= pos - 1; i--)
                {
                    a[i + 1] = a[i];
                }

                a[pos - 1] = x;
                n++;

                printf("Element inserted successfully.\n");
                break;

            case 2:
                printf("Enter position to delete: ");
                scanf("%d", &pos);

                if(pos < 1 || pos > n)
                {
                    printf("Invalid Position\n");
                    break;
                }

                for(i = pos - 1; i < n - 1; i++)
                {
                    a[i] = a[i + 1];
                }

                n--;

                printf("Element deleted successfully.\n");
                break;

            case 3:
                printf("Enter value to search: ");
                scanf("%d", &val);

                for(i = 0; i < n; i++)
                {
                    if(a[i] == val)
                    {
                        printf("Element found at position %d\n", i + 1);
                        break;
                    }
                }

                if(i == n)
                {
                    printf("Element not found.\n");
                }
                break;

            case 4:
                printf("Array Elements:\n");

                for(i = 0; i < n; i++)
                {
                    printf("%d ", a[i]);
                }

                printf("\n");
                break;

            case 5:
                max = a[0];

                for(i = 1; i < n; i++)
                {
                    if(a[i] > max)
                    {
                        max = a[i];
                    }
                }

                printf("Maximum Value = %d\n", max);
                break;

            case 6:
                printf("Program Ended.\n");
                break;

            default:
                printf("Invalid Choice\n");
        }

    } while(choice != 6);

    return 0;
}
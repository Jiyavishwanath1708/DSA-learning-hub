#include <stdio.h>

int arr[50];
int i, j, k, n;

void mergeSort(int low, int high);
void merge(int low, int mid, int high);

int main()
{
    // Read the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Read array elements
    printf("Enter the elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Sort the array using Merge Sort
    mergeSort(0, n - 1);

    // Display the sorted array
    printf("Sorted Array:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}

void mergeSort(int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;

        mergeSort(low, mid);
        mergeSort(mid + 1, high);
        merge(low, mid, high);
    }
}

void merge(int low, int mid, int high)
{
    int temp[50];

    i = low;
    j = mid + 1;
    k = low;

    // Merge the two sorted subarrays
    while (i <= mid && j <= high)
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
        }
    }

    // Copy remaining elements from the left subarray
    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }

    // Copy remaining elements from the right subarray
    while (j <= high)
    {
        temp[k++] = arr[j++];
    }

    // Copy the merged elements back to the original array
    for (i = low; i <= high; i++)
    {
        arr[i] = temp[i];
    }
}
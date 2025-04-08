#include <stdio.h>
#include <conio.h>

void insertionSort(int arr[], int n)
{
    int least, p, i, j, k, temp, pass = 1, key;
    for (i = 0; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        printf("\nPass %d: \n", pass++);
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
        for (k = 0; k < n; k++)
        {
            printf("%d, ", arr[k]);
        }
        printf("\n");
        printf("inserted value: %d change it's position\n", key);
    }
}

int main()
{
    int n, i;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the array data:\n"); // Taking input from user
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    insertionSort(arr, n);    // Calling insertion sort on array arr
    printf("Sorted array: "); // Printing the final result
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}
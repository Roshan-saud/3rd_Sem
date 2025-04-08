#include <stdio.h>
#include <conio.h>

void selectionSort(int arr[], int n)
{
    int least, p, i, j, k, temp, pass = 1;
    for (i = 0; i < n - 1; i++)
    {
        least = arr[i];
        p = i;
        printf("\nPass %d: \n", pass++);
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[p])
            {
                least = arr[j];
                p = j;
            }
            printf("Least: %d\n", least);
            for (k = 0; k < n; k++)
            {
                printf("%d ", arr[k]);
            }
            printf("\n");
        }
        temp = arr[i];
        arr[i] = arr[p];
        arr[p] = temp;
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
    selectionSort(arr, n);    // Calling Selection sort on array arr
    printf("Sorted array: "); // Printing the final result
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}
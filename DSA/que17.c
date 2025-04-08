
#include <stdio.h>
#include <conio.h>

void bubbleSort(int arr[], int n)
{
    int pass = 1;
    for (int i = 0; i < n - 1; i++)
    {
        printf("\nPass %d: \n", pass++);
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            { // To swap the value
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }

            for (int k = 0; k < n; k++)
            { // To print each pass data of array
                printf("%d, ", arr[k]);
            }
            printf("\n");
        }
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
    bubbleSort(arr, n);       // Calling bubble sort on array arr
    printf("Sorted array: "); // Printing the final result
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
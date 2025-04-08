// Write aprogram to search the user input key in the list using Binary search

#include <stdio.h>
void binarySearch(int arr[], int n, int key)
{
    int low = 0, high = n - 1, mid, flag = 0;
    while (low <= high)
    {
        mid = (low + high) / 2;

        if (arr[mid] == key)
        {
            printf("Element found at index %d\n", mid);
            flag = 1;
            break;
        }
        else if (arr[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    if (!flag)
    {
        printf("Element not found in the array.\n");
    }
}
int main()
{
    int n, i, key;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the array data in sorted order (ascending or descending):\n"); // Taking input from user
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to search: ");
    scanf("%d", &key);

    binarySearch(arr, n, key); // Calling Binary Search function
    return 0;
}
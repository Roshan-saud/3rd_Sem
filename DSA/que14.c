// Write aprogram to search the user input key in the list using Linear search
#include <stdio.h>

void linearSearch(int arr[], int n, int key)
{
    int i, flag = 0;
    for (i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            printf("Element found at index %d\n", i);
            flag = 1;
            break;
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

    linearSearch(arr, n, key); // Calling Linear Search function
    return 0;
}

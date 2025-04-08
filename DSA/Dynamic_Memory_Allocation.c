
// Malloc
// #include <stdio.h>
// #include <stdlib.h>
// int main()
// {
//     int n, i, sum = 0;
//     printf("Enter the value for n: ");
//     scanf("%d", &n);
//     int *ptr;
//     ptr = (int *)malloc(n * sizeof(int));
//     printf("Before initilizing \n");
//     for (i = 0; i < n; i++)
//     {
//         printf("%d", *(ptr + i));
//         printf("\n");
//     }
//     printf("\nAfter initilizing \n");
//     printf("Enter %d values: \n", n);
//     for (i = 0; i < n; i++)
//     {
//         scanf("%d", ptr + i);
//         sum = sum + *(ptr + i);
//     }
//     printf("Sum is %d", sum);
//     free(ptr);
//     return 0;
// }

// calloc
// #include <stdio.h>
// #include <stdlib.h>
// int main()
// {
//     int n, i, sum = 0;

//     printf("Enter the value for n: ");
//     scanf("%d", &n);

//     int *ptr;
//     ptr = (int *)calloc(n, 5 * sizeof(int));

//     printf("Before initilizing \n");
//     for (i = 0; i < n; i++)
//     {
//         printf("%d", *(ptr + i));
//         printf("\n");
//     }

//     printf("\nAfter initilizing \n");
//     printf("Enter %d values: \n", n);
//     for (i = 0; i < n; i++)
//     {
//         scanf("%d", ptr + i);
//         sum = sum + *(ptr + i);
//     }
//     printf("sum=%d", sum);
//     free(ptr);
//     return 0;
// }

// Reallocation
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, n1, i, sum = 0;
    printf("Enter the value for n: ");
    scanf("%d", &n);
    int *ptr;
    ptr = (int *)malloc(n * sizeof(int));
    printf("Before initilizing \n");
    for (i = 0; i < n; i++)
    {
        printf("%d", *(ptr + i));
        printf("\n");
    }
    printf("\nAfter initilizing \n");
    printf("Enter %d values: \n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", ptr + i);
        sum = sum + *(ptr + i);
    }
    printf("Sum is %d\n", sum);
    printf("Enter number of additional size: ");
    scanf("%d", &n1);
    realloc(ptr, n1 * sizeof(int));
    
    for (i = 0; i < n1; i++)
    {
        scanf("%d", ptr + i);
        sum = sum + *(ptr + i);
    }
    printf("Additional numbers are:\n");
    for (i = 0; i < n1; i++)
    {
        printf("%d\n", *(ptr + i));
    }
    printf("Final Sum is %d", sum);
    return 0;
}

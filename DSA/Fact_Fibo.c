// Factorial
// #include <stdio.h>
// int fact(int n)
// {
//     if (n == 0 || n == 1)
//     {
//         return 1;
//     }
//     else
//         return n * fact(n - 1);
// }
// void main()
// {
//     int num, result;
//     printf("Enter any number: ");
//     scanf("%d", &num);

//     result = fact(num);
//     printf("The factorial of %d is %d", num, result);
// }

// Fibonacci
#include <stdio.h>
int fibo(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    else
        return (fibo(n - 1) + fibo(n - 2));
}
void main()
{
    int num, i;

    printf("Enter any number: ");
    scanf("%d", &num);

    for (i = 0; i < num; i++)
    {
        printf("%d,", fibo(i));
    }
}
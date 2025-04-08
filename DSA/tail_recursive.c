#include <stdio.h>

void tail(int n)
{
    while (n > 0)
    {
        printf("%d,", n);
        n--;
    }
}

int main()
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    tail(n);
    return 0;
}
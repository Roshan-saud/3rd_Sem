// Tower of Hanoi
#include <stdio.h>
int TOH(int n,char a,char b,char c)
{
    if (n > 0)
    {
        static int count = 1;
        TOH(n - 1, a, c, b);
        printf("%d. Move disk from %c to %c\n", count++, a, c);
        TOH(n - 1, b, a, c);
    }
}
void main()
{
    int num1;
    char a = 'S';
    char b = 'H';
    char c = 'D';
    int count;
    printf("Here S= Source, H= Helper and D= Destination\n");
    printf("Enter a value for number of disk: ");
    scanf("%d", &num1);
    TOH(num1, a, b, c);
}
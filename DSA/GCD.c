// GCD
#include <stdio.h>
int GCD(int a, int b)
{
   if (b == 0)
   {
      return a;
   }
   else
      return (GCD(b, a % b));
}
void main()
{
   int num1, num2, result;

   printf("Enter two number:\n");
   scanf("%d%d", &num1, &num2);

   result = GCD(num1, num2);
   printf("GCD of %d and %d is %d", num1, num2, result);
}
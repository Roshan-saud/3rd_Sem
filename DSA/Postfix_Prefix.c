// // Postfix evaluation
// #include <stdio.h>
// #include <math.h>
// int stack[50], top = -1;
// void sum();
// void sub();
// void mult();
// void div();
// void power();
// int main()
// {
//     char st[50];
//     int i;
//     printf("Enter the postfix expression:\n");
//     scanf("%[^\n]s", st);
//     // Here, to take space as input we use '%[^\n]s'
//     for (i = 0; st[i] != '\0'; i++)
//     {
//         if (st[i] != ' ')
//         {
//             switch (st[i])
//             {
//             case '+':
//                 sum();
//                 break;

//             case '-':
//                 sub();
//                 break;

//             case '*':
//                 mult();
//                 break;

//             case '/':
//                 div();
//                 break;

//             case '^':
//                 power();
//                 break;

//             default:
//                 top++;
//                 stack[top] = st[i] - 48;
//                 /*since, st[i] contain characters so, we subtract
//                 them with 48 so that (char: '0','1','2',...) changed
//                 to their interger form */
//             }
//         }
//     }
//     printf("\nThe result is %d\n", stack[top]);
// }

// void sum()
// {
//     int res, op1, op2;
//     op2 = stack[top];
//     top--;
//     op1 = stack[top];
//     top--;
//     res = op1 + op2;
//     top++;
//     stack[top] = res;
// }

// void sub()
// {
//     int res, op1, op2;
//     op2 = stack[top];
//     top--;
//     op1 = stack[top];
//     top--;
//     res = op1 - op2;
//     top++;
//     stack[top] = res;
// }

// void mult()
// {
//     int res, op1, op2;
//     op2 = stack[top];
//     top--;
//     op1 = stack[top];
//     top--;
//     res = op1 * op2;
//     top++;
//     stack[top] = res;
// }

// void div()
// {
//     int res, op1, op2;
//     op2 = stack[top];
//     top--;
//     op1 = stack[top];
//     top--;
//     res = op1 / op2;
//     top++;
//     stack[top] = res;
// }

// void power()
// {
//     int op1, op2, i;
//     op2 = stack[top];
//     top--;
//     op1 = stack[top];
//     top--;
//     stack[top++] = pow(op1, op2);
// }

// //Pre-fix evaluation
#include <stdio.h>
#include <math.h>
#include <string.h>

int stack[50], top = -1;

void sum();
void sub();
void mult();
void div();
void power();
void reverse(char str[]);

int main()
{
    char st[50];
    int i;

    printf("Enter the prefix expression:\n");
    scanf("%[^\n]s", st);
    // Reverse the input string to process prefix from right to left
    strrev(st);

    for (i = 0; st[i] != '\0'; i++)
    {
        if (st[i] != ' ') // Skip spaces
        {

                switch (st[i])
                {
                case '+':
                    sum();
                    break;

                case '-':
                    sub();
                    break;

                case '*':
                    mult();
                    break;

                case '/':
                    div();
                    break;

                case '^':
                    power();
                    break;

                default:
                   top++;
                 stack[top] = st[i] - 48;

            }
        }
    }

    printf("\nThe result is %d\n", stack[top]);
    return 0;
}

void sum()
{
    int op1 = stack[top--];
    int op2 = stack[top--];
    stack[++top] = op1 + op2;

}

void sub()
{
    int op1 = stack[top--];
    int op2 = stack[top--];
    stack[++top] = op1 - op2;

}

void mult()
{
    int op1 = stack[top--];
    int op2 = stack[top--];
    stack[++top] = op1 * op2;

}

void div()
{
    int op1 = stack[top--];
    int op2 = stack[top--];
    stack[++top] = op1 / op2;

}

void power()
{
    int op1 = stack[top--];
    int op2 = stack[top--];
    stack[++top] = pow(op1, op2);

}



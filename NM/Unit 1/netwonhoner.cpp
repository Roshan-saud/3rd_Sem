//Netwon method for polynomial/ synthetic division
#include <iostream>
#include <math.h>
#define EPS 0.00001
using namespace std;

void horner(int n, float a[], float x0, float p[])
{
    int i;
    p[0] = a[n];
    p[1] = a[n];
    for (i = n - 1; i >= 0; i--)
    {
        p[0] = a[i] + p[0] * x0;

        if (i > 0)
        { // Because P[1] goes 1 less step compare to p[0]
            p[1] = p[0] + p[1] * x0;
        }
    }
}

int main()
{
    float a[10], p[2], x0, x1;
    /* a[10] : To store the function coffecients
       p[2]:  p[0] and p[1] stores the value of the polynomial and its derivative at x0
       x0 : initial value
       x1: Next value from the initial value
       n : To store highest degree of polynomail
    */
    int i, n, count = 1;
    cout << "Enter degree of the polynomial: ";
    cin >> n;
    cout << "Enter the coffecients of the polynomail starting from the higher degree: " << endl;
    for (i = n; i >= 0; i--)
    {
        cin >> a[i];
    }
    cout << "Enter valid initil point x0: ";
    cin >> x0;
    horner(n, a, x0, p);
    x1 = x0 - (p[0] / p[1]);
    do
    {
        count++;
        x0 = x1;
        horner(n, a, x0, p);
        x1 = x0 - (p[0] / p[1]);
    } while (fabs((x1 - x0) / x1) > EPS);

    cout << "The approximation root of given function is " << x1 << " with ";
    cout << count << " number of iteration";
    return 0;
}
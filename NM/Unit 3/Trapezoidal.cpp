#include <iostream>
#include <cmath>
using namespace std;

float f(float x)
{
    return (x * x + 1);
}

int main()
{
    int i;
    float a, b, n, h, sum = 0.0, ict;
    cout << "Enter lower limit of integration a: ";
    cin >> a;
    cout << "Enter upper limit of intergration b: ";
    cin >> b;
    cout << "Give the segment width n: ";
    cin >> n;
    h = (b - a) / (n);
    for (i = 1; i <= n - 1; i++)
    {
        sum = sum + 2 * f(a + i * h);
    }
    sum = sum + f(a) + f(b);
    ict = (sum * h) / 2;
    cout << "Integration between " << a << " and " << b << " when h:" << h << " is " << ict;
    return 0;
}
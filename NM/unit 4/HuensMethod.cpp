//Question-2

#include <iostream>
#include <cmath>

using namespace std;

float f(float x, float y)
{
    return 2 * y * x;
    // return (2*y)/x;
}

int main()
{
    int i, n;
    float x, y, xp, h, m1, m2;
    cout << "Enter initial values of," << endl;
    cout << "x: ";
    cin >> x;
    cout << "y: ";
    cin >> y;
    cout << "Input x at which y is required: ";
    cin >> xp;
    cout << "Input step-size h: ";
    cin >> h;
    n = (int)((xp - x) / h + 0.5);
    for (i = 1; i <= n; i++)
    {
        m1 = f(x, y);
        m2 = f(x + h, y + m1 * h);
        y = y + 0.5 * h * (m1 + m2);
        x = x + h;

        /*
        y = y + 0.5 * h * ( f(x, y) + f(x + h,  y + h * f(x, y)));
        x = x + h;
        these two line also perform the same task
       */
    }

    cout << "\nValue of y at A = " << x << " is " << y;

    return 0;
}
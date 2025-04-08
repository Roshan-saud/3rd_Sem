// Question-6

#include <iostream>
#include <cmath>

using namespace std;

#define EPS 0.00001

float f1(float x, float y1, float y2)
{
    return y2;
}

float f2(float x, float y1, float y2)
{
    // return 4 * x * x * x * y1 + 2;
   return 2*x*x*y1 + 1;
}

float heun(float x0, float x1, float y0, float y1, float h)
{
    float m11, m12, m21, m22;
    while (fabs(x0 - x1) > 0.0001)
    {
        m11 = f1(x0, y0, y1);
        m21 = f2(x0, y0, y1);
        m12 = f1(x0 + h, y0 + h * m11, y1 + h * m21);
        m22 = f2(x0 + h, y0 + h * m11, y1 + h * m21);
        y0 = y0 + 0.5 * h * (m11 + m12);
        y1 = y1 + 0.5 * h * (m21 + m22);
        x0 = x0 + h;
    }
    return y0;
}

int main()
{
    float x0, yx0, x1, yx1, guess1, guess2, guess3, yxp, h, xp;
    char q;
    cout << "\t\t******BVP-Shooting Method******\n";
    cout << "\n Enter the first boundary conditions x and y(x): ";
    cin >> x0 >> yx0;
    cout << "\n Enter the second boundary conditions x and y(x): ";
    cin >> x1 >> yx1;
    cout << "\n Enter the step length: ";
    cin >> h;
    cout << "\n Enter the first guess of y'(" << x0 << "): ";
    cin >> guess1;

    heun(x0, x1, yx0, guess1, h);

    if (fabs(heun(x0, x1, yx0, guess1, h) - yx1) < EPS)
    {
        guess3 = guess1;
    }
    else
    {
        // ... (omitted for brevity)
    }

    cout << "\n\n Enter the second guess of y'(" << x0 << "): ";
    cin >> guess2;

    heun(x0, x1, yx0, guess2, h);

    if (fabs(heun(x0, x1, yx0, guess2, h) - yx1) < EPS)
    {
        guess3 = guess2;
    }

    cout << "\n\n Enter the point x at which y(x) is required: ";
    cin >> xp;

    cout << "\n The approximate value of y(" << xp << ") is " << heun(x0, xp, yx0, guess3, h) << ".";

    return 0;
}
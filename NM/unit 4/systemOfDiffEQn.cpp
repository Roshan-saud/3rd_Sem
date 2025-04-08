//Question-4



#include <iostream>
#include <cmath>

#define EPS 0.00001

using namespace std;

float f1(float x, float y1, float y2) {
    // return x + y1 + y2;
    return 1+y1 + y2;
}

float f2(float x, float y1, float y2) {
    // return 1+y1+y2;
    return y2+ x*y1+y1;
}

// Routine for Heun's method
void heun(float x0, float x1, float y0, float y1, float h) {
    float m11, m12, m21, m22;

    cout << "\n\nCalculation of y1(" << x1 << ") and y2(" << x1 << "):";
    cout << "\n\n x \t\ty1(x) \t\ty2(x)";

    while (fabs(x0 - x1) > 0.0001) {
        cout << "\n " << x0 << "\t\t" << y0 << "\t\t" << y1;
        m11 = f1(x0, y0, y1);
        m21 = f2(x0, y0, y1);
        m12 = f1(x0 + h, y0 + h * m11, y1 + h * m21);
        m22 = f2(x0 + h, y0 + h * m11, y1 + h * m21);
        y0 = y0 + 0.5 * h * (m11 + m12);
        y1 = y1 + 0.5 * h * (m21 + m22);
        x0 = x0 + h;
    }

    cout << "\n " << x0 << "\t\t" << y0 << "\t\t" << y1;
}

int main() {
    float x0, yx0, yx1, xp, h;
    char q;

    cout << "\t\t******Solving System of Differential Equations******\n";
    cout << "\n Enter the initial point x: ";
    cin >> x0;

    cout << "\n Enter the value of y1(x): ";
    cin >> yx0;

    cout << "\n Enter the value of y2(x): ";
    cin >> yx1;

    cout << "\n Enter the step length(h): ";
    cin >> h;

    cout << "\n\n Enter the point x at which y(x) is required: ";
    cin >> xp;

    heun(x0, xp, yx0, yx1, h);

    cout << "\n\n Do you want to approximate at another point?(y/n): ";
    cin >> q;

    return 0;
}

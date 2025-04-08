//Question-3
#include <iostream>
#include <cmath>
#include <conio.h>

using namespace std;

float f(float x, float y) {
    // return y*cos(x);
    return x+y;
}

int main() {
    int i, n;
    float x, y, xp, h, m1, m2, m3, m4;

    cout << "\nInput initial values of x and y: ";
    cin >> x >> y;

    cout << "\nInput x at which y is required: ";
    cin >> xp;

    cout << "\nInput step-size h: ";
    cin >> h;

    n = static_cast<int>((xp - x) / h + 0.5);

    for (i = 1; i <= n; i++) {
        m1 = f(x, y);
        m2 = f(x + 0.5 * h, y + 0.5 * m1 * h);
        m3 = f(x + 0.5 * h, y + 0.5 * m2 * h);
        m4 = f(x + h, y + m3 * h);

        x = x + h;
        y = y + (m1 + 2.0 * m2 + 2.0 * m3 + m4) * h / 6.0;

        cout << "\n" << i << "\t" << x << " " << y;
    }

    cout << "\nValue of y at x = " << xp << " is " << y << endl;
    return 0;
}

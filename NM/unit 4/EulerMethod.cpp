//Question-1 
#include <iostream>
#include <cmath>

using namespace std;

float f(float x, float y)
{
    // return (2 * y) / x;
    return 3 * x + y / 2;
}

int main()
{
    int i, n;
    float x, y, xp, h, dy;
    
    cout << "\t\t******Eulers method******\n";
    cout << "\nInput initial values of x and y: ";
    cin >> x >> y;
    cout << "\nInput x at which y is required: ";
    cin >> xp;
    cout << "\nInput step-size h: ";
    cin >> h;
    
    n = (int)((xp - x) / h + 0.5);
    
    for (i = 1; i <= n; i++)
    {
        dy = h * f(x, y);
        x = x + h;
        y = y + dy;
        // cout << "\n" << i << "\t" << x << "\t" << y << "\n";
    }
    
    cout << "\nValue of y at x=" << x << " is " << y << endl;
    
    return 0;
}
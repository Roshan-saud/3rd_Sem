#include <iostream>
#include <cmath>
#include <iomanip> // For fixed and setprecision
#define MAX 15
using namespace std;

int main()
{
    float x[MAX], bx[MAX], bd[MAX], xp, s, h, v, p;
    int n, i, j, k;
    char q;

    cout << "Input the number of data pairs: ";
    cin >> n;

    cout << "Input data pairs of x and f(x)" << endl;
    for (i = 1; i <= n; i++)
    {
        cout << "x[" << i << "]: ";
        cin >> x[i];
        cout << "f[" << i << "]: ";
        cin >> bx[i];
    }

    h = x[2] - x[1];

    do
    {
        cout << endl<<"Enter the value at which interpolation is required: ";
        cin >> xp;

        s = (xp - x[n]) / h;
        p = 1;
        v = bx[n];
        for (i = 1; i <= n; i++)
        {
            bd[i] = bx[i];
        }
        for (i = n, k = 1; i >= 1, k < n; i--, k++)
        {
            for (j = n; j > n - i; j--)
            {
                bd[j] = bd[j] - bd[j - 1];
            }
            p = p * (s + k - 1) / k;
            v = v + p * bd[n];
        }

        cout << endl<<"Interpolated function value at x = " << xp;
        cout << " is " << fixed<< setprecision(6) << v;
        cout << endl<<"Do you want to input another value? (y/n): ";
        cin >> q;

    } while (q == 'y');

    return 0;
}





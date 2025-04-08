#include <iostream>
#include <cmath>
#include <iomanip> // For fixed and setprecision
#define MAX 15
using namespace std;

int main()
{
    float x[MAX], fx[MAX], fd[MAX], xp, s, h, v, p;
    int n, i, j;
    char q;

    cout << "Input the number of data pairs: ";
    cin >> n;

    cout << "Input data pairs of x and f(x)" << endl;
    for (i = 0; i < n; i++)
    {
        cout << "x[" << i << "]: ";
        cin >> x[i];
        cout << "f[" << i << "]: ";
        cin >> fx[i];
    }

    h = x[1] - x[0];

    do
    {
        cout <<endl<< "Enter the value at which interpolation is required: ";
        cin >> xp;

        s = (xp - x[0]) / h;
        p = 1;
        v = fx[0];
        for (i = 0; i < n; i++)
        {
            fd[i] = fx[i];
        }
        for (i = 1; i < n; i++)
        {
            for (j = 0; j < n - i; j++)
            {
                fd[j] = fd[j + 1] - fd[j];
            }
            p = p * (s - (i - 1)) / i;
            v = v + p * fd[0];
        }

        cout <<endl<< "Interpolated function value at x = " << xp << " is " << fixed << setprecision(6) << v;
        cout <<endl<< "Do you want to input another value? (y/n): ";
        cin >> q;

    } while (q == 'y');

    return 0;
}

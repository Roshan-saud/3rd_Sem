#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

#define MAX 15

int main()
{
    int i, j, n;
    float xp, fp, sum, pi, x[MAX], f[MAX], a[MAX], d[MAX][MAX];
    char q;
    cout <<endl<<"Input the number of data pairs: ";
    cin >> n;
    cout <<endl<<"Input data pairs x(i) and values f(i) (one set in each line): "<<endl;
    for (i = 1; i <= n; i++)
        cin >> x[i] >> f[i];

    /*Construct difference table*/
    for (i = 1; i <= n; i++)
        d[i][1] = f[i];
    for (j = 2; j <= n; j++)
        for (i = 1; i <= n - j + 1; i++)
            d[i][j] = (d[i + 1][j - 1] - d[i][j - 1]) / (x[i + j - 1] - x[i]);

    /*Set the coefficients of interpolation polynomial*/
    for (j = 1; j <= n; j++)
        a[j] = d[1][j];

    /*Compute interpolation value*/
    do
    {
        cout <<endl<<"Input x at which interpolation is required: ";
        cin >> xp;
        sum = a[1];
        for (i = 2; i <= n; i++)
        {
            pi = 1.0;
            for (j = 1; j <= i - 1; j++)
                pi *= (xp - x[j]);
            sum += a[i] * pi;
        }
        fp = sum;
        cout << fixed << setprecision(6);
        cout << "Interpolated function value at x=" << xp << " is " << fp << ".";
        cout << "Do you want to input another value? (y/n): ";
        cin >> q;
    } while (q == 'y');
    
    return 0;
}

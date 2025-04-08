// Solving linear system using Gauss-Jordan Method with partial Pivoting
#include <iostream>
#include <cmath>
#define MAX 10
using namespace std;

int main()
{
    int i, j, k, n, pivrow;
    float a[MAX][MAX], b[MAX], large, temp, factor, pivot;
    cout << "\t\t******Gauss-Jordan Method with partial Pivoting******\n";
    cout << "\nInput number of variables: ";
    cin >> n;
    cout << "\nInput coefficients row-wise :\n";
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            cin >> a[i][j];
    cout << "\nEnter vector b: ";
    for (i = 1; i <= n; i++)
        cin >> b[i];
    for (i = 1; i <= n; i++)
    {
        pivrow = i;
        large = a[i][i];
        for (k = i + 1; k <= n; k++)
        {
            if (fabs(a[k][i]) > large)
            {
                large = a[k][i];
                pivrow = k;
            }
        }
        if (pivrow != i)
        {
            for (j = i; j <= n; j++)
            {
                temp = a[pivrow][j];
                a[pivrow][j] = a[i][j];
                a[i][j] = temp;
            }
            temp = b[pivrow];
            b[pivrow] = b[i];
            b[i] = temp;
        }
        pivot = a[i][i];
        for (j = 1; j <= n; j++)
            a[i][j] = a[i][j] / pivot;
        b[i] = b[i] / pivot;
        for (j = 1; j <= n; j++)
        {
            if (j != i)
            {
                factor = a[j][i];
                for (k = i; k <= n; k++)
                    a[j][k] = a[j][k] - factor * a[i][k];
                b[j] = b[j] - factor * b[i];
            }
        }
    }
    cout << "\nSolution vector x:\n";
    for (i = 1; i <= n; i++)
        cout << "\t" << b[i];
    return 0;
}

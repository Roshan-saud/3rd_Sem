// Solving linear system using Jacobi's Iterative method

#include <iostream>
#include <cmath>
#define MAX 10
#define EPS 0.0001
using namespace std;

int main()
{
    int i, j, n, key, count = 0;
    float a[MAX][MAX], b[MAX], x[MAX], xold[MAX], sum;
    cout << "\t\t******Jacobi's Iterative method******\n";
    cout << "\n Input number of variables: ";
    cin >> n;
    cout << "\n Input coefficients row-wise :\n";
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    cout << "\nEnter vector b:";
    for (i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    for (i = 1; i <= n; i++)
    {
        xold[i] = 0;
    }
    do
    {
        key = 0;
        for (i = 1; i <= n; i++)
        {
            sum = b[i];
            for (j = 1; j <= n; j++)
            {
                if (j != i)
                    sum = sum - (a[i][j] * xold[j]);
            }
            x[i] = sum / a[i][i];
            if ((key == 0) && (fabs(x[i] - xold[i]) / x[i] > EPS))
                key = 1;
        }
        for (i = 1; i <= n; i++)
            xold[i] = x[i];
        count++;
    } while (key == 1);
    cout << "\nSolution vector x:\n";
    for (i = 1; i <= n; i++)
        cout << "\t" << x[i];
    cout << "\n Number of iterations: " << count;
    return 0;
}

// Solving linear system using Gauss-Siedel Iterative Method
#include <iostream>
#include <cmath>
#define MAX 10
#define EPS 0.0001
using namespace std;

int main()
{
    int i, j, n, key, count = 0;
    float a[MAX][MAX], b[MAX], x[MAX], sum, dummy;
    cout << "\t\t******Gauss-Seidel Iterative Method******\n";
    cout << "\nInput number of variables: ";
    cin >> n;
    cout << "\nInput coefficients row-wise :\n";
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
        x[i] = 0;
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
                    sum = sum - (a[i][j] * x[j]);
            }

            dummy = sum / a[i][i];
            if ((key == 0) && (fabs(dummy - x[i]) / dummy) > EPS)
                key = 1;
            x[i] = dummy;
        }
        count++;
    } while (key == 1);
    cout << "\nSolution vector x:\n";
    for (i = 1; i <= n; i++)
    {
        cout << "\t" << x[i];
    }
    cout << "\n Number of iterations : " << count;
    return 0;
}

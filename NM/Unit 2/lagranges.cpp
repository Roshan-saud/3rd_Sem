#include <iostream>
using namespace std;

int main()
{
    float x[100], f[100], l = 1, px = 0, ip_point;
    int i, n, j;
    char condition;

    do
    {
        cout<<"Enter number of data:" ;
         cin>>n;
        cout<<"Enter value of x and f(x) respectively:"<<endl;
        for (i = 0; i < n; i++)
        {
            cout<<"x["<<i<<"]: ";
            cin>>x[i];
            cout<<"f["<<i<<"]: ";
            cin>>f[i];
        }
        cout<<"Enter interpolation point: ";
        cin>>ip_point;
        for (i = 0; i < n; i++)
        {
            l = 1;
            for (j = 0; j < n; j++)
            {
                if (i != j)
                {
                    l = l * (ip_point - x[j]) / (x[i] - x[j]);
                }
            }
            px = px + l * f[i];
        }
        cout<<"f("<<ip_point<<"):"<<px;
        px = 0;
        cout<<endl<<"Do you want to input another value? (y/n): ";
        cin>>condition;
    } while (condition == 'y');
}
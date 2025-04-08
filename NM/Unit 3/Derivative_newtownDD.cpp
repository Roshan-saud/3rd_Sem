#include<iostream>
#include<cmath>
using namespace std;


int main()
{
    char condition;
    int   n, i , k , j ;
    cout<<"Input number of data points: ";
    cin>>n;
    float x[n], f[n] ,d[n], diff = 0, f_first_val, xp, p=1;
    cout<<"Input values of x and f(x) one set of each line: "<<endl;
    for (i = 0; i < n; i++)
    {
        cout<<"x["<<i<<"]: ";
        cin>>x[i];
        cout<<"f["<<i<<"]: ";
        cin>>f[i];
    }
    f_first_val = f[0];
    
    for (i = 0; i < n-1; i++)
    {
        for ( j = 0; j < n-i-1; j++)
        {
            f[j] = (f[j+1] - f[j])/(x[j+i+1]-x[j]);
        }
        d[i] = f[0];
    }

    do{
    diff = diff + f_first_val;
    cout<<"Input x where derivative is required: ";
    cin>>xp;
    for ( i = 0; i < n-1; i++)
    {
        p = 1;
       for (j = 0; j< n-1; j++)
       {
         if(j<i+1)
         {
            p = p*(xp-x[j]);
           
         }
       }
       diff = diff +d[i]*p;
    }
    cout<<"The Derivative at x: "<<xp<<" is "<<diff<<endl;
    cout<<"Do you want to input another value?(y/n): ";
    cin>>condition;
    diff = 0;
   }while(condition=='y');
   return 0;
}
#include<iostream>
#include<cmath>
using namespace std;
#define MAX 20

int main()
{
    float x[MAX],y[MAX],xx[MAX],xy[MAX],Exx=0.0,Exy=0.0,Ex=0.0,Ey=0.0,a,b;
    int i,n;
    cout<<"Enter the size of data pair: ";
    cin>>n;
    for(i=0;i<n;i++)
    {
        cout<<"x["<<i<<"]: ";
        cin>>x[i];
        cout<<"y["<<i<<"]: ";
        cin>>y[i];
    }
    for(i=0;i<n;i++)
    {
        Ex = Ex + x[i];
        Ey = Ey + y[i];
        Exx = Exx + x[i]*x[i];
        Exy = Exy + x[i]*y[i];
    }

    b = (n*Exy - Ex * Ey)/(n*Exx-pow(Ex,2));
    a = (Ey/n)-(b*Ex/n);

   cout<<"Hence, straight line that is fit the given data is: "<<endl;
   cout<<" y = "<<a<<"+"<<b<<"x";
}
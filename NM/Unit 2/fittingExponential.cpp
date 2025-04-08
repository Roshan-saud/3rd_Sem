#include<iostream>
#include<math.h>
#define MAX 20
using namespace std;

int main()
{
  float x[MAX],y[MAX],ui[MAX],Exx=0.0,Ex=0.0,Exui=0.0,Eui=0.0,a,b,A;
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
        ui[i] = log(y[i]);
    } 
    for(i=0;i<n;i++)
    {
        Ex +=  x[i];
        Eui +=  ui[i];
        Exx +=  x[i]*x[i];
        Exui += x[i]*ui[i];
    } 

    b = (n*Exui-Ex*Eui)/(n*Exx-pow(Ex,2));
    A = (Eui/n)-(b*Ex/n);
    a = exp(A);
    cout<<"Hence, the required exponential equation of given data is: "<<endl;
   cout<<" y = "<<a<<"*e^("<<b<<"x"<<")";
   return 0;
}
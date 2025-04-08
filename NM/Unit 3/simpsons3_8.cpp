#include<iostream>
#include<cmath>
using namespace std;

float f(float x)
{
    return (2/(1+x*x*x));
}

int main()
{
   int i,n;
   float a, b, h, sum = 0.0 , ics,x;
   cout<<"Enter lower limit of integration: ";
   cin>>a;
   cout<<"Enter upper limit of intergration: ";
   cin>>b;
   do{
    cout<<"Enter number of segments n(divisible by 3): ";
    cin>>n;
   }while(n%3!=0);
   h = (b-a)/n;
   for(i=1;i<n;i++)
   {
    if(i%3==0)
    {
         sum = sum + 2*f(a+h*i);
    }
    else{
           sum = sum + 3*f(a+h*i);
    }
 
   }
   sum = sum + f(a) + f(b);
   ics = (3*h*sum)/8;
   cout<<"Intergration between "<<a<<" and "<<b<<" when h:"<<h<<" is "<<ics;
   return 0;
}
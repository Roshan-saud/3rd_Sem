#include<iostream>
#include<cmath>
using namespace std;

float f(float x){
 return (1/(1+x*x));
}

int main()
{
    int n , m , i;
    float a , b , h,  sum = 0.0 , ics;
    cout<<"Enter lower limit of integration: ";
    cin>>a;
    cout<<"Enter upper limit of intergration: ";
    cin>>b;
    do{
        cout<<"Enter number of segments n (Even number): ";
        cin>>n;
    }while(n%2!=0);
    h = (b-a)/n;
    m = n/2;
    for(i = 1; i<n; i++)
    {
        if(i%2==0)
        {
            sum = sum + 2*f(a+h*i);
        }
        else{
           sum = sum + 4*f(a+h*i);
        }
    }
    sum = sum + f(a) + f(b);
    ics = sum*h/3.0;
    cout<<"Integration between "<<a<<" and "<<b<<" when "<<"h:"<<h<<" is: "<<ics;
    return 0;
}

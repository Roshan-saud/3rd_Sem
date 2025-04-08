#include<iostream>
#include<cmath>
using namespace std;

float f(float x){
    return (x*x*exp(x)+sin(x));
}

int main()
{
    float a, h, fd1, fd2;
    char q;
    do{
        cout<<"Enter the point(x) at which derivatives are required: ";
        cin>>a;
        cout<<"Enter the value of h: ";
        cin>>h;
        fd1 = (f(a+h)-f(a-h))/(2*h);
        fd2 = (f(a+h)-2*f(a)+f(a-h))/(h*h);
        cout<<"The first and second derivitives at x: "<<a<<" are ";
        cout<<fd1<<" and "<<fd2<<endl;
        cout<<"Do you want to input another values?(y/n): ";
        cin>>q;
    }while(q=='y');
    return 0;
}
//Newton Rapson
#include<iostream>
#include<math.h>
using namespace std;
#define EPS 0.00001

float f(float x){
    return (x*sin(x)+cos(x));
}

float f1(float x){
    return (cos(x)*x);
}

int main(){
    float n,x0,x1;

    cout<<"Enter the initial value: ";
    cin>>x0;
    do{
      n++;
      x1 = x0 - (f(x0)/f1(x0));
      x0 = x1;
    }while(fabs((f(x1)))>EPS);
    cout<<endl;
	cout<<"The approximation root of given function is "<<x1<<endl;
	cout<<"With number of iteration: "<<n;
	return 0;


}
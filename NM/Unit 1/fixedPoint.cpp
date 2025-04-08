//Fixed-point iteration
#include<iostream>
#include<math.h>
using namespace std;
#define EPS 0.00001

float f(float x){
    return (x*x*x+x*x-1);
}


int main(){
    float n,x0,x1;
 
    cout<<"Enter the initial value: ";
    cin>>x0;
    do{
      n++;
      x1 = sqrt(2*x0+3);
      x0 = x1;
    }while(fabs((f(x1)))>EPS);
    cout<<endl;
	cout<<"The approximation root of given function is "<<x1<<endl;
	cout<<"With number of iteration: "<<n;
	return 0;
}
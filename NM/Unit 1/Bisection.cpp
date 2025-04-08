//Bisection
#include<iostream>
#include<math.h>
#define EPS 0.00001
using namespace std;

float f(float x){
	return x*exp(x)-1;
}

int main(){
	float a,b,c;
	int n = 0;
	do{
		cout<<"Enter two valid initial points a and b: "<<endl;
		cin>>a;
		cin>>b;
	}while(f(a)*f(b)>=0);
	
	do{
		n++;
		c = (a+b)/2;
		if(f(c)==0)
		break;
		if(f(a)*f(c)<0)
		b =c;
		else
		a = c;
	}while(fabs(f(c))>EPS);
	cout<<endl;
	cout<<"The approximation root of given function is "<<c<<endl;
	cout<<"With number of iteration: "<<n;
	return 0;
}

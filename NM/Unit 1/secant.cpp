//Secant
#include<iostream>
#include<math.h>
//#define EPS 0.0001
#define EPS 0.00001
using namespace std;

float f(float x){
	//return x*x*x-3*x+1;
    return 3*x+sin(x)-exp(x);
}

int main(){
	float x0,x1,x2;
	int n = 0;
		cout<<"Enter two valid initial points x0 and x1: "<<endl;
		cin>>x0;
		cin>>x1;

	do{
		n++;
		x2 = (x0*f(x1)-x1*f(x0))/(f(x1)-f(x0));
		if(f(x2)==0)
		break;
		x0 =x1;
        x1 = x2;
	}while(fabs(f(x2))>EPS);
	//}while(fabs((x1-x0)/x0)>EPS);
	cout<<endl;
	cout<<"The approximation root of given function is "<<x2<<endl;
	cout<<"With number of iteration: "<<n;
	return 0;
}

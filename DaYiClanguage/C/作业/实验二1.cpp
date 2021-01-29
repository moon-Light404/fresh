#include<iostream>
using namespace std;
int Max1(int a,int b);
int Max1(int a,int b,int c);
double Max1(double a,double b);
double Max1(double a, double b,double c);
int main()
{
	Max1(2,3);
	cout<<endl;
	Max1(6,2,9);
	cout<<endl;
	Max1(2.5,3.6,3.75);
	cout<<endl;
	Max1(2.5,3.65);
	return 0;
}
int Max1(int a,int b)
{
	int z;
	z=a<b?b:a;
	cout<<z;
}
int Max1(int a,int b,int c)
{
	if(a>c)
	c=a;
	if(b>c)
	c=b;
	cout<<c;
	 
}
double Max1(double a,double b)
{
	double z;
	z=a<b?b:a;
	cout<<z;
}
double Max1(double a, double b,double c)
{
		if(a>c)
	c=a;
	if(b>c)
	c=b;
	cout<<c;
}


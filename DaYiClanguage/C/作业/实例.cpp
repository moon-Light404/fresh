#include<iostream>
using namespace std;
bool fun(int n)
{
	int m,k,b;
	m=n/100;
	k=n/10%10;
	b=n%10;
	if(m*m*m+k*k*k+b*b*b==n)
	return true;
	
	else return false;
}
int main()
{
 int a;
 a=fun(158);
 cout<<a<<endl;

}

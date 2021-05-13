#include<iostream>
using namespace std;
int Fibonacci(int n);
int main()
{
	int n,F;
	cin>>n;
	F=Fibonacci(n);
	cout<<"Fib¼¶Êý"<< F;	
	return 0;
}
int Fibonacci(int n)
{
	int f;
	if(n==1||n==2)
	return 1;
	else  return Fibonacci(n-1)+Fibonacci(n-2);

}



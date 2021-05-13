#include<iostream> 
using namespace std;
long pow_2(int b){
	long x=2;
	long res=1;
	while(b>0){
		if(b&1)
		res*=x;
		b>>=1;
		x=x*x;
	}
	return res;
}
int gcd(long a,long b){
	return b==0?a:gcd(b,a%b);
}
int main()
{
	cout<<pow_2(20)<<endl;
	
	
}

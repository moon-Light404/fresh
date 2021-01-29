#include<iostream>
#include<bits/stdc++.h>>
using namespace std;
bool isprime(int n){
	for(int i=2;i<=sqrt(n);i++){
		if(n%i==0)
		return false;
	}
	return true;
}
void Decom(int n)
{
	int i = 2;
 
	printf("%d=", n); //¼ÙÉèn=165
 
	while (1)
	{
		if (i == n)
		{
			printf("%d", i);
			break;
		}
		
		while (n%i == 0)
		{	
			printf("%d*", i);
			n /= i;
		}
 
		i++;
	}
}
int main(){
	int N;
	cin>>N;
	Decom(N);
	return 0; 
}

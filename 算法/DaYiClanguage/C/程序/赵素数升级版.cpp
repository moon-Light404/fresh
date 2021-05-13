#include<iostream>
using namespace std;
int main()
{
int n;
cin >>n;
int a[n];
bool isprime;
int count=0;
for(int i=2;i<=n;i++)
{
	bool isprime =true;
	for(int j=0;j<count;j++)
	if(i%a[j]==0)
	{
		isprime =false;
		break;
	}
	if(isprime){
		a[count++]=i;
	}
	
}
for(int i=0;i<count;i++)
{
	cout<< a[i];
	cout<<endl;
	
}
return 0;
}

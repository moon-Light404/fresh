#include<iostream>
using namespace std;
int main()
{
	int n;
	int p;
	cin>>n>>p;
	int a[n];
	int s=0;
	static int max=0;
for(int i=0;i<n;i++)
cin>>a[i];
	
	
	for(int i=0;i<n-2;i++)
	{
	
	for(int j=i+1;j<n-1;j++){
	
	for(int k=j+1;k<n;k++)
	
	{
		s=a[i]+a[j]+a[k];
		if(s%p==0&& s>max)
		{
		max=s;
	}
    }
	}
}
	cout<<max<<endl;
	
}


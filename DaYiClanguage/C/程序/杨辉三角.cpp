#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[21][30]={0};
	 a[1][1]=a[2][1]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			if(j==1)
			a[i][j]=1;
			if(i==j)
			a[i][j]=1;
			
			else a[i][j]=a[i-1][j]+a[i-1][j-1];
		}
	}
	for(int i=1;i<=n;i++)
	{
	for(int j=1;j<=i;j++)
	{
		printf("%d ",a[i][j]);
	}
	printf("\n");
}
	
 } 

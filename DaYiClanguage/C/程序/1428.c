#include<stdio.h>
int main()
{
	int i,j,n,a[101],b[101]={0};
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=1;i<=n;i++)
	 for(j=i;j>=1;j--)
	 {
	 if(a[i]>a[j])  b[i]++;
	 }
	 
	 for(i=1;i<=n;i++)
	 printf("%d ",b[i]);
	 return 0;
	
}

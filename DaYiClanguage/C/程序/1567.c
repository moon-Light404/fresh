
#include<stdio.h>
int main()
{
	int i,k=1,n,max,a[1000],b[1000];
	scanf("%d",&n);
	for( i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	
	for( i=0;i<n;i++)
	{
		if(a[i]<a[i+1])
		{k++;
		b[i]=k;
	}
	else {
		k=1; b[i]=k;
	}
		 
	}
	max=b[1];
	for(i=0;i<n;i++)
	{
		if(max<b[i]) max=b[i];
	}
	printf("%d",max);
	
	
	return 0;
}

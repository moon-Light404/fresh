#include<stdio.h>


int main()
{
	int a[15];
	int b;
	int count=0;
	int i;
	for( i=1;i<=10;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("\n");
	scanf("%d",&b);
	
	for(i=1;i<=10;i++)
	{
	if((b+30)>=a[i])
	count++;
	}
	printf("%d",count);
	return 0;
}

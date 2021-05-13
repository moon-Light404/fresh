#include<stdio.h>
int main()
{
	int a[101],i;
	for(  i=0;i<100;i++)
	{
	scanf("%d",&a[i]);
	if(a[i]==0) break;
    }
	while(i>=0)
	{if(a[i]==0)  ;
	 else printf("%d ",a[i]);
	i--;
	 } 
	 return 0;
}

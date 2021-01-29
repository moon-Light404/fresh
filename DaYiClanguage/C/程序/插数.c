#include<stdio.h>
int main()
{
	int a[10];
	int n,b;
	int i=0;
	int k;
	int *p;
	printf("请输入你要输入多少个数:");
	scanf("%d",&n);
	printf("请输入输入的数:");
	printf("请输入你要插入的数:");
	scanf("%d",&b); 
	printf("输入你原来的数：");
	while(i<n)
	{
		scanf("%d",&a[i]);
		i++;
	 } 
	 i=0;
	 p=a;
	 for(p=a;p<p+n;p++)
	 {  i++;
	 	if(*p>b)
	 	break;
	 	
	 }
	 
	 for (k=n-1;k>=i-1;k--)
	{
		a[k+1]=a[k];
	 } 
	 
	 
	 *p=b; 
	 for(i=0;i<n+1;i++)
	 {
	 	printf("%d ",a[i]);
	 }
	 return 0;
	 
}

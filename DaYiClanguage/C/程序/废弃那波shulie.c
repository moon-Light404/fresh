#include<stdio.h>
int main()
{
	int i,n,t1=0,t2=1,next;
	printf("输出几项:");
	scanf("%d",&n);
	printf("废弃那波数列：");
	for(i=1;i<=n;i++)
	{
		printf("%d",t1);
		next=t1+t2;
		t1=t2;
		t2=next;
	 } 
}

#include<stdio.h>
int main()
{
	int i,n,t1=0,t2=1,next;
	printf("�������:");
	scanf("%d",&n);
	printf("�����ǲ����У�");
	for(i=1;i<=n;i++)
	{
		printf("%d",t1);
		next=t1+t2;
		t1=t2;
		t2=next;
	 } 
}

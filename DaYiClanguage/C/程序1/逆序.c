#include<stdio.h>
int main()
{
	int A;
	int a;
	scanf("%d",&A);
	while(A>0)
	{
		a=A%10;
		A=A/10;
		printf("%d",a);
	}
	return 0;
}

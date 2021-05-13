#include<stdio.h>
int main()
{
	int n;
	int i=0;
	int j,k;
	scanf("%d",&n);
	for(i=n;i>=1;i--)
	{
		for(j=0;j<n-i;j++)
		{
			printf(" ");
		}
		for(k=1;k<=2*i-1;k++)
		{
			printf("#");
			
		}
		printf("\n");
	}
	return 0;
}

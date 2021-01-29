#include<stdio.h>

int main()
{
	int T;
	char c;
	int amount;
	
	scanf("%d",&T);
	getchar();
	while(T--)
	{
		amount=0;
		while((c=getchar())!='\n'){
			
			amount++;
		}
		printf("%d\n",amount/2);
	}
	return 0;
}

#include<stdio.h>
#include<math.h>
#include<string.h>
#define N 2000001
int main()
{
	int i;
	int j;
	char flag[N];
	memset(flag,'0',N);
	
	for(i=2;i<=sqrt(N);i++)
	{
		for(j=i*i;j<N;j+=i)
		{
			flag[j]='1';
		}
	}
	int number;
	while(1)
	{
		scanf("%d",&number);
		
		if(number==0)
		break;
		
		
		for(i=2;i<=number;i++)
		{
			if(flag[i]=='0')
			printf("%d ",i);
		}
		printf("\n");
	}
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}

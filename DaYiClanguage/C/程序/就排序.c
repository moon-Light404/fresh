#include<stdio.h>
int main()
{
	int T;
	int i;
	int n;
	
	scanf("%d",&T);
	
	while(T--)
	{
		scanf("%d",&n);
		for(i=0;i<=n;i++)
		{
			if(i%2==1){
				if(i==1) 
				printf("%d",i);
				
				else printf(" %d",i);
			}
		}
		printf("\n");
		
		for(i=1;i<=n;i++)
		{
			if(i%2==0){
				if(i==2)
				printf("%d",i);
				
				else printf(" %d",i);
			}
			  
		}
		printf("\n");
	}
 } 

#include<stdio.h>
int main()
{
	char ac[]={0,1,2,3,4,5,6,7,8,9,-1};
	char *p= &ac[0];
	int i;
	for(i=0;i<sizeof(ac)/sizeof(ac[0]);i++)
	{
		printf("%d",ac[i]);
	}
	//for(p=ac;*p!=-1 ;p++)
	printf("\n");
	while (*p!=-1){
	
		printf("%d",*p++);
	}
	 //} 
	int ai[]={0,1,2,3,4,5,6,7,8,9};
	int *q=ai;
	return 0;
}

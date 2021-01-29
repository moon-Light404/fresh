#include<stdio.h>
#include<stdlib.h>
void populate(int *arry,size_t arrysize,int(*getNextValue)())
{
	size_t i=0;
	for( i=0;i<arrysize;i++)
	arry[i]=getNextValue();
}

int getNextRandomValue()
{
	return rand();
}

int main()
{
	int myarry[10];
	populate(myarry,10,getNextRandomValue);
	int i;
	for( i=0;i<10;i++)
	{
		printf("%d ",myarry[i]);
	}
	printf("\n");
	return 0;
}

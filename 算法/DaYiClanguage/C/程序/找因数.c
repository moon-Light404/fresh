#include<stdio.h>
int main()
{
	int number,i;
	while((scanf("%d",&number))!=EOF){
	
	printf("%d��������:",number);
	for(i=1;i<=number;i++)
	{
		if(number%i==0)
		printf("%d ",i);
	}
}
	return 0;
}

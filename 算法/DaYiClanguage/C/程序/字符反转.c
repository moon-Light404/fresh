#include<stdio.h>
void revenu();
int main()
{ 
    int T;
    scanf("%d",&T);
	while(T>0)
	{
		revenu();
		printf("\n");
		T--;
	}
	return 0;
}



void revenu()
{
	char c;
    scanf("%c",&c);
    if(c!='\n')
    {
    	revenu();
    	printf("%c",c);
	}
}


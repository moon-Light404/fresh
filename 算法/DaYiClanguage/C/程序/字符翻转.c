#include<stdio.h>
void reverseSentence();
int main()
{
	printf("ÊäÈëÒ»¸ö×Ö·û´®:");
	reverseSentence();
}
void reverseSentence()
{
	char c;
	scanf("%c",&c);
	if(c!='\n')
	{
		reverseSentence();
		printf("%c",c);
	}
}

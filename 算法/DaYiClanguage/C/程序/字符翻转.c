#include<stdio.h>
void reverseSentence();
int main()
{
	printf("����һ���ַ���:");
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

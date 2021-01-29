#include<stdio.h>
int main()
{
	int a,b;
	a=3;
	b=2;
	b= a++;
	a =  ++b;
	printf("%d,%d",a,b);
}

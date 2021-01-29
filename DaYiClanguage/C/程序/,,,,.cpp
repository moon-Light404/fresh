#include<stdio.h>
int main()
{   
    int a;
	 int* p=&a;
	a=10;
	printf("%d",*p);
	return 0;
}

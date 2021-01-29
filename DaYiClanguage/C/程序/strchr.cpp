#include<stdio.h>
#include<string.h>

int main(int argc,char const *argv[])
{
	char s[]="hello";
	char* p=strchr(s,'l');
	p=strchr(p+1,'l');
	printf("%s\n",p);
	return 0;
}

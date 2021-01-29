#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	char s[]="hello";
	char c= *p;
	char* p=strchr(s,'l');
	*p='\0';
	char *t=(char*)malloc(strlen(s)+1);
	strcpy(t,s);
	printf("%s\n",t);
	free(t);
	*p=c;
	printf("%s\n",s);
	
	return 0;
 } 

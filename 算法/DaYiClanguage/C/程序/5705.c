#include<stdio.h>
#include<string.h>
int main()
{ 
  int i,n;
  char str1[40];
  char str2[40];
  scanf("%s",str1);
  i=strlen(str1)-1;
  for(n=0;i>=0;n++)
  {
  	str2[n]=str1[i];
  	i--;
  }
  str2[strlen(str1)]=0;
	puts(str2);
	return 0;
 } 

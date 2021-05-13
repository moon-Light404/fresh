#include<stdio.h>
#include<string.h>
int main()
{
	char c;
	char s[100];
	int i;
	int length;
	
	while(scanf("%c",&c)!=EOF)
	{
		i=0;
		while(c!='\n'){
			s[i]=c;
			i++;
			c=getchar();
		}
		
		s[i]='\0';
		length=strlen(s);
		
		for(i=0;i<length-2;i++)
		{
			if(s[i]=='y' && s[i+1]=='o'&& s[i+2]=='u'){
			
				s[i]='w';
				s[i+1]='e';
				s[i+2]='\0';
			}
	}
		
		for(i=0;i<length;i++)
		{
			if(s[i]!='\0')
			printf("%c",s[i]);
		}
		printf("\n");
	}
	return 0;
}

#include<stdio.h>
int main()
{   
    int number;
    int R;
    int length;
    char s[50];
    int flag;
    while(scanf("%d %d",&number,&R)!=EOF)
    {   int i=0;flag=1;
        if(number<0) {
        	flag=0;
        	number=-number;
		}
    	while(number){
    		if(number%R<=9)  s[i]=(number%R)+'0';
    		
    		else if(number%R==10)  s[i]='A';
    		
    		else if(number%R==11)  s[i]='B';
    		
    		else if(number%R==12)  s[i]='C';
    		
    		else if(number%R==13)  s[i]='D';
    		
    		else if(number%R==14)   s[i]='E';
    		
    		else if (number%R==15)  s[i]='F';
    		
    		number/=R;
    		i++;
 		}
 		if(flag==0)  printf("-");
 		length=i-1;
 		for(i=length;i>=0;i--)
 		{
 			printf("%c",s[i]);
		 }
 		
	}
}

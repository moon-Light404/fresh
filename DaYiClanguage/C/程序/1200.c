#include<stdio.h>
int main()
{
 char a[6],b[6];
 int i,t=1,p=1;
 int x,y;
 gets(a);
 gets(b);
 for(i=0;i<6;i++)
 {
 	t*=(a[i]-'@');
 	p*=(b[i]-'@');
	 }	
	 x=t%47;
	 y=p%47;
	 
 if  (x==y)
 printf("GO");
 
 else printf("STAY");
 
 return 0;
}

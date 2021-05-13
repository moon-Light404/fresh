#include<stdio.h>
int getlm(int a,int b);
int getly(int a,int b);
int main()
{
	int a;
	int b;
	while(scanf("%d %d",&a,&b)!=EOF)
	{
		printf("%d %d\n",getlm(a,b),getly(a,b));
	}
	
	
	
	
	return 0;
	
	
 } 	
 int getlm(int a,int b)
 {
 	int A;
 	int B;
 	int r;
 	int temp;
 	A=a;
 	B=b;
 	if(a<b)
 	{
 		temp=a;
 		a=b;
 		b=temp;
	 }
 	while(a%b)
 	{
 		r=a%b;
 		a=b;
 		b=r;
	 }
	 return A*B/b;
 }
 int getly(int a,int b)
 {
 		int A;
 	int B;
 	int r;
 	int temp;
 	A=a;
 	B=b;
 	if(a<b)
 	{
 		temp=a;
 		a=b;
 		b=temp;
	 }
 	while(a%b)
 	{
 		r=a%b;
 		a=b;
 		b=r;
	 }
	 return b;
 }

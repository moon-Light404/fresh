#include<stdio.h>
int gad(int a,int b);
int main()
{
	int a;
	int b;
	int c;
	int d;
	char sign;
	int fenmu,fenzi;
	char temp;
	
	while(scanf("%d/%d%c%d/%d",&a,&b,&sign,&c,&d)!=EOF)
	{
		
		fenmu=b*d/gad(b,d);
		if(sign=='+')
		fenzi=a*fenmu/b+c*fenmu/d;
		else if (sign=='-')
		fenzi=a*fenmu/b-c*fenmu/d;
		
		if(fenzi==0){
		
		printf("0\n");
		continue; 
	}
		
		temp='+';
		if(fenzi<0)
		{
			temp='-';
			fenzi=-fenzi;
		}
		if(temp=='-') 
		{
			printf("-");
		}
		if(fenzi%fenmu==0)
		printf("%d\n",fenzi/fenmu);
		
		
		else printf("%d/%d\n",fenzi/gad(fenzi,fenmu),fenmu/gad(fenzi,fenmu));
	}
	
return 0;
}

int gad(int a,int b)
{
	int temp;
	int r;
	if(a<b)
	{
		temp=b;
		b=a;
		a=temp;
	 } 
	while(a%b)
	{
		r=a%b;
		a=b;
		b=r;
	}
	return r;
 } 


 

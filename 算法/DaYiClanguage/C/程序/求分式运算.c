#include<stdio.h>
int gcd(int a,int b);
int main()
{
	int a;
	int b;
	int c;
	int d;
	char sign;
	int fenmu,fenzi;
	char temp;
	
	while(scanf("%d %d %c %d %d",&a,&b,&sign,&c,&d)!=EOF)
	{
		fenmu=b*d/gcd(b,d);
		
		if(sign=='+')
		    fenmu=a*fenmu/b+c*fenmu/d;
		else
		fenzi=a*fenmu/b-c*fenmu/d;
		if(fenzi==0)
		{
			printf("0\n");
			continue;
		}
		temp='+';
		if(fenzi<0)
		{
			fenzi=-fenzi;
			temp='-';
		}
		
		if(temp=='-')
		
		printf("-");
		if(fenzi%fenmu==0)
		printf("%d\n",fenzi/fenmu);
		
		
	    else
		printf("%d/%d\n",fenzi/gcd(fenzi,fenmu),fenmu/gcd(fenzi,fenmu));
		
		return 0; 
	}
}
int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}

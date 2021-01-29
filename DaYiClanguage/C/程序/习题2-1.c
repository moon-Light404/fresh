#include<stdio.h>
int main()
{
	int a,b,c;
	int i=0;
	int kase=0;
while(scanf("%d %d %d",&a,&b,&c)!=EOF)
{
	
for(i=10;i<=100;i++)
{
	if(i%3==a && i%5==b &&i%7==c)
	{
		printf("Case %d:%d\n",++kase,i);
		break;
	}
}
if(i==101)  printf("нч╫Б\n");

}
return 0;

}

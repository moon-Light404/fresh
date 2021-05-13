#include<stdio.h>
int main()
{
int n,k;
int i;
scanf("%d %d",&n,&k);
for(i=0;i<k;i++)
{
	while(n%10!=0)
	{
		n--;
		i++;
		if(i>=k)
		break;
	}
	if(i<=k-1) n/=10;
}
printf("%d",n);
return 0;
	

}

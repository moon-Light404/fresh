#include<stdio.h>
#define MIN(a,b)(a)>(b)  ? (b) :(a)
int min(int a,int b,int c)
{                               
	int ret;
	ret=MIN(a,b);
	ret=MIN(ret,c);
	return ret;              
}
int nthu(int n)
{
	int dp[n];            /* 输入一个数n，找到第n个丑数，丑数只能是
	                        2，3，5的倍数，规定1是最小的丑数*/ 
	int i;
	int l2=0;
	int l3=0;
	int l5=0;
	memset(dp,0,sizeof(int)*n);
	dp[0]=1;
	for(i=1;i<n;i++)
	{
		dp[i]=min(dp[l2]*2,dp[l3]*3,dp[l5]*5);
		if(dp[i]==dp[l2]*2) l2++;
		if(dp[i]==dp[l3]*3)  l3++;
		if(dp[i]==dp[l5]*5)  l5++;   /*出现2，3，5的倍数，对应的下标加1，因为这个
		  下标下次已经没有用了，已经插入到数组里去了，所以加1，再比较最小的丑数
		  */ 
	}
	return dp[n-1];
}
int main()
{
	int n;
	int m;
	printf("请输入第几个数:");
	scanf("%d",&n);
	
	printf("%d",nthu(n));
}

/*丑数： 1   2   3   4   5   6  8   9   10  12
个数： 1   2   3   4   5   6  7   8   9   10
 dp[0]=1          l2        l3       l5 
dp[1]=2        1          0         0
dp[2]=3        1          1         0       先取最小的数， 
dp[3]=4        2          1         0
dp[4]=5        2          1         1
dp[5] =6       3          2         1
dp[6]=8        4          2         1
dp[7] =9       4          3         1
dp[8] =10      5          3         2      下标对应的数分别乘以2，3，5
                                      一般乘以的数越大，下标增加的慢，也越小 
dp[9]=12
dp[10]
*/ 







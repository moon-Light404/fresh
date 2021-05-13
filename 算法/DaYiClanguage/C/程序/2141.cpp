#include<stdio.h>
int main()
{
	int t[200005],g[200005];
	int n,ans=0,a[105];
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
	scanf("%d",&a[i]);
	g[a[i]]=1;
	}
	for(int i=1;i<n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			t[a[i]+a[j]]++;
		}
	}
	for(int i=1;i<=200002;i++)
	{
	if(t[i]>0 && g[i]==1)   ans++;
}
	printf("%d",ans);
	return 0;  
}

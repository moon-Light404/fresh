#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int n,a,b,ans=0x7ffffff;
int flor[205];
bool vis[205];
void dfs(int now,int sum)//now表示当前楼层,sum表示按键次数 
{
	cout<<"现在是"<<now<<"楼"<<endl; 
	if(now==b) ans=min(ans,sum);//b是目标楼层 
	if(sum>ans) return ;//没有到达一次b层 
	vis[now] = 1;//表示到过了
	
	if(now+flor[now]<=n && !vis[now+flor[now]]) dfs(now+flor[now],sum+1);
	
	if(now-flor[now]>=1 && !vis[now-flor[now]])  dfs(now-flor[now],sum+1);
	vis[now]=0;
	
	
 } 
 
 int main(){
 	cin>>n>>a>>b;
 	for(int i=1;i<=n;i++)
 	{
 		cin>>flor[i];
	 }
	
	 vis[a]=1;
	 dfs(a,0);
	 if(ans!=0x7ffffff) cout<<ans;
	 else cout<<"-1";
	 return 0;
 }
 






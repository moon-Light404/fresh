#include<bits/stdc++.h>
using namespace std;
int mp[6][6];
bool vis[6][6];
int dx[4]={0,0,1,-1};
int dy[4]={-1,1,0,0};
int ans,fx,fy,sx,sy,T,n,m,l,r;//l,r是障碍的横纵坐标
void bfs(int x,int y){
	if(x==fx&&y==fy){
		ans++;
		return;//f-final终点 s-起点 
	}
	else{
		for(int i=0;i<=3;i++){//四个方向 
			if(vis[x+dx[i]][y+dy[i]]==0 && mp[x+dx[i]][y+dy[i]]==1){//1表示此处无障碍 
				vis[x][y]=1;//走过的地方标记 
				bfs(x+dx[i],y+dy[i]);//走过去 
				vis[x][y]=0; //还原标记 
			}
		}
	}
} 

int main(){
	cin>>n>>m>>T;
	for(int ix=1;ix<=n;ix++){
		for(int iy=1;iy<=m;iy++)
		mp[ix][iy]=1;//1表示能走 
	}
	cin>>sx>>sy;
	cin>>fx>>fy;
	for(int k=1;k<=T;k++){
		cin>>l>>r;
		mp[l][r]=0;//0表示为障碍不能走 
	}
	bfs(sx,sy);
	cout<<ans;
	return 0;
}

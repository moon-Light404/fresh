#include<bits/stdc++.h>
using namespace std;
int ans=0;
bool vis[1000] ={false}; 
int P[1000];
void generateP(int index,int n);

int main(){
	int m;
	cin>>m;
	generateP(1,m);
	cout<<ans;
	return 0;
}
void generateP(int index,int n){
	if(index == n+1){
		ans++;//总数加1--- 
		if(ans<=3){
		for(int i=1;i<=n;i++){
			cout<<P[i]<<" ";
		}
		cout<<endl;
	}
		return;
	}
	for(int x=1;x<=n;x++){
		if(vis[x] == false){
			bool flag = true;
			for(int pre=1;pre<index;pre++){
				if(abs(index-pre)==abs(x-P[pre])){//先判断对角线的情况 
					flag = false;
					break;
				}
			}
			if(flag){
				P[index] = x;
				vis[x]=true;
				generateP(index+1,n);
				vis[x]=false;
			}
		
		}
	}	
}

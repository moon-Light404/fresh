#include<bits/stdc++.h>
using namespace std;
// a-0 b-1 c-2 d-3 e-4 f-5 g-6
int ve[7][7];//表示两个二极管是否相邻,1-相邻  0-不相邻 
bool vis[7];
int ans = 0;
set<set<int> >se;
void dfs(int x,set<int> s){//传入一个集合带有数字表示相邻二极管的一串数字 
	if(!se.count(s)){
		cout<<"现在k="<<x<<endl;
		se.insert(s);//插入一个集合,方便下次查重
		
		
		set<int>::iterator it;
		for(it=s.begin();it!=s.end();it++)
		{
			cout<<char('a'+*it)<<" ";
		}
		cout<<endl;
		ans++; 
		cout<<"\n"<<"现在ans的值"<<ans<<"\n";
	}
	if(s.size()==7)
	return;
	for(int k=0;k<7;k++){
		if(!vis[k] && ve[x][k]){
//			cout<<"现在k="<<k<<endl;
			vis[k]=1;
			s.insert(k);
			dfs(k,s);
			vis[k]=0;
			s.erase(k);
		}
	}
}
void add(int x,int y){
	ve[x][y]=1;
	ve[y][x]=1;
}
int main(){
	//a相邻的边 
	add(0,1);
	add(0,5);
	
	//b
	add(1,6);
	add(1,2);
	
	//c
	add(2,6);
	add(2,3);
	
	//d
	add(3,4);
	
	//e
	add(4,5);
	add(4,6);
	
	//f
	add(5,6);
	set<int> s; 
	for(int i=0;i<=6;i++){
		cout<<"\t"<<"现在i="<<i<<endl; 
		s.insert(i);
		vis[i]=1;
		dfs(i,s);
		vis[i]=0;
		s.erase(i);
	}
	cout<<ans;
	return 0;
}

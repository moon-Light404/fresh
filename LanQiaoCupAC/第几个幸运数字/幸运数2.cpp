#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
set<ll> s;
long long maxn=343 ;

int main(){
	int a[3] = {3,5,7};
	ll t = 1;
	while(true){
	for(int i=0;i<3;i++){
		if(t*a[i]<=maxn)
		s.insert(t*a[i]);
	}
	t = *s.upper_bound(t);
	if(t == maxn)
	break;	
}
	cout<<s.size()<<endl;
	cout<<"这是测试从github网站上测试再到文件中验证"<<endl;
	return 0;
} 

#include<bits/stdc++.h> 
using namespace std;
int main(){
	string str;
	stringstream ss;
	int a,s=0;
	cin>>a;
	for(int i=1;i<=a;i++){
		ss<<i;
		ss>>str;
		s+=count(str.begin(),str.end(),'1');
		ss.clear();//������л�����֮ǰ���������,��clearɾ�� 
	}
	cout<<s<<endl;
	return 0;
}

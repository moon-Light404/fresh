#include<bits/stdc++.h>
using namespace std;
int main(){
	string m;
	int sum=0;
	while(getline(cin,m)){
		int k=m.size();
		for(int i=0;i<k;i++){
			sum+=(int)(m[i]-'0');
		}
		cout<<sum<<endl;
		sum=0; 
	}
	return 0;
}

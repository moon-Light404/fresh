#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
ll ans = 0;
int is_2019(int x){
	while(x){
		int t = x % 10;
		if(t == 2|| t == 0||t==1 || t == 9)
			return 1;//∑µªÿ’Ê 
			x /= 10;
}
return 0;
}
int main()
{
	
	for(int i=1;i<=2019;i++){
		if(is_2019(i)){
			ans += i*i;
		}
	}
	cout<<ans<<endl;
	return 0;
  cout<<"sawfwa";
}



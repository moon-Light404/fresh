#include<bits/stdc++.h>
using namespace std;
int a[10]={1,2,0,9,8,7,6,4,10,12};
int main(){
	int b = (upper_bound(a,a+10,8)-a)+1;
	cout<<b;
	return 0;
}

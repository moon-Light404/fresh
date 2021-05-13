#include<bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int n,p,a[maxn];

int binarySearch(int i,long long x){  //M���ֵ  m��Сֵ  -> m*x>=M 
	if(a[n-1]<=x) return n;
	int p=i+1,r=n-1,mid;
	while(p<r){
		mid=(p+r)/2;
		if(a[mid]<=x){
			p = mid+1;
		}
		else{
			r =mid;
			}	
	}
	return p;
}

int main(){ 
	cin>>n>>p;
	for(int i =0 ;i<n;i++){
		cin>>a[i];
	}
	
	sort(a,a+n);
	int ans=1;
	for(int i=0;i<n;i++){
		int j = binarySearch(i,(long long)a[i]*p );//�ҵ���һ������a[i]*p��λ�� 
		ans = max(ans,j-i);//������󳤶� 
	}
	cout<<ans<<endl;
	return 0;
}


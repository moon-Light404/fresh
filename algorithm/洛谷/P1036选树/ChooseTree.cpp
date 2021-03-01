
#include<iostream>
using namespace std;
int ans=0,sum=0,x[25];
int n,k;
bool isprime(int n){
	int s = sqrt(double(n));
	for(int i=2;i<=s;i++){
		if(n%i==0)
		return false;
	}
	return true;
}
//void PL(int left_num,int alsum,int start,int end){
//	if(left_num==0){
//		if(isprime(alsum))
//		ans++;//递归直到所有数被选完,判断alsum总和是否为质数 
//	}
//	for(int j=start;j<=end;j++){
//		PL(left_num-1,alsum+x[j],j+1,end);
//	}	
//	
//}
//第二种写法::: 
int PL(int left_num,int alsum,int start,int end){
	if(left_num==0){
		return isprime(alsum);//返回1或0 
	}
	int sum=0;//sum置为0,因为进入循环外部的sum值会被内部的再利用,返回值又是sum
	 
	for(int j=start;j<=end;j++){
		sum+=PL(left_num-1,alsum+x[j],j+1,end);//1 2 3 4 5
	}
	return sum;//返回满足条件的总数 
	
}
int main(){

	cin>>n>>k;
	for(int t=1;t<=n;t++)//1-n总共n个数 
	cin>>x[t];
	cout<<PL(k,0,1,n);//从1开始,n结束
	
	return 0; 
}



#include<iostream>
using namespace std;
int b1,b2,b3,flag=0, k1,k2,k3;;
int a[10];
int ans=0;//分别对应1-9的个数 
int main(){
	cin>>k1>>k2>>k3;
	int big = 1000/k3;
	for(int b=1;b<=big;b++){
		b1=b*k1;
		b2=b*k2;
		b3=b*k3;
		if(b2>987||b3>987) break;
		
		for(int c=1;c<=3;c++){
			a[b1%10]++;
			b1/=10;
		} 
		for(int c=1;c<=3;c++){
		a[b2%10]++;
		b2/=10;
		} 
		
		for(int c=1;c<=3;c++){
		a[b3 %10]++;
		b3/=10;
		} 
		
		for(int d=1;d<=9;d++){
			if(a[d]!=1){
			flag = 1;
			break;
			}//有重复数字 
		}
		
		for(int c=1;c<=9;c++){
			a[c] = 0;
		}
		
		if(!flag){
			cout<<b*k1<<" "<<b*k2<<" "<<b*k3<<endl;
			ans++;
		}
		else flag = 0;//再次值为1,进行下一次循环 
		
		
		
	}
	if(!ans){
		cout<<"No!!!";
	}
	
	return 0;
	
}





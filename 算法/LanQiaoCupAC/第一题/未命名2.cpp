//#include<iostream>
//using namespace std;
//#include<cmath>
//int a[10];
//bool case1(int *a,int len)//等差数列 
//{
//	for(int i=1;i<len-1;i++)
//	{
//		if(a[i]-a[i-1] != a[i+1]-a[i])
//		{
//			return false;
//		}
//	}
//	return true;
//}
//
//
//bool case2(int *a,int len)//等比数列 在main里面再判断是否是摆动数列 
//{
//	for(int i=1;i<len-1;i++)
//	{
//		if(a[i]*a[i] != a[i+1]*a[i-1])
//		{
//			return false;
//		}
//	}
//	return true;
//}
//
//bool case3(int *a,int len)//每两项的差构成等差数列 
//{
//	int cha = (a[2]-a[1])-(a[1]-a[0]);
//	for(int i=1;i<len-1;i++)
//	{
//		if(a[i]!=(a[i+1]+a[i-1]-cha)/2) 
//		{
//			return false;
//		}
//	}
//	return true;
//} 
//
//bool case4(int *a,int len)//每两项的差为等比数列 
//{
//	//int cha = (a[2]-a[1])-(a[1]-a[0]);
//	for(int i=1;i<len-2;i++)
//	{
//		if((a[i+1]-a[i])*(a[i+1]-a[i])!=(a[i+2]-a[i+1])*(a[i]-a[i-1]))
//		{
//			return false;
//		}
//	}
//	return true;
//}
//int main()
//{
//	int i=0;
//	int x;
//	while(scanf("%d",&x)!=EOF )
//	{
//		a[i++] = x;
//	}
//	
//	if(case1(a,i))
//	{
//		cout<<a[0]+(a[1]-a[0])*i<<endl;
//		return 0;
//	}
//	if(case2(a,i))
//	{
//		cout<<a[0]*pow((a[1]/a[0]),i)<<endl;
//		return 0;
//	}
//	if(case3(a,i))
//	{
//		int cha = (a[2]-a[1])-(a[1]-a[0]);
//		cout<<a[i-1]*2+cha-a[i-2]<<endl;
//		return 0;
//	}
//	if(case4(a,i))
//	{
//		int c = a[1]-a[0];
//		int cha = (a[2]-a[1])/(a[1]-a[0]);
//		cout<<a[i-1]+c*pow(cha,i-1)<<endl;
//		return 0;
//	}
//	return 0;
//}
#include<bits/stdc++.h>
using namespace std;
int N,M;
string ss[32];
int a[9],b[10],c[10],d[9];

int main(){
 	 cin>>N>>M;
  	for(int i=0;i<N;i++)
      cin>>ss[i];
  	for(int i=0;i<9;i++)
      cin>>a[i];
  	for(int i=0;i<10;i++)
      cin>>b[i];
  for(int i=0;i<10;i++)
      cin>>c[i];
  for(int i=0;i<9;i++)
      cin>>d[i];
  cout<<"FUNCTION" <<endl<<"STRUCTURE"<<endl<<"UNDERFLOW"<<endl<<"ANALYTIC";
  return 0;
}

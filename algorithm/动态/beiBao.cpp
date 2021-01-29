#include<iostream>
#include<cstdio>
#include<algorithm>//背包问题,算法笔记445页,将二维数组将为一维数组(使用了滚动数组的思想)
using namespace std;
const int maxn = 100;
const int maxv = 1000;
int w[maxn],c[maxn],dp[maxv];
int main()
{   
    int n,V;
    cin>>n>>V;
    for(int i=0;i<n;i++)
    {
        cin>>w[i];
    }
    for(int i =0;i<n;i++){
        cin>>c[i];
    }
    for(int v=0;v<=V;v++){
        dp[v]= 0;
    }

    for(int i=1;i<=n;i++){
        for(int v=V;v>=w[i];v--){
            dp[v]=max(dp[v],dp[v-w[i]]+c[i]);
        }
    }
    cout<<dp[V];
    return 0;
}
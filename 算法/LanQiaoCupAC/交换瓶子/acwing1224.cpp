#include<bits/stdc++.h>
using namespace std;
int a[10001];
long long  ans=0;
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    
    for(int i=1;i<=n;i++){
        while(a[i]!=i){
            swap(a[i],a[a[i]]);
            ans++;
        }
    }
    cout<<ans;
    return 0;
}


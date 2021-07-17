#include<iostream>

#include <cmath>

using namespace std;

int x,k,A[10000];

bool win[10000];

void solve(){

    win[0]=false;

    for(int j=1;j<=x;j++){

         win[j]=false;
        for(int i =0;i<k;i++)

            win[j] |=A[i]<=j&&win[j-A[i]]; 
    }

    if(win[x]) puts("first");

     else puts("second");
}



int main(){

cin>>x;

cin>>k;

for(int i =1;i<=k;i++) A[i]=i;

solve();

}

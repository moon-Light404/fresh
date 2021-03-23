#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector<int> a{1,2,3};
    while(next_permutation(a.begin(),a.end()))
    {
         for(int i = 0;i<3;i++)
            cout<<a[i];
            cout<<endl;
    }
    
   
    return 0;
}
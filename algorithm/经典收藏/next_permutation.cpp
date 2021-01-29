#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector<int> a{1,2,3};
    next_permutation(a.begin(),a.end());//vector要用begin()等迭代器
    for(int i = 0;i<3;i++)
    cout<<a[i];
    return 0;
}
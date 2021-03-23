#include<iostream>
#include<algorithm>
using namespace std;
bool cmp(int a,int b)
{
    return a > b;
}
int main()
{
    int a[5] = {1,3,2,5,4};
    sort(a,a+5,cmp);
    for(int i = 0;i < 5;i++)
    cout << a[i]<< " ";
    return 0;
}
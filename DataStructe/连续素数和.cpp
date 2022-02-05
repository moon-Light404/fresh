/**
 * 给定一个正整数，表示一个或多个连续素数的和，写出有多少种这样的表示
 *
 */
#include<iostream>
#include<vector>
#define ll long long
using namespace std;
 
const ll N = 100000; // 100000以内的素数
int prime[N]; // 素数判断
int table[10000];// 素数表
void findPrime() { // 筛选非素数
    prime[1] = 1; // 1不是质数
    for(ll i = 2; i <= N;i++)
        if(prime[i] == 0) { // i是质数
            for(ll j = i * i; j <= N; j += i)
                prime[j] = 1;
        }
}
int main() {
    findPrime();
    int c = 0;
    for(int i = 1; i <= N;i++) {
       if(!prime[i]) {
           table[c++] = i;
       }
    }
    // for(int i = 0;i < c;i++)    cout << table[i] << " ";
    int t; // 要输入的数
    while (cin >> t && (t != 0)) {
        int cnt = 0; // 答案数初始化为0
        for(int i = 0; t >= table[i];i++) {
            int sum = 0; // 连续素数的和
            vector<int> a;
            a.clear(); // 清空数组
            for(int j = i; j < c && sum < t; j++) {
                sum += table[j];
                a.push_back(table[j]);
            }
                
            if(sum == t) {
                ++cnt; // 答案数 +1  
                for(vector<int> :: iterator iter = a.begin();iter!=a.end();iter++) {
                    cout << *iter;
                    if((iter + 1) != a.end())   cout << "+";
                }
                cout << endl;
            }     
        }
        cout <<"总数为：" << cnt << endl;
    }
    
    return 0;
}


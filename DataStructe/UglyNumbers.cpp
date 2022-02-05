/** 丑数
 */
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1e8;
int uglyNumber[1510]; // 丑数数组
int pos = 1;
int main() {
    for(int i = 1; i < N;i =i * 2) {
        for(int j = 1; i * j < N; j = j * 3) {
            for(int k = 1; i * j * k < N; k = k * 5) {
                uglyNumber[pos++] = i * j * k;     
            }    
        }
    }
    sort(uglyNumber,uglyNumber+pos);
    int n;
    while(cin >> n && n) {
        cout << uglyNumber[n];
    }
    return 0;
}
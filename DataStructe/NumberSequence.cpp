/**给出一个正整数i，编写一个程序，在数组序列S1S2...Sk中找到第i个位置的数字
 **/
#include<iostream>
#include<cmath>
using namespace std;
const int Maxn = 40000;
long long len[Maxn], sum[Maxn]; // 每段的长度和前i段的长度和
void init() {
    for(int i = 1;i < Maxn;i++) {
        len[i] = len[i-1] + (int)log10((double)i) + 1;
        sum[i] = sum[i-1] + len[i]; // 前i段分组的长度和
    }
}

int solve(int N) { // 第N个位置
    int i = 1;
    while(sum[i] < N)   i++;
    N = N - sum[i-1]; // 在第 i 组中的位置

    int len_k = 0, t;
    for(t = 1;len_k < N;t++) {
        len_k += (int) log10((double)t) + 1; // 从1~t数字计算长度
    }
    int pos = len_k - N;
    // 找到 t - 1 就是要找的数字，比较len_k是否超过了范围
    return (t - 1)/(int)(pow((double)10,pos)) % 10;
}
int main() {
    int T;
    cin >> T;
    init();
    while(T--) {
        int a;
        cin >> a;
        cout << solve(a) << endl;
    }
    return 0;
}
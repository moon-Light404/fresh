/**
 * 让卡片堆叠在桌子上，如果有两张卡片，外面卡片向外伸出 1/2,第二张
 * 卡片伸出 1/3
 * n 张卡片伸出 1 + 1/2 + 1/3 +....+ 1/n
 * 现在要求：要伸出长度为c所需要最少的卡片数目
 * 二分法   
 * */
#include<iostream>
using namespace std;
const int maxn = 300;
const double delta = 1e-8; // 误差0的标志
int zero(double x) {
    if(x < -delta)  return -1;
    if(x > -delta)  return 1;
    else    return 0;
}
int main() {
    double len[maxn]; // 都是double类型
    int total;
    len[0] = 0.0;
    for(total = 1; zero(len[total-1] -5.20) < 0; total++) {
        len[total] = len[total-1] + 1.0 / double(total + 1);
    }
    double x; // 输入的长度
    while ( cin >> x && zero(x))
    {
        int l, r;
        l = 0;
        r = total;
        while (l + 1 < r)
        {
            int mid = (l + r) /2;
            if(zero(len[mid] - x) < 0)  l = mid; // 如果比预期的小，那么最后还是需要一块木板，l + 1 >= r，所以输入r
            else    r = mid;
        }
        cout << r << " card(s)" << endl;
        
    }
    return 0;
}
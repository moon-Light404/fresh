/**
 * 切木棒，取一些相同的木棒随意切割，给出几段木棒的长度，求原先木棒最小
 * 可能的长度
 * */
#include<iostream>
#include<algorithm>
using namespace std;
int sticks[65];
int used[65];
int n, len;
bool dfs(int i,int l, int t) {
    if(l == 0) {
        t -= len;
        if(t == 0)  return true; // 所有木条都被切出来
        for(i = 0;used[i];i++);// 找到第一根还没切的木条
        used[i] = 1; // 切下木条i
        if(dfs(i+1,len-sticks[i],t))    return true; // 拼凑下一根木棒(分成若干木条)
        used[i] = 0, t+=len; // 恢复递归之前的参数
    }
    else { // 把剩余的len切完(把一根木棒正好切成一些小段)
        for(int j = i;j < n;j++) { // 按照长度递减的顺序来切--贪心
            if(j>0 && (sticks[j-1] == sticks[j] && !used[j-1])) continue; // 如果j-1和j相同长度，且都没有切成功(和凑不了len)，那就看下一条木棒

            if(!used[j] && l >= sticks[j]) { // 切下木条j
                l -= sticks[j]; used[j] = 1;
                if(dfs(j,l,t)) return true; // 若能切下剩下的木条，返回true
                l += sticks[j]; used[j] = 0; // 恢复递归之前的参数
                // if(sticks[j] == l) break; 
            }
        }
    }
    return false;
} 

bool cmp(const int a,const int b) {
    return a > b;
}

int main() {
    while(cin >> n && n) {
        int sum = 0;
        for(int i=0;i < n;i++) {
            cin >> sticks[i];
            sum += sticks[i];
            used[i] = 0;
        }
        sort(sticks,sticks+n,cmp); // 递减
        bool flag = false;

        for(len = sticks[0];len <= sum/2;++len) { // 区间[stick[0],sim/2]递增
            if(sum % len == 0) {
                if(dfs(0,len,sum)) { // 若长度为len的木棒刚好能切下n根木条
                    flag = true;
                    cout << len  << endl;
                    break;
                }
            }
        }
        if(!flag)   cout << sum << endl; // 总长度是len的倍数，当长度是sum/2的时候还不行，那木棒的长度就是所有木条的和
    }

    return 0;
}

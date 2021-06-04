#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 20;
int a[N];
//首先我们知道 如果 k == n ,那么就证明所有的数字是全部都选,
//             如果 k < n , 那么就要思考怎样去选择了:
//1.k 如果是偶数的话,选出来的结果一定是非负数 , 原因如下:
//             (1) # 负数的个数是偶数个的话,负负得正,那么一定是非负数
//             (2) # 负数的个数如果是奇数个的话,那么我们就只选偶数个绝对值最大的负数
//2.k 如果是奇数个的话,
//             (1)# 所有的数字如果都是负数,那么选出来的结果也一定都是负数
//             (2)# 否则的话,则一定至少有 1个非负数, 那么我们将最大的数取出来, 此时要选的个数就是 k--,
//                # k-- 是偶数,那么就又转化为 k-- 是偶数的情况思考

int main() {
	int time;
	cin >> time;
	while (time--) {
		int n, k;
		cin >> n >> k;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		sort(a, a + n);
		ll res = 1;
		int l = 0, r = n - 1;
		int sign = 1;
		if (k % 2) {
			res = a[r];
			r--;
			k--;
			if (res < 0 )
				sign = -1;
		}
		while (k) {
			ll x = (ll)a[l] * a[l + 1], y = (ll)a[r] * a[r - 1];
			if (x * sign > y * sign) {
				res = x * res;
				l += 2;
			} else {
				res = y * res;
				r -= 2;
			}
			k -= 2;
		}
		printf("%lld", res);
	}

	return 0;
}




#include<iostream>
#include<cstring>
using namespace std;
const int N = 20;
char g[N][N];
bool col[N]; // 该列是否被填过
bool u1[N], u2[N]; // 记录对角线和反对角线
int k; // k x K的方格
void dfs(int n)
{
    if(n == k) // 搜了k行
    {
        for(int i = 0; i < k;i++)   cout << g[i]  << endl;
        puts("");
        return;
    }
    
    for(int u = 0;u < k;u++) // 这里是搜索某一行的上的各列
    {
        if(!col[u] && !u1[u+n] && !u2[u-n+k-1]) // 对角线上的点的x，y坐标的性质
        {
           col[u] = true; // 标记该列
           g[n][u] = 'Q';
           u1[u+n] = true;
           u2[u-n+k-1] = true;
           dfs(n+1);
           // 恢复现场
           col[u] = false;
           u1[u+n]  =false;
           u2[u-n+k-1]=false;
           g[n][u]='.';
        }
    }
}
int main()
{
    cin >> k;
    for(int i = 0;i < k;i++)
        for(int j = 0; j < k;j++)
            g[i][j] = '.';
    dfs(0); // 第一行开始
    return 0;
}
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
int v[N], w[N]; // 体积和价值
int f[N][N]; // f[i][j], j体积下前i个物品的最大价值

int main() {
	int n, m;
	cin >> n >> m; // n件物品和背包容量m

	for (int i = 1; i <= n; i++)
		cin >> v[i] >> w[i];

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			if (j < v[i]) { // 如果背包容量比这件物品的体积还小
				f[i][j] = f[i - 1][j];
//				cout << i << ' ' << j << ' ' << f[i][j] << endl;
			} else
				f[i][j] = max(f[i - 1][j - v[i]] + w[i], f[i - 1][j]); // 状态转移方程
//			cout << i << ' ' << j << ' ' << f[i][j] << endl;
		}

	// f[i][j] 表示 体积为j下前i个物品的价值最大值
	cout << f[n][m] << endl;

	return 0;
}
#include <iostream>
using namespace std;
const int N = 110;
int w[N][N]; // 村珠宝数目
int n, f[N][N]; // 状态数组表示从坐标i,j 到山的底部的最大珠宝数

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			cin >> w[i][j];
	for (int i = 1; i <= n; i++) {
		f[n][i] = w[n][i];
	}

	for (int i = n - 1; i >= 1; i--) {
		for (int k = 1; k <= i; k++)
			f[i][k] = w[i][k] + max(f[i + 1][k], f[i + 1][k + 1]);
	}
	cout << f[1][1];
	return 0;
}
#include <iostream>
using namespace std;
const int N = 110;

int f[N]; // f[i][j]表示前i个金矿在不超过 j 个人的情况下可得的最大价值
int w[N], p[N]; // 金矿的情况价值和 人数,把人数当成体积，
int main() {
	int n, m; // n是人数，m金矿数目
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
		cin >> p[i] >> w[i];

	for (int i = 1; i <= m; i++)
		for (int j = n; j >= p[i]; j--) {
			f[j] = max(f[j - p[i]] + w[i], f[j]);
		}
	cout << f[n];
	return 0;
}
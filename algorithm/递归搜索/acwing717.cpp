#include <iostream>
using namespace std;
int n;
// 一、递归写法
/*
int fa[50]; // 先定义好每个数组，便于记录防止多余的重复计算

int dfs(int u) {

	if (u == 1)
		return 0;

	if (u == 2)
		return 1;

	if (fa[u]) {
		return fa[u]; // 如果fa[u]有初值则直接返回
	}

	fa[u] = dfs(u - 1) + dfs(u - 2);
	return fa[u];
}

int main() {
	fa[1] = 0;
	fa[2] = 1; // 先赋初值
	cin >> n;
	dfs(n);
	for (int i = 1; i <= n; i++) {
		printf("%d ", fa[i]);
	}

	return 0;
}
*/

// 二、迭代写法
/*
int main() {
	cin >> n;

	int f[46];
	f[1] = 0;
	f[2] = 1;
	for (int i = 3; i <= n; i++) {
		f[i] = f[i - 1] + f[i - 2];
	}

	for (int i = 1; i <= n; i++) {
		cout << f[i] << ' ';

	}
	return 0;
}
*/

// 三、滚动数组写法

int main() {
	cin >> n;
	int a = 0, b = 1;
	for (int i = 1; i <= n; i++) {
		cout << a << ' ';
		int fn = a + b;
		a = b, b = fn;
	}

	return 0;
}

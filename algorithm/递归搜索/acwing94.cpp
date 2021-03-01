#include <iostream>


using namespace std;

const int N = 10;
int n;
int vis[N]; // 判断这个数字是否访问过
int res[N]; // 存储可能的结果

void dfs(int u) { // u表示第几个位置
	if (u > n) {
		for (int i = 1; i <= n; i++) {
			printf("%d ", res[i]);
		}
		puts("");
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (!vis[i]) { // 遍历循环如果这个数字没有访问过，即没有占位置
			res[u] = i;
			vis[i] = true; // 标记为访问过
			dfs(u + 1);

			res[u] = 0;
			vis[i] = false; // 还原访问前的状态
		}
	}

}

int main() {
	cin >> n;
	dfs(1);

	return 0;
}
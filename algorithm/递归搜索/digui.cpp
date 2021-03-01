#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>
const int N = 16;
using namespace std;
int st[N]; //  为1表示选，2表示不选，0表示还未不做处理
int n;

void dfs(int u) {
	if (u > n) {
		for (int i = 1; i <= n; i++) {
			if (st[i] == 1) {
				printf("%d ", i);
			}
		}
		puts("");
		return;
	}

	st[u] = 1; // 选u这个数
	dfs(u + 1);
	st[u] = 0; // 恢复状态

	st[u] = 2; //  不选u
	dfs(u + 1);
	st[u] = 0; // 恢复状态


}

int main() {
	cin >> n;
	dfs(1);

	return 0;
}

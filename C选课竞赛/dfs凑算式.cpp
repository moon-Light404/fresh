#include <iostream>
using namespace std;
const int N = 10;
int s[N];
int cnt;
bool st[N]; // 标记状态数组

void dfs(int u) { // 枚举每一个位置
	// 递归边界,9个位置都已经枚举完了
	if (u > 9) {
		int a = s[1], b = s[2], c = s[3], def = s[4] * 100 + s[5] * 10 + s[6];
		int ghi = s[7] * 100 + s[8] * 10 + s[9];

		if (b * ghi + c * def == c * ghi * (10 - a))
			cnt++;
	}
	for (int i = 1; i <= 9; i++) {
		if (!st[i]) {
			st[i] = true;
			s[u] = i;
			dfs(u + 1); // 下一个位置

			// 恢复现场回溯
			s[u] = 0;
			st[i] = false;
		}
	}
}

int main() {
	dfs(1);
	cout << cnt << endl;
	return 0;
}
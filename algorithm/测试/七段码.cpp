#include <iostream>
using namespace std;
const int N = 8;
int mp[N][N];
int fa[N];
int ans;

bool vis[N]; // 标记是否被选过
int merge(int a) {
	if (fa[a] == a)
		return fa[a];
	else
		return fa[a] = merge(fa[a]);
}

void dfs(int n) {
	if (n > 7) {
		for (int i = 1; i <= 7; i++)
			fa[i] = i; // 并查集初始化

		for (int i = 1; i <= 7; i++) {
			for (int j = 1; j <= 7; j++) {
				if (vis[i] && vis[j] && mp[i][j]) { // 相邻的灯被选了将其合并一个集合
					int a = merge(i), b = merge(j);
					if (a != b)
						fa[a] = fa[b];
				}
			}
		}
		int k = 0; // 记录连通块
		for (int i = 1; i <= 7; i++) {
			if (vis[i] && fa[i] == i)
				k++;
		}
		if (k == 1)
			ans++;
		return;
	}
	// 不选
	vis[n] = false;
	dfs(n + 1);
	// 选
	vis[n] = true;
	dfs(n + 1);
	vis[n] = false;

}

int main() {
	mp[1][2] = mp[1][6] = 1;
	mp[2][1] = mp[2][3] = mp[2][7] = 1;
	mp[3][2] = mp[3][7] = mp[3][4] = 1;
	mp[4][3] = mp[4][5] = 1;
	mp[5][4] = mp[5][7] = 1;
	mp[6][5] = mp[6][7] = mp[6][1] = 1;

	dfs(1);
	cout << ans << endl;
	return 0;
}
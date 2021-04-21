
#include <stdio.h>
using namespace std;
int mp[110][110];
int ans[11000];
bool vis[110][110];
void dfs(int x, int y, int k) {
	if (mp[x][y] == '.')
		return;
	if (vis[x][y])
		return;
	vis[x][y] = 1;
	if (mp[x - 1][y] == '#' && mp[x + 1][y] == '#' && mp[x][y - 1] == '#' && mp[x][y + 1] == '#')
		ans[k]++;
	dfs(x + 1, y, k);
	dfs(x - 1, y, k);
	dfs(x, y - 1, k);
	dfs(x, y + 1, k);
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		getchar();
		for (int j = 1; j <= n; j++)
			scanf("%c", &mp[i][j]);

	}
	int len = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (mp[i][j] == '#' && !vis[i][j]) {
				dfs(i, j, len);
				len++;
			}
		}
	}
	int sum = 0;
	for (int i = 0; i < len; i++)
		if (ans[i] == 0)
			sum++;
	printf("%d\n", sum);
	return 0;
}

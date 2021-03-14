#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cstdio>
#define x first
#define y second
using namespace std;

const int N = 1010;
typedef pair<int, int> PII;
char g[N][N];


bool st[N][N]; // 标记是否遍历过的 数组


int dx[4] = {0, -1, 0, 1}, dy[4] = {-1, 0, 1, 0};
queue<PII> q; // 记录遍历陆地的队列
int n;

void bfs(int x, int y, int &total, int &bound) {
	q.push({x, y}); // 入队列
	st[x][y] = true; // 标记该位置访问过

	while (q.size()) {
		PII t = q.front(); // 取出队首元素
		total++; // 陆地像素加1
		q.pop(); // 出队
		bool is_bound = false;
		for (int i = 0; i < 4; i++) {

			int newx = t.x + dx[i], newy = t.y + dy[i]; // 记录新坐标
			if (newx < 0 || newx >= n || newy < 0 || newy >= n)
				continue;
			if (st[newx][newy])
				continue;
			if (g[newx][newy] == '.') { // 海洋像素
				is_bound = true;
				continue;
			}
			q.push({newx, newy}); // 入队
			st[newx][newy] = true;
		}
		if (is_bound)
			bound++;
	}
}

int main() {

	cin >> n;
	for (int i = 0; i < n; i++)
		scanf("%s", g[i]);

	int cnt = 0; // 记录被全部淹没的岛屿数量
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; i++) {
			if (!st[i][j] && g[i][j] == '#') { // 没有遍历过且是陆地
				int total  = 0, bound = 0;
				bfs(i, j, total, bound);
				if (total == bound)
					cnt++; // bound记录四周有海的陆地格子(即要被淹没的陆地格子)
			}
		}

	cout << cnt << endl;
	return 0;
}
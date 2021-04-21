#include <iostream>
#include <queue>
using namespace std;
const int N = 110;
char g[N][N];


bool st[N][N]; // 访问数组
int dx[4] = {-1, 0, 0, 1}, dy[4] = {0, 1, -1, 0};
int row;

struct Point {
	int x, y;
	int step;
};

bool bfs(int x, int y) {
	queue<Point> q;
	Point t1, t2;
	t1 = {x, y, 0};
	q.push(t1);
	st[x][y] = true; // 标记访问过
	while (q.size()) {
		t2 = q.front();
		q.pop();
		if (g[t2.x][t2.y] == 'B') {
			cout << t2.step;
			return true;
		}
		for (int i = 0; i < 4; i++) {
			int newx = t2.x + dx[i], newy = t2.y + dy[i];
			if (newx < 0 || newx >= row || newy < 0 || newy >= row)
				continue;
			if (st[newx][newy])
				continue;
			// 两步不能相同
			if (g[t2.x][t2.y] == g[newx][newy] )
				continue;

			Point t3 = {newx, newy, t2.step + 1};
			q.push(t3);
			st[newx][newy] = true;
		}
	}
	return false;
}


int main() {
	cin >> row;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < row; j++)
			cin >> g[i][j];
	bool flag = true;
	int sx, sy; // 开始的坐标
	for (int i = 0; i < row && flag; i++) {
		for (int j = 0; j < row; j++) {
			if (g[i][j] == 'A') {
				flag = false;
				sx = i, sy = j;
			}
		}
	}
	if (bfs(sx, sy) == false ) {
		cout << "-1";
	}
	return 0;
}
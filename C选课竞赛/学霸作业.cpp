#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int N = 110;
char g[N][N];
int n, m;

bool st[N][N]; // 访问数组
int dx[4] = {1, 0, 0, -1}, dy[4] = {0, -1, 1, 0};



char dir[4] = {'D', 'L', 'R', 'U'}; // 下，左，右，上
struct Point {
	int x, y;
	int foot; // 步数
	string path;
};

bool check(int x, int y) {
	if (x <= 0 || x > n || y <= 0 || y > m)
		return false;
	if (g[x][y] == '1')
		return false;
	if (st[x][y])
		return false;
	return true;
}

void bfs() {
	queue<Point> q;
	Point p1 = {1, 1, 0, ""};
	q.push(p1);
	st[1][1] = true;
	while (q.size()) {
		auto t = q.front();
		q.pop();
		if (t.x == n && t.y == m) {
			cout << t.foot << endl;
			for (int k = 0; k < t.path.length(); k++)
				cout << t.path[k];
		}
		for (int i = 0; i < 4; i++) { // 按照字典序来遍历四个方向
			int newx = t.x + dx[i], newy = t.y + dy[i];
			if (check(newx, newy)) {
				st[newx][newy] = true;
				t.path = t.path + dir[i];
				q.push({newx, newy, t.foot + 1, t.path});
			}
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> g[i] + 1;
	bfs();
	return 0;
}
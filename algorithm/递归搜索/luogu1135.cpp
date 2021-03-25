#include <iostream>
#include <queue>
using namespace std;
const int N = 205;
int f[N]; // 记录每一层的按钮
bool vis[N]; // 记录是否访问过
int n, s, e;

typedef struct {
	int d; // 楼层
	int pushcount ; // 到达该楼按按钮的次数
} layer;
queue<layer> q;

int BFS() {
	layer e1, e2;
	e1.d = s; // 起始楼层
	e1.pushcount = 0;
	q.push(e1);
	vis[s] = true;

	while (q.size()) {

		e2 = q.front();
		q.pop();
		if (e2.d == e) {
			return e2.pushcount;
		}
		// 向上走
		int k = e2.d + f[e2.d];
		if (k <= n && vis[k] == false) {
			e1.d = k;
			e1.pushcount = e2.pushcount + 1;
			q.push(e1);
			vis[k] = 1;
		}
		// 向下走

		k = e2.d - f[e2.d];
		if (k >= 1 && vis[k] == false) {
			e1.d = k;
			e1.pushcount = e2.pushcount + 1;
			q.push(e1);
			vis[k] = 1;
		}
	}

	return -1;
}


int main() {
	cin >> n >> s >> e; // 起点和终点
	for (int i = 1; i <= n; i++)
		cin >> f[i];
	int res = BFS();
	cout << res << endl;
	return 0;
}
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 510;
const int INF = 100000;
int g[N][N];
bool st[N];
int d[N];
int n, m;

void Dijkstra() {
	memset(d, INF, sizeof d);
	d[1] = 0; // 到自身距离为0
	for (int i = 0; i < n; i++) {
		int u = -1;
		for (int j = 1; j <= n; j++) {
			if ((u == -1 || d[j] < d[u]) && !st[j])
				u = j;
		}
		if (u == -1)
			return ;
		st[u] = true; // 访问该点

		for (int v = 1; v <= n; v++) {
			if (d[v] > d[u] + g[u][v] && g[u][v] != INF) {
				d[v] = d[u] + g[u][v];
				cout << u << " " << v << g[u][v] << endl;
				cout << "d[v]" << d[v] << endl;
				cout <<  "到达" << v << "点现在最短" << d[v] << endl;
			}
		}
	}
}

int main() {
	memset(g, INF, sizeof g);
	cin >> n >> m;
	int a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		g[a][b] = c;
	}
	Dijkstra();
	if (d[n] == INF)
		cout << "-1" << endl;
	else
		cout << d[n];
	return 0;
}
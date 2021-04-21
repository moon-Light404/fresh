//#include <iostream>



















//#include <cstring>
//using namespace std;
//const int N = 1000;
//int n, m;
//int dist[N], backup[N];
//
//struct Edge {
//	int a, b, w;
//
//} edges[N];
//
//void bellman_ford() { // 计算dist数组
//	memset(dist, 0x3f, sizeof dist);
//	dist[1] = 0;
//	for (int i = 0; i < n - 1; i++) {
//		memcpy(backup, dist, sizeof dist);
//		for (int j = 0; j < m; j++) {
//			int a = edges[j].a, b = edges[j].b, w = edges[j].w;
//			if (dist[b] > backup[a] + w) {
//				cout << "i:" << i + 1 << endl;
//				cout << a << b << endl;
//				dist[b] = backup[a] + w;
//			}
//
//		}
//	}
//
//}
//
//int main() {
//	n = 5, m = 4;
//	edges[0] = {1, 2, -3};
//	edges[1] = {2, 3, 2};
//	edges[2] = {3, 4, 3};
//	edges[3] = {4, 5, 2};
//	bellman_ford();
//	for (int i = 1; i <= 5; i++)
//		cout << dist[i] << endl;
//
//	return 0;
//}
#include <iostream>
#include <cstring>
using namespace std;
const int N = 1000;
int h[N], e[N], ne[N], idx;
bool st[N];

// 添加一条边a->b
void add(int a, int b) {
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

void dfs(int u) {
	st[u] = true;
	for (int i = h[u]; i != -1; i = ne[i]) {
		int j = e[i];
		if (!st[j]) {
			cout << j << endl;
			st[j] = true;
			dfs(j);
		}
	}
}

int main() {
	memset(h, -1, sizeof h);
	add(1, 2), add(1, 3), add(2, 4), add(4, 3);
	add(4, 1), add(5, 3), add(4, 5);
	dfs(1);
	return 0;
}
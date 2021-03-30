#include <iostream>
#include <cstring>
using namespace std;
const int N = 1010;
int h[N], e[N], ne[N], idx;
bool st[N];

// 添加一条边a->b
void add(int a, int b) {
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

//
//void dfs(int u) {
//	printf("%d\n", u);
//	st[u] = true;
//	for (int i = h[u]; i != -1; i = ne[i]) {
//		int j = e[i];
//		printf("%d\n", j);
//	}
//}


void dfs(int u) {
	st[u] = true; // st[u] 表示点u已经被遍历过

	for (int i = h[u]; i != -1; i = ne[i]) {
		int j = e[i];

		if (!st[j]) {
			printf("%d\n", j);
			dfs(j); // 继续递归
		}

	}
}


int main() {
	int n;
	memset(h, -1, sizeof h);
	cin >> n; // 设有n个点  1- n
	for (int i = 0; i < n - 1; i++) { // n - 1条边
		int a, b;
		scanf("%d%d", &a, &b);
		add(a, b), add(b, a);
	}
	dfs(1);
	return 0;
}
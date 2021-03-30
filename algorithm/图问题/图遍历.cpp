#include <iostream>
#include <cstring>
using namespace std;
const int N = 1010;
int h[N], e[N], ne[N], idx;
bool st[N];

// ���һ����a->b
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
	st[u] = true; // st[u] ��ʾ��u�Ѿ���������

	for (int i = h[u]; i != -1; i = ne[i]) {
		int j = e[i];

		if (!st[j]) {
			printf("%d\n", j);
			dfs(j); // �����ݹ�
		}

	}
}


int main() {
	int n;
	memset(h, -1, sizeof h);
	cin >> n; // ����n����  1- n
	for (int i = 0; i < n - 1; i++) { // n - 1����
		int a, b;
		scanf("%d%d", &a, &b);
		add(a, b), add(b, a);
	}
	dfs(1);
	return 0;
}
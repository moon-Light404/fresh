#include <iostream>
using namespace std;
int n;

const int N = 10;
int res[N];

void dfs(int u, int x, int c) { // u��ʾ�����±�λ��,x��ʾ��ǰ�ĺͣ�c��ʾ��ǰ��ʼ�������������Ҫ��ǰ��Ĵ��ڻ����
	if (x > n)
		return;

	if (x == n) {
		for (int i = 0; i < u; i++)
			cout << res[i] << ' ';
		cout << endl;
		return;
	}

	for (int i = c; i <= n; i++) {
		res[u] = i;
		dfs(u + 1, x + i, i);
	}
}

int main() {
	cin >> n;
	dfs(0, 0, 1);
	return 0;
}
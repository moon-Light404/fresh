#include <iostream>
using namespace std;
const int N = 10;
int s[N];
int cnt;
bool st[N]; // ���״̬����

void dfs(int u) { // ö��ÿһ��λ��
	// �ݹ�߽�,9��λ�ö��Ѿ�ö������
	if (u > 9) {
		int a = s[1], b = s[2], c = s[3], def = s[4] * 100 + s[5] * 10 + s[6];
		int ghi = s[7] * 100 + s[8] * 10 + s[9];

		if (b * ghi + c * def == c * ghi * (10 - a))
			cnt++;
	}
	for (int i = 1; i <= 9; i++) {
		if (!st[i]) {
			st[i] = true;
			s[u] = i;
			dfs(u + 1); // ��һ��λ��

			// �ָ��ֳ�����
			s[u] = 0;
			st[i] = false;
		}
	}
}

int main() {
	dfs(1);
	cout << cnt << endl;
	return 0;
}
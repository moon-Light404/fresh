#include <iostream>
using namespace std;
const int N = 10010;

bool st[N]; // ��¼��û�б�ɸ��
int prime[N]; // ��¼����
int cnt; // ����
int main() {
	int n;
	cin >> n;
	for (int i = 2; i <= n; i++) { // O(n)����
		if (!st[i])
			prime[cnt++] = i;
		for (int  j = 0; prime[j] * i <= n; j++) {
			st[prime[j] * i] = true;
			if (i % prime[j] == 0) { // һ��Ҫ����С��������ɸ��
				break;
			}

		}
	}
	for (int i = 0; i < cnt; i++)
		cout << prime[i] << " ";
	return 0;
}
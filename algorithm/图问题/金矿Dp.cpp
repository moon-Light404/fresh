#include <iostream>
using namespace std;
const int N = 110;

int f[N]; // f[i][j]��ʾǰi������ڲ����� j ���˵�����¿ɵõ�����ֵ
int w[N], p[N]; // ���������ֵ�� ����,���������������
int main() {
	int n, m; // n��������m�����Ŀ
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
		cin >> p[i] >> w[i];

	for (int i = 1; i <= m; i++)
		for (int j = n; j >= p[i]; j--) {
			f[j] = max(f[j - p[i]] + w[i], f[j]);
		}
	cout << f[n];
	return 0;
}
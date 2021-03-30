#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 105;
int f[N][N]; // f[i][j]��ʾ��ǰi����Ʒ��ѡ���ܺͳ���k��������j,��������ֵ
int w[N]; // �ǹ���
// f[i][j] = f[i - 1][j] , f[i - 1][(j-w + n)%n] + w
// ѡ�벻ѡ֮�֣�ѡ�Ļ���ôǰi-1����Ʒ + �� i ����Ʒw ������������ ����Ϊ(j-w+n)%n
int main() {
	int m, n;
	cin >> m >> n; // n ������
	memset(f, -0x3f, sizeof f);
	f[0][0] = 0; // f�����ʾ����ֵ
	// f[0][i]�����������,�����ʼ��Ϊ0�Ļ�����᲻��ȷ
	for (int i = 1; i <= m; i++)
		cin >> w[i];

	for (int i = 1; i <= m; i++)
		for (int j = 0; j < n; j++) {
			cout << "������ǰ������Ʒ��" << i << endl;
			cout << "���ڵ�����Ϊ:" << j << endl;
			f[i][j] = max(f[i - 1][j], f[i - 1][(j - w[i] % n + n) % n] + w[i]);
			cout << "����Ӧ��Ϊ:" << (j - w[i] % n + n) % n << endl;
			cout << "ǰ" << i << "����������������Ϊ" << j << "�����ֵ" << f[i][j] << endl;
			cout << endl;
		}
	cout << f[m][0];
	return 0;
}
#include <iostream>
using namespace std;
int len = 1, f[5003][5003];

void fp(int k) {
	for (int i = 1; i <= len; i++)
		f[k][i] = f[k - 1][i] + f[k - 2][i]; //����Ӧ��λ��������(ÿһλ�������)

	for (int i = 1; i <= len; i++) { //len��ʾ���ݵ�λ������Ӧ�� i ҲҪ������
		if (f[k][i] >= 10) {
			f[k][i + 1] += f[k][i] / 10;
			f[k][i] = f[k][i] % 10; //��λ�����ߣ�

			if (f[k][len + 1])
				len++;//���ֳ��ȼ�1

		}
	}
}

int main() {
	int a;
	cin >> a;
	f[1][1] = 1;
	f[2][1] = 2;
	for (int i = 3; i <= a; i++)
		fp(i); //�ӵ�λ����λ������ѭ��

	for (int i = len; i >= 1; i--) { //�������
		cout << f[a][i];
	}
	return 0;
}

#include <iostream>
using namespace std;

const int N = 19; // 0-18
int a[N] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6}; // 0-9ÿ��������Ҫ�Ļ������
// �Ӻź͵Ⱥ������ĸ����,

int fun(int x) { // ����ĳ����Ҫ���ٻ��
	int num = 0;
	while (x / 10 != 0) {
		num += a[x % 10];
		x = x / 10;
	}
	num += a[x];
	return num;
}

int main() {
	int n, x, sum = 0; // �������
	cin >> n;
	n = n - 4; // ��ȥ�Ӻź͵Ⱥ�
	for (int i = 0; i <= 1111; i++)
		for (int j = i; j <= 1111; j++) {
			int x = i + j;
			if (fun(i) + fun(j) + fun(x) == n) {
				if (i == j)
					sum += 1;
				else
					sum += 2;
			}
		}
	cout << sum;
	return 0;
}
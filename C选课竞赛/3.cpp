#include <iostream>
using namespace std;

const int N = 19; // 0-18
int a[N] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6}; // 0-9每个数字需要的火柴数量
// 加号和等号用了四根火柴,

int fun(int x) { // 计算某个数要多少火柴
	int num = 0;
	while (x / 10 != 0) {
		num += a[x % 10];
		x = x / 10;
	}
	num += a[x];
	return num;
}

int main() {
	int n, x, sum = 0; // 火柴数量
	cin >> n;
	n = n - 4; // 除去加号和等号
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
#include <iostream>
using namespace std;
int len = 1, f[5003][5003];

void fp(int k) {
	for (int i = 1; i <= len; i++)
		f[k][i] = f[k - 1][i] + f[k - 2][i]; //各对应的位置相加求和(每一位互相相加)

	for (int i = 1; i <= len; i++) { //len表示数据的位数，相应的 i 也要用起来
		if (f[k][i] >= 10) {
			f[k][i + 1] += f[k][i] / 10;
			f[k][i] = f[k][i] % 10; //高位往下走，

			if (f[k][len + 1])
				len++;//数字长度加1

		}
	}
}

int main() {
	int a;
	cin >> a;
	f[1][1] = 1;
	f[2][1] = 2;
	for (int i = 3; i <= a; i++)
		fp(i); //从低位到高位，依次循环

	for (int i = len; i >= 1; i--) { //逆序输出
		cout << f[a][i];
	}
	return 0;
}

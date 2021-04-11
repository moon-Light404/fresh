#include <iostream>
using namespace std;
const int N = 110;

int a[N], d[N]; // d[i]表示以a[i]结尾的子段中的最大连续和
// 因为它没有限制长度(任意长度都行)，无非就是判断会不会有负数
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	d[1] = a[1];
	for (int i = 2; i <= n; i++) {
		if (d[i - 1] > 0)
			d[i] = d[i - 1] + a[i];
		else
			d[i] = a[i]; // 前面的都是负数，直接丢弃
	}
	cout << d[n];
	return 0;
}
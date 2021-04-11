// 大整数高精度算法c++写法
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

struct bign {
	int d[1000];
	int len;
	bign() {
		memset(d, 0, sizeof d);
		len = 0;
	}
};

bign change(string str) {
	bign a;
	a.len = str.length(); // 数字长度
	for (int i = 0; i < a.len; i++) {
		a.d[i] = str[a.len - i - 1] - '0';
	}
	return a;
}

bign add(bign a, bign b) {
	bign c;
	int carry = 0; // 进位
	for (int i = 0; i < a.len || i < b.len; i++) {
		int tmp = a.d[i] + b.d[i] + carry;
		c.d[c.len++] = tmp % 10;
		carry = tmp / 10;
	}
	if (carry != 0) {
		c.d[c.len++] = carry;
	}

	return c;
}

int main() {
	string s1, s2;
	cin >> s1 >> s2;
	bign a = change(s1);
	bign b = change(s2);
	bign res = add(a, b);
	cout << "结果是" << endl;
	for (int i = res.len - 1; i >= 0; i--) {

		cout << res.d[i];
	}
	return 0;
}
#include <iostream>
#include <cstring>
using namespace std;

void f(int i, int sum, string str, int remain) { // 要操作的数, 和 ,当前字符串
	if (i == 10) {
		if (sum == 110 && (!remain) && (str[0] != '-')) {
			if (str[0] == '+')
				cout << &str[1] << endl;
			else
				cout << str << endl;
		}
		return;
	}
	if (remain) {
		if (remain > 0) {
			f(i + 1, sum + 10 * remain + i, str + char('0' + i), 0); //杀鸡取卵
			f(i + 1, sum, str + char('0' + i), 10 * remain + i); //继续叠加
		} else {
			f(i + 1, sum + 10 * remain - i, str + char('0' + i), 0); //杀鸡取卵
			f(i + 1, sum, str + char('0' + i), 10 * remain - i); //继续叠加
		}

	} else {
		f(i + 1, sum + i, str + "+" + char('0' + i), 0);
		f(i + 1, sum - i, str + "-" + char('0' + i), 0);
		f(i + 1, sum, str + "+" + char('0' + i), i); // 前面不添加符号，留下了i
		f(i + 1, sum, str + "-" + char('0' + i), -i);
	}
}

int main() {
	f(1, 0, "", 0);
	return 0;
}

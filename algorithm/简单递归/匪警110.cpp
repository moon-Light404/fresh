#include <iostream>
#include <cstring>
using namespace std;

void f(int i, int sum, string str, int remain) { // Ҫ��������, �� ,��ǰ�ַ���
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
			f(i + 1, sum + 10 * remain + i, str + char('0' + i), 0); //ɱ��ȡ��
			f(i + 1, sum, str + char('0' + i), 10 * remain + i); //��������
		} else {
			f(i + 1, sum + 10 * remain - i, str + char('0' + i), 0); //ɱ��ȡ��
			f(i + 1, sum, str + char('0' + i), 10 * remain - i); //��������
		}

	} else {
		f(i + 1, sum + i, str + "+" + char('0' + i), 0);
		f(i + 1, sum - i, str + "-" + char('0' + i), 0);
		f(i + 1, sum, str + "+" + char('0' + i), i); // ǰ�治��ӷ��ţ�������i
		f(i + 1, sum, str + "-" + char('0' + i), -i);
	}
}

int main() {
	f(1, 0, "", 0);
	return 0;
}

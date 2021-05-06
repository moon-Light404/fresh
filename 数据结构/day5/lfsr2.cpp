#include <bitset>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
string startNum = "001100010"; // 初始序列 8到0
string result = "";

vector<string> sequ;

bitset<9> foo(startNum); // 0-8九位二进制串
int i = 1;
int cycle = 0; // 开始循环的行数 次数
int find_pos(string s) {
	int k = 1;
	vector<string>::iterator it = sequ.begin();
	for (; it != sequ.end(); it++) {
		if (*it == s)
			return k;
		k++;
	}
	return 0;
}

void Find() {
	while (1) {
		cout << foo << "\t" << foo[0] << "\t" << i << endl;
		int k =  foo[1] ^ foo[5] ^ foo[6];
		if (foo.test(0)) { // 输出b1的值
			result += '1';
		} else {
			result += '0';
		}
		foo >>= 1;
		if (k & 1) { // 把表达式结果放到最高位
			foo.set(8); // 最高位
		} else if (!(k & 1)) {
			foo.reset(8); // 最高位
		}
		if (count(sequ.begin(), sequ.end(), foo.to_string()) == 1) { // 找到重复状态了
			cycle = find_pos(foo.to_string());
			break;
		} else
			sequ.push_back(foo.to_string());
		i++;
	}
}

int main() {
	sequ.push_back(startNum);
	cout << "当前序列" << "\t"  << "输出" << "\t" << "次数" << endl;
	cout << foo << "\t" << foo[0] << "\t" << i << endl;
	i++;
	int k = foo[1] ^ foo[5] ^ foo[6];
	if (foo.test(0)) { // 输出b1的值
		result += '1';
	} else {
		result += '0';
	}
	foo >>= 1;
	if (k & 1) { // 把表达式结果放到最高位
		foo.set(8); // 最高位
	} else if (!(k & 1)) {
		foo.reset(8); // 最高位
	}
	sequ.push_back(foo.to_string());
	Find();
	cout << "==================================" << endl;
	cout << "开始循环的次数:" << cycle << endl;
	cout << "下次循环的次数:" << sequ.size() + 1 << endl;
	cout << "结果序列为:" << result;
	return 0;
}

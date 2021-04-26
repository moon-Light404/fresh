#include <bitset>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
string startNum = "001100100"; // 初始序列 8到0
string result = "";

vector<string> sequ;
bitset<9> foo(startNum); // 0-8九位二进制串
int main() {
	sequ.push_back(startNum);
	cout << "当前序列" << "\t"  << "输出" << "\t" << "次数" << endl;
	for (int i = 1; i <= 20; i++) {
		cout << foo << "\t" << foo[0] << "\t" << i << endl;
		int k = foo[2] ^ foo[5] ^ foo[6];
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
	}
	return 0;
}
#include <bitset>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
string startNum = "001100100"; // ��ʼ���� 8��0
string result = "";

vector<string> sequ;
bitset<9> foo(startNum); // 0-8��λ�����ƴ�
int main() {
	sequ.push_back(startNum);
	cout << "��ǰ����" << "\t"  << "���" << "\t" << "����" << endl;
	for (int i = 1; i <= 20; i++) {
		cout << foo << "\t" << foo[0] << "\t" << i << endl;
		int k = foo[2] ^ foo[5] ^ foo[6];
		if (foo.test(0)) { // ���b1��ֵ
			result += '1';
		} else {
			result += '0';
		}
		foo >>= 1;
		if (k & 1) { // �ѱ��ʽ����ŵ����λ
			foo.set(8); // ���λ
		} else if (!(k & 1)) {
			foo.reset(8); // ���λ
		}
		sequ.push_back(foo.to_string());
	}
	return 0;
}
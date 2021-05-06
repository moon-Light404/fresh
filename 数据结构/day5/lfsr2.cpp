#include <bitset>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
string startNum = "001100010"; // ��ʼ���� 8��0
string result = "";

vector<string> sequ;

bitset<9> foo(startNum); // 0-8��λ�����ƴ�
int i = 1;
int cycle = 0; // ��ʼѭ�������� ����
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
		if (count(sequ.begin(), sequ.end(), foo.to_string()) == 1) { // �ҵ��ظ�״̬��
			cycle = find_pos(foo.to_string());
			break;
		} else
			sequ.push_back(foo.to_string());
		i++;
	}
}

int main() {
	sequ.push_back(startNum);
	cout << "��ǰ����" << "\t"  << "���" << "\t" << "����" << endl;
	cout << foo << "\t" << foo[0] << "\t" << i << endl;
	i++;
	int k = foo[1] ^ foo[5] ^ foo[6];
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
	Find();
	cout << "==================================" << endl;
	cout << "��ʼѭ���Ĵ���:" << cycle << endl;
	cout << "�´�ѭ���Ĵ���:" << sequ.size() + 1 << endl;
	cout << "�������Ϊ:" << result;
	return 0;
}

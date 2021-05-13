#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
const int s = 1000, e = 8999;
int n;
vector<int> arr;

int month[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

bool check(int yy, int mm, int dd) {//�Ƿ��������ڸ�ʽ
	if (mm >= 1 && mm <= 12) {
		if (yy % 400 == 0 || (yy % 4 == 0 && yy % 100 != 0))
			month[2] = 29;

		if (month[mm] >= dd)
			return true;
		else
			return false;
	}
	return false;
}

void init() {//Ԥ�����������
	for (int i = s; i <= e; i++) {
		string s = to_string(i);//תstring

		for (int j = 3; j >= 0; j--)
			s += s[j];

		int mm = (s[4] - '0') * 10 + (s[5] - '0'); //��
		int dd = (s[6] - '0') * 10 + (s[7] - '0'); //��

		if (check(i, mm, dd)) {
			int k = stoi(s);//תint
			arr.push_back(k);//���ĵ�����ͳһ������
		}
		month[2] = 28;

	}
}

//
//int upper_bound(int key) {//�ҵ���һ���������Ļ�������
//	int l, r, mid;
//	l = 0, r = arr.size() - 1;
//	while (l < r) {
//		mid = l + r  >> 1;
//
//		if (arr[mid] > key)
//			r = mid ;
//		else
//			l = mid + 1;
//	}
//	return l;
//}







int ababbaba(int index) {//Ѱ������ ababbaba ��ʽ�Ļ�������
	for (int i = index; i < arr.size(); i++) {
		string s = to_string(arr[i]);

		if (s[0] == s[2] && s[1] == s[3])
			return i;
	}
	return 0;
}

int main() {
	int n;
	cin >> n;
	init();

	int index = upper_bound(arr.begin(), arr.end(), n) - arr.begin();

	cout << arr[index] << '\n';

	index = ababbaba(index);
	cout << arr[index];
	return 0;
}

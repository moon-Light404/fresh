#include <iostream>
using namespace std;
const int N = 10;
int cnt[N];

bool check(int num) { // num�Ƿ���ƴ����
	while (num) {
		int x = num % 10; // ȡ��λ
		cnt[x]--; // x��Ƭ��ȥ1
		if (cnt[x] < 0)
			return false;
		num /= 10;
	}
	return true; // ��ƴ����
}

int main() {
	for (int i = 0; i < 10; i++)
		cnt[i] = 2021; // ����i�Ŀ�Ƭ��������2021

	int j = 1;
	while (1) {
		if (check(j)) {
			j++;
		} else
			break;
	}
	cout << j - 1 ;
	return 0;
}
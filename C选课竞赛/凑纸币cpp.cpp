// ��ֽ��̰���㷨,�ȴ�������ֵ��Ǯ
#include <iostream>
using namespace std;
const int N = 110;

int slary[N]; // Ա������
int RMB[6] = {100, 50, 10, 5, 2, 1};

int n; // ����
int moneyNum(int m) { // �ճ�m������Ҫ�����������
	int cnt = 0; // ��¼����
	for (int i = 0; i < 6; i++) {
		if (m % RMB[i] == 0) {
			cnt += m / RMB[i];
			break;
		} else {
			cnt += m / RMB[i];
			m %= RMB[i];
		}
	}
	return cnt;
}

int main() {
	int sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> slary[i];
		sum += moneyNum(slary[i]);
	}
	cout << sum;
	return 0;
}
#include <iostream>
using namespace std;
const int N = 2000;
int prime[N], total = 0;

bool isprime(int k) {
	for (int i = 0; i < total; i++) {
		if (k % prime[i] == 0) {
			return false;
		}
	}
	return true;
}

// ÿһ���������Էֽ�������
int main() {
	int n = 10000;
	for (int i = 2; i <= n; i++)  { // ��2��ʼ��������
		if (isprime(i)) {
			prime[total++] = i;
			cout << i << " ";
		}
	}
	return 0;
}
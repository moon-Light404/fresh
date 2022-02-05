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

// 每一个合数可以分解质因数
int main() {
	int n = 10000;
	for (int i = 2; i <= n; i++)  { // 从2开始遍历数字
		if (isprime(i)) {
			prime[total++] = i;
			cout << i << " ";
		}
	}
	return 0;
}
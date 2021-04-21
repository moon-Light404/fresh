#include <iostream>
using namespace std;
const int N = 10010;

bool st[N]; // 记录有没有被筛过
int prime[N]; // 记录素数
int cnt; // 计数
int main() {
	int n;
	cin >> n;
	for (int i = 2; i <= n; i++) { // O(n)遍历
		if (!st[i])
			prime[cnt++] = i;
		for (int  j = 0; prime[j] * i <= n; j++) {
			st[prime[j] * i] = true;
			if (i % prime[j] == 0) { // 一定要由最小质因子来筛数
				break;
			}

		}
	}
	for (int i = 0; i < cnt; i++)
		cout << prime[i] << " ";
	return 0;
}
// 凑纸币贪心算法,先凑最大的面值的钱
#include <iostream>
using namespace std;
const int N = 110;

int slary[N]; // 员工工资
int RMB[6] = {100, 50, 10, 5, 2, 1};

int n; // 人数
int moneyNum(int m) { // 凑成m至少需要多少张人民币
	int cnt = 0; // 记录数量
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
#include <iostream>
using namespace std;
const int N = 10;
int cnt[N];

bool check(int num) { // num是否能拼出来
	while (num) {
		int x = num % 10; // 取个位
		cnt[x]--; // x卡片减去1
		if (cnt[x] < 0)
			return false;
		num /= 10;
	}
	return true; // 能拼出来
}

int main() {
	for (int i = 0; i < 10; i++)
		cnt[i] = 2021; // 数字i的卡片数量都是2021

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
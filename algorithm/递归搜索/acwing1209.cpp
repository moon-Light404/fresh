#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 10;
int n;
bool st[N], backup[N]; // 判重数组，1表示用了，0表示没用过
int ans;

bool check(int a, int c) {
	long long b = n * (long long)c - a * c;
	cout << "现在 a b c 的值分别为" << a << ' ' << c << ' ' << b << ' ' << endl;
	if (!a || !b || !c)
		return false;

	memcpy(backup, st, sizeof st); // 将判重数组拷贝一份
	//防止干扰a和c进行拆分，也便于下面对a b c 进行
	//查重
	while (b) {
		int x = b % 10;
		b /= 10;
		if (!x || backup[x])
			return false;// 这个数在a和c中已经出现过
		backup[x] = true; // 记录该数字出现过
	}

	for (int i = 1; i <= 9; i++) {
		if (!backup[i]) { // 确保1-9都出现了
			return false;
		}
	}
	return true; // 如果上面都不成立则表示符合题意

}

void dfs_c(int a, int c) { // 传入a的值，c当前的值
	if (check(a, c))
		ans++;

	for (int i = 1; i <= 9; i++) {
		if (!st[i]) {
			st[i] = true;
			dfs_c(a, c * 10 + i); // a此时的值固定，循环查找c的值

			st[i] = false;
		}
	}
}

void dfs_a(int a) {
	if (a >= n)
		return;
	if (a)
		dfs_c(a, 0); // 把当前a的值传进函数中，因为dfs_c
	//函数中有check(a,c)函数需要a的值

	for (int i = 1; i <= 9; i++) {
		if (!st[i]) {
			st[i] = true;
			dfs_a(a * 10 + i); // 传入a当前的值
			st[i] = false; // 恢复初状态
		}
	}
}

int main() {
	cin >> n;

	dfs_a(0);  // a的初值为0

	cout << ans << endl;

	return 0;
}


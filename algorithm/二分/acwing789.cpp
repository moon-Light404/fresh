#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int N  = 100010;
int g[N];

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &g[i]);

	for (int i = 0; i < m; i++) {
		int x;
		scanf("%d", &x); // 输入要查找的数

		int l = 0, r = n - 1; // 左右端点
		// 二分求左端点找 >=x 的第一个位置
		while (l < r) {
			cout << "----进入循环" << endl;
			cout << "现在l的值为" << l << endl;
			cout << "现在r的值为" << r << endl;
			int mid = l + r >> 1; // 除以2
			if (g[mid] >= x) {

				r = mid; // 注意r一直等于mid
				cout << "现在r的值为" << r << endl;
			} else {
				l = mid + 1;
				cout << "现在l的值为" << l << endl;
			}

		}

		if (g[r] == x) {
			cout << r << ' ';
			r = n - 1; // l可以不变，因为l在左端点
			// 二分找右端点 <= x 的第一个位置
			while (l < r) {
				cout << "----进入循环" << endl;
				cout << "现在l的值为" << l << endl;
				cout << "现在r的值为" << r << endl;
				int mid = l + r + 1 >> 1;
				if (g[mid] <= x) {

					l = mid; // 这时是l一直等于mid
					cout << "现在l的值为" << l << endl;
				}

				else {

					r = mid - 1;
					cout << "现在r的值为" << r << endl;
				}
			}
			cout << l << endl;
		} else
			cout << "-1 -1" << endl;

	}
	return 0;
}
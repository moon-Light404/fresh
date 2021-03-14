#include <iostream>
#include <cstdio>
using namespace std;

const int N = 10010;
int a[N], st[N]; // st数组用来计算有多少个环的
int n, cnt; // cnt是环数目的结果
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}

	for (int i = 1; i <= n; i++) {
		if (!st[i]) { // 当前元素未被标记
			cnt++;
//			st[i] = true;
			cout << cnt << endl;

			// 把所有环内的数标记完
			for (int j = i; !st[j]; j = a[j]) { // 一个箭头指向另一个箭头直到一个环内所以数都被标记为止
				st[j] = true;
			}
		}
	}

	printf("%d\n", n - cnt);
	return 0;
}
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int mylower_bound(int a[], int key) { // 找到第一个不大于x的数(<=)
	int l, r, mid;
	l = 0, r = 9;
	while (l < r) {
		mid = l + r + 1 >> 1;
		if (a[mid] <= key)
			l = mid;
		else
			r = mid - 1;

	}
	return l;
}

int main() {
	int a[10] = {1, 2, 4, 5, 6, 6, 6, 8, 10, 12};
	cout << mylower_bound(a, 6) << endl;
	return 0;
}


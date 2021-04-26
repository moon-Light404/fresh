#include "ArrayIo.h"
#include <iostream>
using namespace std;

int max(int a[], int left, int right) {
	int mid, l, r;
	if (left == right)
		return a[left];
	else {
		mid = (left + right) / 2;
		l = max(a, left, mid); // 左区间的最大值
		r = max(a, mid + 1, right); // 右区间的最大值
		return l > r ? l : r;

	}

}

int main() {
	int a[10];
	input(a, 10);
	print(a, 10);
	printf("数组的最大数是:%d\n", max(a, 0, 9));
	return 0;
}
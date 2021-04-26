#include "ArrayIo.h"
#include <iostream>
using namespace std;

int max(int a[], int left, int right) {
	int mid, l, r;
	if (left == right)
		return a[left];
	else {
		mid = (left + right) / 2;
		l = max(a, left, mid); // ����������ֵ
		r = max(a, mid + 1, right); // ����������ֵ
		return l > r ? l : r;

	}

}

int main() {
	int a[10];
	input(a, 10);
	print(a, 10);
	printf("������������:%d\n", max(a, 0, 9));
	return 0;
}
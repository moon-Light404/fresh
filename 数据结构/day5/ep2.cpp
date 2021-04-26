#include "ArrayIo.h"
#define N 10

// 左边找偶数,右边找奇数
void partion(int a[], int left, int right) {
	int temp;
	while (left < right) {
		while (left < right && a[left] % 2 == 1)
			left++;
		while (left < right && a[right] % 2 == 0)
			right--;
		if (left < right) { // 此时lefthe right下标对应的数分别是偶数和奇数
			temp = a[left];
			a[left] = a[right];
			a[right] = temp;

			partion(a, left + 1, right - 1);
		}
	}
}

int main() {
	int a[N];
	init(a, N);
	print(a, N);
	partion(a, 0, N - 1);
	print(a, N);
}
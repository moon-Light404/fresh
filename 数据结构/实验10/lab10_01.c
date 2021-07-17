#include "ArrayIo.h"
#include <time.h>
#define N 50000

void insertSort(int a[], int n) {
	int i, j;
	for (i = 2; i <= n; i++) {
		a[0] = a[i]; // a[0]不存储数据，只做临时数据用来比较
		j = i - 1;
		// 让j往左移动
		while ( a[j] > a[0]) {
			a[j + 1] = a[j]; // 大于a[0]的数不断向右移动，腾出空位
			j--;
		}
		// 因为上面最后面j减去了1，所以要加回来
		a[j + 1] = a[0];
	}
}

int main() {
	clock_t start, finish;
	start = clock();
	int a[N + 1], n;
	printf("数据初始化...\n");
	n = readData(a, N, "data1.txt");
	printf("%d个数据排序中...\n", n);
	insertSort(a, n);
	saveData(a, n, "out.txt");
	printf("排序结束,排序结果保存在out.txt文件中\n");
	finish = clock();
	double d = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("the time cost is %lf\n", d);
	return 0;
}

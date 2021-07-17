#include "Arrayio.h"
#include <time.h>
#define N 100000     /*N为数据量大小，因data1.txt中只有50万个数，所以自行设定N值时需让N<=500000*/

/*请将本函数补充完整，并进行测试*/
void binInsertSort(int a[], int n) {
	int mid, left, right, i, j;
	for (i = 2; i <= n; i++) {
		left = 1;
		right = i - 1;
		while (left <= right) {
			mid = (left + right) / 2;
			if (a[i] < a[mid])
				right = mid - 1;
			else
				left = mid + 1;
		}
		//插入的位置是left
		a[0] = a[i];
		for (j = i - 1; j >= left; j--)
			a[j + 1] = a[j];
		a[left] = a[0];
	}

}

int  main() {
	clock_t start, finish;
	start = clock();
	int a[N + 1], n;                  /*数据存储在a[1]...a[N]中*/
	printf("数据初始化...\n");
	n = readData(a, N, "data1.txt");  /*从data1.txt中读入N个整数存入数组a，n为实际读入的数据个数*/
	printf("%d个数据排序中...\n", n);
	binInsertSort(a, n);
	saveData(a, n, "out.txt");        /*排序结果存放在out.txt文件中*/
	printf("排序结束，排序结果保存在out.txt文件中。\n");
	finish = clock();
	double d = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("the time cost is %lf\n", d);
	return 0;
}

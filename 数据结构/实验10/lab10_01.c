#include "ArrayIo.h"
#include <time.h>
#define N 50000

void insertSort(int a[], int n) {
	int i, j;
	for (i = 2; i <= n; i++) {
		a[0] = a[i]; // a[0]���洢���ݣ�ֻ����ʱ���������Ƚ�
		j = i - 1;
		// ��j�����ƶ�
		while ( a[j] > a[0]) {
			a[j + 1] = a[j]; // ����a[0]�������������ƶ����ڳ���λ
			j--;
		}
		// ��Ϊ���������j��ȥ��1������Ҫ�ӻ���
		a[j + 1] = a[0];
	}
}

int main() {
	clock_t start, finish;
	start = clock();
	int a[N + 1], n;
	printf("���ݳ�ʼ��...\n");
	n = readData(a, N, "data1.txt");
	printf("%d������������...\n", n);
	insertSort(a, n);
	saveData(a, n, "out.txt");
	printf("�������,������������out.txt�ļ���\n");
	finish = clock();
	double d = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("the time cost is %lf\n", d);
	return 0;
}

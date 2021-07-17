#include "Arrayio.h"
#include <time.h>
#define N 100000     /*NΪ��������С����data1.txt��ֻ��50����������������趨Nֵʱ����N<=500000*/

/*�뽫���������������������в���*/
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
		//�����λ����left
		a[0] = a[i];
		for (j = i - 1; j >= left; j--)
			a[j + 1] = a[j];
		a[left] = a[0];
	}

}

int  main() {
	clock_t start, finish;
	start = clock();
	int a[N + 1], n;                  /*���ݴ洢��a[1]...a[N]��*/
	printf("���ݳ�ʼ��...\n");
	n = readData(a, N, "data1.txt");  /*��data1.txt�ж���N��������������a��nΪʵ�ʶ�������ݸ���*/
	printf("%d������������...\n", n);
	binInsertSort(a, n);
	saveData(a, n, "out.txt");        /*�����������out.txt�ļ���*/
	printf("���������������������out.txt�ļ��С�\n");
	finish = clock();
	double d = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("the time cost is %lf\n", d);
	return 0;
}

#include "Arrayio.h"
#include "time.h"
#define N 100000     /*NΪ��������С����data1.txt��ֻ��50����������������趨Nֵʱ����N<=500000*/

/*�뽫���������������������в���*/
void shellSort(int a[], int n) {
	int i, j, d;
	d = n / 2;
	while (d >= 1) {
		for (i = d + 1; i <= n; i++) {
			//ÿһ�˽�a[i]���뵽a[1]..a[i-1]
			a[0] = a[i];
			j = i - d;
			while ( j >= 1 && a[j] > a[0]) {
				a[j + d] = a[j];
				j = j - d;
			}
			a[j + d] = a[0];
		}

		d = d / 2;
	}

}

int  main() {
	clock_t start, finish;
	start = clock();
	int a[N + 1], n;                  /*���ݴ洢��a[1]...a[N]��*/
	printf("���ݳ�ʼ��...\n");
	n = readData(a, N, "data1.txt");  /*��data1.txt�ж���N��������������a��nΪʵ�ʶ�������ݸ���*/
	printf("%d������������...\n", n);
	shellSort(a, n);
	saveData(a, n, "out.txt");        /*�����������out.txt�ļ���*/
	printf("���������������������out.txt�ļ��С�\n");
	finish = clock();
	double d = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("the time cost is %lf\n", d);
	return 0;
}

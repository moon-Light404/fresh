#include <stdio.h>
#include <math.h>
#include <iostream>
#include <queue>
using namespace std;

void FCFS(float Atime[], float Stime[]) {
	float Ctime[5]; // 完成时间
	float ZZtime[5]; // 周转时间
	float DQtime[5]; // 响应比
	int i;
	Ctime[0] = Stime[0];
	printf("完成结束时间\t");
	for (i = 1; i < 5; i++)
		Ctime[i] = Stime[i] + Ctime[i - 1]; // 完成时间==服务时间+上一个进程完成时间
	for (i = 0; i < 5; i++)
		printf("%5.2f  ", Ctime[i]);
	printf("\n");
	printf("等待+服务时间\t");
	for (i = 0; i < 5; i++) {
		ZZtime[i] = Ctime[i] - Atime[i]; // 周转时间=完成时间-到达时间
		printf("%5.2f  ", ZZtime[i]);
	}
	printf("\n");
	printf("响应比\t\t");
	for (i = 0; i < 5; i++) {
		DQtime[i] = ZZtime[i] / Stime[i]; // 响应比
		printf("%5.2f  ", DQtime[i]);
	}
	printf("\n");
}

void SJF(float Atime[], float Stime[]) {
	float Ctime[5];
	float ZZtime[5];
	float DQtime[5];
	int i, j;
	// 开始时刻只有一个进程执行
	Ctime[0] = Stime[0];
	ZZtime[0] = Ctime[0] - Atime[0];
	DQtime[0] = ZZtime[0] / Stime[0];
	for (i = 1; i < 5; i++) {
		for (int j = i; j < 5; j++) { // 排序
			for (int d = i + 1; d < 5; d++) {
				if (Ctime[i - 1] >= Atime[i] && Ctime[i - 1] >= Atime[d] && Stime[j] > Stime[d]) {
					int m, n;
					m = Stime[j];
					Stime[j] = Stime[d];
					Stime[d] = m;
					n = Atime[j];
					Atime[j] = Atime[d];
					Atime[d] = n;
				}
			}
		}
		if (Atime[i] < Ctime[i - 1]) { // 当前到达时间在上一个作业结束之前
			Ctime[i] = Ctime[i - 1] + Stime[i];
			ZZtime[i] = Ctime[i] - Atime[i];
			DQtime[i] = ZZtime[i] / Stime[i];
		} else { // 当前到达时间在上一个作业结束时间之后
			Ctime[i] = Atime[i] + Stime[i];
			ZZtime[i] = Ctime[i] - Atime[i];
			DQtime[i] = ZZtime[i] / Stime[i];
		}
	}
	printf("完成时间\t");
	for (int i = 0; i < 5; i++)
		printf("%5.2f  ", Ctime[i]);
	printf("\n");
	printf("周转时间\t");
	for (int i = 0; i < 5; i++)
		printf("%5.2f  ", ZZtime[i]);
	printf("\n");
	printf("响应比\t");
	for (int i = 0; i < 5; i++)
		printf("%5.2f  ", DQtime[i]);

}

// 时间片轮转算法
void RR(float Atime[], float Stime[]) {
	float Ctime[5];
	float ZZtime[5];
	float DQtime[5];
	int i, j, h, f, q;
	float t[5], k;
	scanf("%d", &q); // 时间片大小
	int q[N];







	// 打印
	for (i = 0; i < 5; i++)
		ZZtime[i] = Ctime[i] - Atime[i];
	for (i = 0; i < 5; i++)
		DQtime[i] = ZZtime[i] / Stime[i];
	for (i = 0; i < 5; i++)
		printf("%5.2f ", Ctime[i]);
	printf("\n");
	for (i = 0; i < 5; i++)
		printf("%5.2f ", ZZtime[i]);
	printf("\n");
	for (i = 0; i < 5; i++)
		printf("%5.2f ", DQtime[i]);
	printf("\n");
}

void HRN(float Atime[], float Stime[]);

int main() {
	int i;
	float Atime[5] = {0, 2, 4, 6, 8};
	float Stime[5] = {3, 6, 4, 5, 2};
	printf("到达时间	");
	for (i = 0; i < 5; i++)
		printf("%5.2f  ", Atime[i]);
	printf("\n");
	printf("服务时间	");
	for (i = 0; i < 5; i++)
		printf("%5.2f  ", Stime[i]);
	printf("\n");
	RR(Atime, Stime);

}
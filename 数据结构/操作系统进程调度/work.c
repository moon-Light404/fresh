#include <stdio.h>
#include <math.h>
#include <iostream>
#include <queue>
using namespace std;

void FCFS(float Atime[], float Stime[]) {
	float Ctime[5]; // ���ʱ��
	float ZZtime[5]; // ��תʱ��
	float DQtime[5]; // ��Ӧ��
	int i;
	Ctime[0] = Stime[0];
	printf("��ɽ���ʱ��\t");
	for (i = 1; i < 5; i++)
		Ctime[i] = Stime[i] + Ctime[i - 1]; // ���ʱ��==����ʱ��+��һ���������ʱ��
	for (i = 0; i < 5; i++)
		printf("%5.2f  ", Ctime[i]);
	printf("\n");
	printf("�ȴ�+����ʱ��\t");
	for (i = 0; i < 5; i++) {
		ZZtime[i] = Ctime[i] - Atime[i]; // ��תʱ��=���ʱ��-����ʱ��
		printf("%5.2f  ", ZZtime[i]);
	}
	printf("\n");
	printf("��Ӧ��\t\t");
	for (i = 0; i < 5; i++) {
		DQtime[i] = ZZtime[i] / Stime[i]; // ��Ӧ��
		printf("%5.2f  ", DQtime[i]);
	}
	printf("\n");
}

void SJF(float Atime[], float Stime[]) {
	float Ctime[5];
	float ZZtime[5];
	float DQtime[5];
	int i, j;
	// ��ʼʱ��ֻ��һ������ִ��
	Ctime[0] = Stime[0];
	ZZtime[0] = Ctime[0] - Atime[0];
	DQtime[0] = ZZtime[0] / Stime[0];
	for (i = 1; i < 5; i++) {
		for (int j = i; j < 5; j++) { // ����
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
		if (Atime[i] < Ctime[i - 1]) { // ��ǰ����ʱ������һ����ҵ����֮ǰ
			Ctime[i] = Ctime[i - 1] + Stime[i];
			ZZtime[i] = Ctime[i] - Atime[i];
			DQtime[i] = ZZtime[i] / Stime[i];
		} else { // ��ǰ����ʱ������һ����ҵ����ʱ��֮��
			Ctime[i] = Atime[i] + Stime[i];
			ZZtime[i] = Ctime[i] - Atime[i];
			DQtime[i] = ZZtime[i] / Stime[i];
		}
	}
	printf("���ʱ��\t");
	for (int i = 0; i < 5; i++)
		printf("%5.2f  ", Ctime[i]);
	printf("\n");
	printf("��תʱ��\t");
	for (int i = 0; i < 5; i++)
		printf("%5.2f  ", ZZtime[i]);
	printf("\n");
	printf("��Ӧ��\t");
	for (int i = 0; i < 5; i++)
		printf("%5.2f  ", DQtime[i]);

}

// ʱ��Ƭ��ת�㷨
void RR(float Atime[], float Stime[]) {
	float Ctime[5];
	float ZZtime[5];
	float DQtime[5];
	int i, j, h, f, q;
	float t[5], k;
	scanf("%d", &q); // ʱ��Ƭ��С
	int q[N];







	// ��ӡ
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
	printf("����ʱ��	");
	for (i = 0; i < 5; i++)
		printf("%5.2f  ", Atime[i]);
	printf("\n");
	printf("����ʱ��	");
	for (i = 0; i < 5; i++)
		printf("%5.2f  ", Stime[i]);
	printf("\n");
	RR(Atime, Stime);

}
#include <stdio.h>
#include <iostream>
#define max 10000
using namespace std;

typedef struct zon {
	int Znumber[6];
	int address[6];
	int size[6];
	int flag[6];
} zone; // �洢ÿ���������

int fenqu(zone &Z, int work, int s) {
	int k = -1, min = max;
	for (int i = 0; i < 6; i++) {
		if (Z.size [i] >= s && Z.flag[i] == 0) {
			if (Z.size [i] - s < min) {
				k = i;
				min = Z.size [i] - s;
			}
		} // �ҳ������������ҵ�����ڴ����С����
	}
	if (k == -1) {
		printf("����ʧ��\n");
		return 0;
	} else {
		Z.flag[k] = work; // ��������ķ�����Ǹ���ҵ
		return 1;
	}
}

void shifang(zone &Z, int work) { // �ͷŽ���
	for (int i = 0; i < 6; i++) {
		if (Z.flag[i] == work)
			Z.flag[i] = 0;
	}
}

int main() {
	zone z;
	int s;//��ҵ����
	int  w;//��ҵ����
	char J;
	printf("�������ڴ�����\n");
	printf("������,��ʼ��ַ,����,ռ�ñ�־\n");
	for (int i = 0; i < 6; i++) {
		scanf("%d,%d,%d,%d", &z.Znumber [i], &z.address [i], &z.size [i], &z.flag [i]);
		getchar();
	}
	printf("��������ҵ����\n");
	scanf("%c%d,%d", &J, &w, &s);
	getchar();
	fenqu(z, w, s);
	if (fenqu(z, w, s)) {
		printf("������   ��ʼ��ַ   ����  ռ�ñ�־\n");
		for (int i = 0; i < 6; i++) {
			printf("%d       %d       %d      ", z.Znumber [i], z.address [i], z.size [i]);
			if (z.flag[i] != 0) {
				printf("J%d\n", z.flag [i]);
			} else {
				printf("%d\n", z.flag [i]);
			}
		}
	}
	printf("��������ҵ����\n");
	scanf("%c%d,%d", &J, &w, &s);
	getchar();
	if (fenqu(z, w, s)) {
		printf("������   ��ʼ��ַ   ����  ռ�ñ�־\n");
		for (int i = 0; i < 6; i++) {
			printf("%d       %d       %d      ", z.Znumber [i], z.address [i], z.size [i]);
			if (z.flag[i] != 0) {
				printf("J%d\n", z.flag [i]);
			} else {
				printf("%d\n", z.flag [i]);
			}
		}
	}
	printf("�������ͷ���ҵ����\n");
	scanf("%c%d", &J, &w);
	shifang(z, w);
	printf("������   ��ʼ��ַ   ����  ռ�ñ�־\n");
	for (int i = 0; i < 6; i++) {
		printf("%d       %d       %d      ", z.Znumber [i], z.address [i], z.size [i]);
		if (z.flag[i] != 0) {
			printf("J%d\n", z.flag [i]);
		} else {
			printf("%d\n", z.flag [i]);
		}
	}
	getchar();
	getchar();
	return 0;
}

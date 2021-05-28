#include <stdio.h>
#include <iostream>
#define max 10000
using namespace std;

typedef struct zon {
	int Znumber[6];
	int address[6];
	int size[6];
	int flag[6];
} zone; // 存储每个分区情况

int fenqu(zone &Z, int work, int s) {
	int k = -1, min = max;
	for (int i = 0; i < 6; i++) {
		if (Z.size [i] >= s && Z.flag[i] == 0) {
			if (Z.size [i] - s < min) {
				k = i;
				min = Z.size [i] - s;
			}
		} // 找出能满足进程作业所需内存的最小分区
	}
	if (k == -1) {
		printf("分区失败\n");
		return 0;
	} else {
		Z.flag[k] = work; // 满足情况的分区标记改作业
		return 1;
	}
}

void shifang(zone &Z, int work) { // 释放进程
	for (int i = 0; i < 6; i++) {
		if (Z.flag[i] == work)
			Z.flag[i] = 0;
	}
}

int main() {
	zone z;
	int s;//作业长度
	int  w;//作业名称
	char J;
	printf("请输入内存分配表\n");
	printf("分区号,起始地址,长度,占用标志\n");
	for (int i = 0; i < 6; i++) {
		scanf("%d,%d,%d,%d", &z.Znumber [i], &z.address [i], &z.size [i], &z.flag [i]);
		getchar();
	}
	printf("请输入作业申请\n");
	scanf("%c%d,%d", &J, &w, &s);
	getchar();
	fenqu(z, w, s);
	if (fenqu(z, w, s)) {
		printf("分区号   起始地址   长度  占用标志\n");
		for (int i = 0; i < 6; i++) {
			printf("%d       %d       %d      ", z.Znumber [i], z.address [i], z.size [i]);
			if (z.flag[i] != 0) {
				printf("J%d\n", z.flag [i]);
			} else {
				printf("%d\n", z.flag [i]);
			}
		}
	}
	printf("请输入作业申请\n");
	scanf("%c%d,%d", &J, &w, &s);
	getchar();
	if (fenqu(z, w, s)) {
		printf("分区号   起始地址   长度  占用标志\n");
		for (int i = 0; i < 6; i++) {
			printf("%d       %d       %d      ", z.Znumber [i], z.address [i], z.size [i]);
			if (z.flag[i] != 0) {
				printf("J%d\n", z.flag [i]);
			} else {
				printf("%d\n", z.flag [i]);
			}
		}
	}
	printf("请输入释放作业申请\n");
	scanf("%c%d", &J, &w);
	shifang(z, w);
	printf("分区号   起始地址   长度  占用标志\n");
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

#include <stdio.h>
#include <iostream>
#include <cmath>
#include <queue>
#include <iomanip>
#include <cstring>
using namespace std;

queue<int> process; // 进程就绪队列从0-4
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
	float atime[5], stime[5]; // 因为下面操作时数据会改变拷贝一下
	float Ctime[5];
	float ZZtime[5];
	float DQtime[5];
	for (int k = 0; k < 5; k++) {
		atime[k] = Atime[k];
		stime[k] = Stime[k];
	}
	int q;
	scanf("%d", &q);
	int point = 0; // 从0开始记录每段时间片的下标
	process.push(0); // 把第一个进程放进队列
	int processMoment[100]; // 存储每个时间片p对应的进程编号
	int Currenttime = 0;
	int i = 1; // 指向还未处理的进程下标
	int temptime;
	int finalProcessNumber = 0; //执行RR算法后，进程的个数
	int processTime[50]; // 每个时间片执行的时间
	//声明此变量控制CurrentTime的累加时间，当前进程的服务时间小于时间片q的时候，起到重要作用
	// Currenttime初始化
	if (Stime[0] >= q) {
		Currenttime = q;
	} else {
		Currenttime = Stime[0];
	}

	while (!process.empty()) { // 当进程队列不空
		for (int j = i; j < 5; j++) { //使得满足进程的到达时间小于当前时间的进程都进入队列
			if (Currenttime >= Atime[i]) {
				process.push(i); // 进程编号
				i++;
			}
		}
		if (Stime[process.front()] < q) {
			temptime = Stime[process.front()];
		} else {
			temptime = q;
		}
		Stime[process.front()] -= q;  //进程每执行一次，就将其服务时间 -q

		processMoment[point] = process.front();
		point++;
		processTime[finalProcessNumber] = temptime;
		finalProcessNumber++;

		if (Stime[process.front()] <= 0) {
			process.pop();
		} else {
			process.push(process.front());
			process.pop();
		}
		Currenttime += temptime; // 加上单个时间片的长度
	}
	printf("各进程的执行时刻信息:\n");
	printf(" 0时刻---->%d时刻", processTime[0]);
	processTime[finalProcessNumber] = 0;
	int time = processTime[0];
	int count = 0;
	for (int i = 0; i < finalProcessNumber; i++) {
		count = 0;
		cout << setw(3) << processMoment[i] << setw(3) << endl; // 输出进程编号

		while (count != processMoment[i] && count < 5) {
			count++;
		}
		Ctime[count] = time; // 完成时间
		cout << "标记:" << Ctime[count] << endl;
		if (i < finalProcessNumber - 1) {
			cout << setw(3) << time << "时刻" << "-->" << setw(2) << time + processTime[i + 1] << "时刻" << setw(3);
			time += processTime[i + 1];
		}
	}
	printf("\n");
	// 打印计算
	for (int i = 0; i < 5; i++) {
		ZZtime[i] = Ctime[i] - atime[i]; // 周转时间
	}
	for (int i = 0; i < 5; i++) {
		DQtime[i] = ZZtime[i] / stime[i];
	}
	printf("完成时间:\t");
	for (int j = 0; j < 5; j++) {
		printf("%5.2f  ", Ctime[j]);
	}
	printf("\n");
	printf("周转时间:\t");
	for (int j = 0; j < 5; j++) {
		printf("%5.2f  ", ZZtime[j]);
	}
	printf("\n");
	printf("响应比:\t");
	for (int j = 0; j < 5; j++) {
		printf("%5.2f ", DQtime[j]);
	}
}

// 最高响应比优先算法
void HRN(float Atime[], float Stime[]) {
	float Ctime[5];
	float ZZtime[5];
	float DQtime[5];
	int t = 1;
	float m, n, k, f;
	Ctime[0] = Stime[0];
	ZZtime[0] = Ctime[0] - Atime[0];
	DQtime[0] = ZZtime[0] / Stime[0];
	float  maxvalue;
	int next; // 下一个要执行的进程
	for (int i = 1; i < 5; i++) {
		maxvalue = 1 + (Ctime[i - 1] - Atime[i]) / Stime[i]; // 响应比
		next = i; // 现在在第几个进程
		for (int j = i; j < 5; j++) {
			if ((Ctime[i - 1] - Atime[j]) / Stime[j] + 1 > maxvalue && Atime[i] <= Ctime[i - 1]) { // 在第一个进程完成结束前到达
				next = j; // 找出最大的响应比
			}
		}
		m = Atime[i], Atime[i] = Atime[next], Atime[next] = m;
		n = Stime[i], Stime[i] = Stime[next],	Stime[next] = n; // 把最大响应比的进程移动到前面
		Ctime[next] = Ctime[i - 1] + Stime[next]; // 计算完成时间
	}
	for (int i = 0; i < 5; i++)
		printf("%5.2f ", Atime[i]);
	printf("\n");
	for (int i = 0; i < 5; i++)
		printf("%5.2f ", Stime[i]);
	printf("\n");
	for (int i = 1; i < 5; i++) {
		Ctime[i] = Stime[i] + Ctime[i - 1];
	}
	printf("完成时间\t");
	for (int i = 0; i < 5; i++)
		printf("%5.2f ", Ctime[i]);
	printf("\n");
	printf("周转时间\t");
	for (int i = 1; i < 5; i++)
		ZZtime[i] = Ctime[i] - Atime[i];
	for (int i = 0; i < 5; i++)
		printf("%5.2f ", ZZtime[i]);
	printf("\n");
	printf("响应比\t");
	for (int i = 1; i < 5; i++)
		DQtime[i] = ZZtime[i] / Stime[i];
	for (int i = 0; i < 5; i++)
		printf("%5.2f ", DQtime[i]);
	printf("\n");
}

int main() {
	char c;
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
	scanf("%c", &c);
	switch (c) {
		case 'F':
			FCFS(Atime, Stime);
			break;
		case 'S':
			SJF(Atime, Stime);
			break;
		case 'R':
			RR(Atime, Stime);
			break;
		case 'H':
			HRN(Atime, Stime);
			break;
		default:
			printf("error");
	}

}
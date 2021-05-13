#include <stdio.h>
#include <iostream>
#include <cmath>
#include <queue>
#include <iomanip>
#include <cstring>
using namespace std;

queue<int> process; // ���̾������д�0-4
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
	float atime[5], stime[5]; // ��Ϊ�������ʱ���ݻ�ı俽��һ��
	float Ctime[5];
	float ZZtime[5];
	float DQtime[5];
	for (int k = 0; k < 5; k++) {
		atime[k] = Atime[k];
		stime[k] = Stime[k];
	}
	int q;
	scanf("%d", &q);
	int point = 0; // ��0��ʼ��¼ÿ��ʱ��Ƭ���±�
	process.push(0); // �ѵ�һ�����̷Ž�����
	int processMoment[100]; // �洢ÿ��ʱ��Ƭp��Ӧ�Ľ��̱��
	int Currenttime = 0;
	int i = 1; // ָ��δ����Ľ����±�
	int temptime;
	int finalProcessNumber = 0; //ִ��RR�㷨�󣬽��̵ĸ���
	int processTime[50]; // ÿ��ʱ��Ƭִ�е�ʱ��
	//�����˱�������CurrentTime���ۼ�ʱ�䣬��ǰ���̵ķ���ʱ��С��ʱ��Ƭq��ʱ������Ҫ����
	// Currenttime��ʼ��
	if (Stime[0] >= q) {
		Currenttime = q;
	} else {
		Currenttime = Stime[0];
	}

	while (!process.empty()) { // �����̶��в���
		for (int j = i; j < 5; j++) { //ʹ��������̵ĵ���ʱ��С�ڵ�ǰʱ��Ľ��̶��������
			if (Currenttime >= Atime[i]) {
				process.push(i); // ���̱��
				i++;
			}
		}
		if (Stime[process.front()] < q) {
			temptime = Stime[process.front()];
		} else {
			temptime = q;
		}
		Stime[process.front()] -= q;  //����ÿִ��һ�Σ��ͽ������ʱ�� -q

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
		Currenttime += temptime; // ���ϵ���ʱ��Ƭ�ĳ���
	}
	printf("�����̵�ִ��ʱ����Ϣ:\n");
	printf(" 0ʱ��---->%dʱ��", processTime[0]);
	processTime[finalProcessNumber] = 0;
	int time = processTime[0];
	int count = 0;
	for (int i = 0; i < finalProcessNumber; i++) {
		count = 0;
		cout << setw(3) << processMoment[i] << setw(3) << endl; // ������̱��

		while (count != processMoment[i] && count < 5) {
			count++;
		}
		Ctime[count] = time; // ���ʱ��
		cout << "���:" << Ctime[count] << endl;
		if (i < finalProcessNumber - 1) {
			cout << setw(3) << time << "ʱ��" << "-->" << setw(2) << time + processTime[i + 1] << "ʱ��" << setw(3);
			time += processTime[i + 1];
		}
	}
	printf("\n");
	// ��ӡ����
	for (int i = 0; i < 5; i++) {
		ZZtime[i] = Ctime[i] - atime[i]; // ��תʱ��
	}
	for (int i = 0; i < 5; i++) {
		DQtime[i] = ZZtime[i] / stime[i];
	}
	printf("���ʱ��:\t");
	for (int j = 0; j < 5; j++) {
		printf("%5.2f  ", Ctime[j]);
	}
	printf("\n");
	printf("��תʱ��:\t");
	for (int j = 0; j < 5; j++) {
		printf("%5.2f  ", ZZtime[j]);
	}
	printf("\n");
	printf("��Ӧ��:\t");
	for (int j = 0; j < 5; j++) {
		printf("%5.2f ", DQtime[j]);
	}
}

// �����Ӧ�������㷨
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
	int next; // ��һ��Ҫִ�еĽ���
	for (int i = 1; i < 5; i++) {
		maxvalue = 1 + (Ctime[i - 1] - Atime[i]) / Stime[i]; // ��Ӧ��
		next = i; // �����ڵڼ�������
		for (int j = i; j < 5; j++) {
			if ((Ctime[i - 1] - Atime[j]) / Stime[j] + 1 > maxvalue && Atime[i] <= Ctime[i - 1]) { // �ڵ�һ��������ɽ���ǰ����
				next = j; // �ҳ�������Ӧ��
			}
		}
		m = Atime[i], Atime[i] = Atime[next], Atime[next] = m;
		n = Stime[i], Stime[i] = Stime[next],	Stime[next] = n; // �������Ӧ�ȵĽ����ƶ���ǰ��
		Ctime[next] = Ctime[i - 1] + Stime[next]; // �������ʱ��
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
	printf("���ʱ��\t");
	for (int i = 0; i < 5; i++)
		printf("%5.2f ", Ctime[i]);
	printf("\n");
	printf("��תʱ��\t");
	for (int i = 1; i < 5; i++)
		ZZtime[i] = Ctime[i] - Atime[i];
	for (int i = 0; i < 5; i++)
		printf("%5.2f ", ZZtime[i]);
	printf("\n");
	printf("��Ӧ��\t");
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
	printf("����ʱ��	");
	for (i = 0; i < 5; i++)
		printf("%5.2f  ", Atime[i]);
	printf("\n");
	printf("����ʱ��	");
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
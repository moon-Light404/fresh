//#include <iostream>







//using namespace std;
//
//int Search(int a[], int left, int right, int key) {
//	if (left <= right) {
//		int mid = (left + right) / 2;
//		if (a[mid] == key)
//			return mid;
//		else if (a[mid] > key) {
//			return Search(a, left, mid - 1, key);
//		} else
//			return Search(a, mid + 1, right, key);
//	}
//	return -1;
//}
//
//int main() {
//	int x;
//	int pos;
//	int a[10] = {5, 8, 17, 20, 31, 38, 45, 57, 65, 74};
//	printf("������Ҫ���ҵ���:\n");
//	scanf("%d", &x);
//	pos = Search(a, 0, 9, x);
//	if (pos != -1)
//		printf("a[%d]=%d\n", pos, x);
//	else
//		printf("Not found\n");
//	return 0;
//}




// ֻ��ͷ����ѭ������
#include <iostream>
#include <cstdlib>
using namespace std;
typedef int datatype;
typedef struct link_node {
	datatype info;
	struct link_node *next;
} node; // ���н��

typedef struct {
	node *rear;
} queue;

void initQueue(queue *q) { // �����ÿ�
	q->rear = (node *)malloc(sizeof(node));
	q->rear->next = q->rear; // ��β���Ϊ��û��Ԫ��
}

void EnQueue(queue *qu, datatype x) {
	node *p;
	p = (node *)malloc(sizeof(node));
	p->info = x;
	p->next = qu->rear->next;
	qu->rear = p;
}

void display(queue *qu) { // ����Ԫ��
	node *p = qu->rear;
	p = p->next;
	while (p != qu->rear) {
		printf("%d ", p->info);
		p = p->next;
	}
}

int main() {
	queue *qu;
	qu = (queue *)malloc(sizeof(queue));
	initQueue(qu);
	for (int i = 1; i < 5; i++)
		EnQueue(qu, i);
	display(qu);
	return 0;
}
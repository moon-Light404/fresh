#include "slinklist.h"

linklist insert(linklist head, datatype x) {
	linklist p, q, pre; // q是要插入的节点
	q = (linklist)malloc(sizeof(node));
	q->info = x;
	p = head;
	// 插入头节点
	if (p->info >= x) {
		head = q;
		q->next = p;
		return head;
	}
	pre = p, p = p->next;
	while (p && x >= p->info) { // 找到第一个大于等于的数
		pre = p;
		p = p->next;
	}
	// 插入中间,插入到p后面
	if (pre->next) {
		q->next = pre->next;
		pre->next = q;
	}
	// 最后一个点
	else if (pre->next == NULL) {
		pre->next = q;
		q->next = NULL;
	}
	return head;
}

int main() {
	datatype x;
	linklist head;
	printf("输入一组升序排列的整数: \n");
	head = creatbyqueue();
	print(head);
	printf("请输入要插入的值:");
	scanf("%d", &x);
	head = insert(head, x);
	print(head);
	delList(head);
	return 0;
}
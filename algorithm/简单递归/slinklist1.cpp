#include "slinklist.h"

linklist delx(linklist head, datatype x) {
	linklist p, pre = NULL;
	p = head;
	// 第一个结点就是x
	if (p->info == x) {
		head = head->next;
		return head;
	}
	while (p && p->info != x) {
		pre = p;
		p = p->next;
	}
	if (p) {
		if (pre == NULL)
			head = head ->next;
		else
			pre->next = p->next;
		free(p);
	}
	return head;
}

int main() {
	datatype x;
	linklist head;
	head = creatbyqueue();
	print(head);
	printf("输入要删除的值: ");
	scanf("%d", &x);
	head = delx(head, x);
	print(head);
	delList(head);

	return 0;
}
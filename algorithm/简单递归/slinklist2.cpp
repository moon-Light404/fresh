#include "slinklist.h"

linklist delallx(linklist head, int x) {
	linklist p = head, p2 = head;
	while (p != NULL) {
		if (p->info == x) {
			if (p == head)
				head = p->next;
			else {
				p2->next = p->next;
				free(p);
				p = p2;
			}
		}
		p2 = p; // ǰ���ڵ�
		p = p->next;
	}
	return head;
}



int main() {
	datatype x;
	linklist head;
	head = creatbyqueue();
	print(head);
	printf("������Ҫɾ����ֵ:\n");
	scanf("%d", &x);
	head = delallx(head, x);
	print(head);
	delList(head);
	return 0;
}
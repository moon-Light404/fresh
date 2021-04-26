#include "slnklist.h"

// 返回链表中最大数所在的结点地址
linklist max(linklist head) {
	linklist p;
	if (head->next == NULL) { // 表中没有元素
		return NULL;
	} else if (head->next->next == NULL) { // 表中有一个元素
		return head->next;
	} else {
		p = max(head->next); // 一直递归到最后一个元素，然后
		// 回溯，找到head->next后面的数中的最大值(不包括head->next)
		if (head->next->info > p->info) {
			return head->next;
		}
		return p;
	}
}

int main() {
	linklist head, p;
	head = creatbyqueue();
	print(head);
	p = max(head);
	if (p)
		printf("max=%d\n", p->info);
	else
		printf("链表为空\n");
	return 0;
}
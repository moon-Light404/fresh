#include "slnklist.h"

// ������������������ڵĽ���ַ
linklist max(linklist head) {
	linklist p;
	if (head->next == NULL) { // ����û��Ԫ��
		return NULL;
	} else if (head->next->next == NULL) { // ������һ��Ԫ��
		return head->next;
	} else {
		p = max(head->next); // һֱ�ݹ鵽���һ��Ԫ�أ�Ȼ��
		// ���ݣ��ҵ�head->next��������е����ֵ(������head->next)
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
		printf("����Ϊ��\n");
	return 0;
}
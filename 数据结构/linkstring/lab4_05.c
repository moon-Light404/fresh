#include "linkstring.h"

void delstring(linkstring s, int i, int len) {
	linkstring p, q;
	int k = 1;
	p = s->next;
	while (p && k < i - 1) { // ��ɾ�����Ӵ�����ʼ����ǰ�����
		p = p->next;
		k++;
	}
	if (!p || !p->next)
		return;
	else {
		k = 0;
		while (p->next && k < len) {
			q = p->next;
			p ->next = q->next;
			free(q);
			k++;
		}
	}
}

int main() {
	linkstring str;
	str = create();
	print(str);
	delstring(str, 2, 3);
	print(str);
	delList(str);
	return 0;
}
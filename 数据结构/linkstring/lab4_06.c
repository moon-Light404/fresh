#include "linkstring.h"

// ��ͷ���
linkstring index(linkstring s, linkstring t) { // t ���Ӵ�
	linkstring p, p1, t1;
	p = s->next;
	while (p) { // ����ѭ������
		p1 = p;
		t1 = t->next; // ÿ�ζ�Ҫ��ͷѭ���Ӵ�
		while (p1 && t1 && p1->data == t1->data) {
			p1 = p1->next;
			t1 = t1->next;
		}
		if (t1 == NULL)
			return p; // ˵���Ӵ����������Ѿ���������
		p = p->next;
	}
	return NULL;

}

int main() {
	linkstring s, t, p = NULL;
	s = create();
	t = create();
	print(s);
	print(t);
	p = index(s, t);
	if (p) {
		printf("ƥ��ɹ�,�״�ƥ��Ľ��ֵΪ:%c\n", p -> data);
	} else
		printf("ƥ��ʧ��\n");
	delList(s);
	delList(t);
	return 0;
}
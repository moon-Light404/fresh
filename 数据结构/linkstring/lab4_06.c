#include "linkstring.h"

// 带头结点
linkstring index(linkstring s, linkstring t) { // t 是子串
	linkstring p, p1, t1;
	p = s->next;
	while (p) { // 依次循环主串
		p1 = p;
		t1 = t->next; // 每次都要从头循环子串
		while (p1 && t1 && p1->data == t1->data) {
			p1 = p1->next;
			t1 = t1->next;
		}
		if (t1 == NULL)
			return p; // 说明子串在主串中已经遍历到了
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
		printf("匹配成功,首次匹配的结点值为:%c\n", p -> data);
	} else
		printf("匹配失败\n");
	delList(s);
	delList(t);
	return 0;
}
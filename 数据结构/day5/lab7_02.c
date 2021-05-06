#include "bintree.h"
char *a = "ABC##D#E##F##";

void levelbintree(bintree t) {
	seqstack s1, s2;
	init(&s1);
	init(&s2);
	push(s1, t); // ��������

	while (!empty(&s1)) { // s1����
		bintree temp = NULL;
		if (!empty(&s2)) { // s2����
			tmp = pop(&s2);
		} else {
			tmp = pop(&s1); // ��s1�еĽ�㵼��s2
			while (!empty(&s1)) { // s1����
				push(&s2, tmp);
				tmp = pop(&s1);
			}
		}
		printf("%4c", tmp->data);
		if (tmp->lchild != NULL) {
			push(&s1, tmp->lchild);
		}
		if (tmp->rchild != NULL) {
			push(&s1, tmp->rchild);
		}
	}
	free(s1);
	free(s2);
}

int main() {
	bintree t;
	t = createbintree();
	printf("�������Ĳ������Ϊ:\n");
	levelbintree(t);
	return 0;

}
#include "bintree.h"
char *a = "ABC##D#E##F##";

void levelbintree(bintree t) {
	seqstack s1, s2;
	init(&s1);
	init(&s2);
	push(s1, t); // 根结点入队

	while (!empty(&s1)) { // s1不空
		bintree temp = NULL;
		if (!empty(&s2)) { // s2不空
			tmp = pop(&s2);
		} else {
			tmp = pop(&s1); // 把s1中的结点导入s2
			while (!empty(&s1)) { // s1不空
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
	printf("二叉树的层次序列为:\n");
	levelbintree(t);
	return 0;

}
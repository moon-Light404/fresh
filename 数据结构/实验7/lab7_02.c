#include "bintree.h"
char *a = "ABC##D#E##F##";

void levelbintree(bintree t) {
	bintree queue[100];
	int l = 0, r = 1;
	queue[0] = t;
	bintree tmp;
	while (l < r) {
		tmp = queue[l]; // 记录队首元素
		l++; // 出队并打印
		printf("%c ", tmp->data);
		if (tmp->lchild) {
			queue[r] = tmp->lchild;
			r++;
		}
		if (tmp->rchild) {
			queue[r] = tmp->rchild;
			r++; // 入队
		}
	}
}

int main() {
	bintree t;
	t = creatbintree();
	printf("二叉树的层次序列为:\n");
	levelbintree(t);
//	preorder(t);
//	puts("");
//	postorder(t);
	return 0;

}
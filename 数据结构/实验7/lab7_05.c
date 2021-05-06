#include "bintree.h"
char *a = "ABC##D##EF#G###";

void change(bintree t) {
	bintree p;
	if (t == NULL)
		return;
	else {
		p = t->lchild;
		t->lchild = t->rchild;
		t->rchild = p;
		// �ݹ�������
		change(t->lchild);
		// �ݹ�������
		// ֱ��tΪ�շ���NULL
		change(t->rchild);
	}

}

int main() {
	bintree root;
	root = creatbintree();
	change(root);
	preorder(root);
	return 0;
}
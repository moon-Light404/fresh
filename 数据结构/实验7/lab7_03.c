#include "bintree.h"
char *a = "ABC##D##EF#G###";

bintree prelast(bintree t) {
	bintree p = t;
	if (p) {
		// 要寻找最后一个结点那么开始从右子树向下找
		//	在p不为空且p有左子节点或者右子节点的情况下，在右子节点不为空的情况下先去找右子节点，右子节点为空则返回左子节点。
		//最后找到的结点无左右子树则跳出循环，并返回p的结点地址为前序遍历下最后一个结点地址。
		while (p && p->lchild || p->rchild) {
			if (p->rchild)
				p = p->rchild;
			else
				p = p->lchild;
		}
	}
	return p;
}

? // 同理后序遍历下的第一个结点的地址则去不停的往下寻找左节点，
// 知道节点没有左子树再去看是否有右子树，如果没有则返回节点地址，如果有则继续进入右子树去寻找左下角的结点。
bintree prefirst(bintree t) {
	bintree p = t;
	if (p) {
		while (p && p->lchild || p->rchild) {
			if (p->lchild)
				p = p->lchild;
			else
				p = p-> rchild;
		}
	}
	return p;
}

int main() {
	bintree t, p, q;
	t = creatbintree();
	q = prelast(t);
	p = prefirst(t);
	if (t != NULL) {
		printf("前序遍历最后一个结点为:%c\n", q->data);
		printf("后序遍历第一个结点为:%c\n", p->data);
	} else {
		printf("二叉树为空! ");
	}
	return 0;
}
#include "bintree.h"
char *a = "ABC##D##EF#G###";

bintree prelast(bintree t) {
	bintree p = t;
	if (p) {
		// ҪѰ�����һ�������ô��ʼ��������������
		//	��p��Ϊ����p�����ӽڵ�������ӽڵ������£������ӽڵ㲻Ϊ�յ��������ȥ�����ӽڵ㣬���ӽڵ�Ϊ���򷵻����ӽڵ㡣
		//����ҵ��Ľ������������������ѭ����������p�Ľ���ַΪǰ����������һ������ַ��
		while (p && p->lchild || p->rchild) {
			if (p->rchild)
				p = p->rchild;
			else
				p = p->lchild;
		}
	}
	return p;
}

? // ͬ���������µĵ�һ�����ĵ�ַ��ȥ��ͣ������Ѱ����ڵ㣬
// ֪���ڵ�û����������ȥ���Ƿ��������������û���򷵻ؽڵ��ַ����������������������ȥѰ�����½ǵĽ�㡣
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
		printf("ǰ��������һ�����Ϊ:%c\n", q->data);
		printf("���������һ�����Ϊ:%c\n", p->data);
	} else {
		printf("������Ϊ��! ");
	}
	return 0;
}
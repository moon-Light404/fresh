#include "bintree.h"
char *a = "ABC##D#E##F##";

void levelbintree(bintree t) {
	bintree queue[100];
	int l = 0, r = 1;
	queue[0] = t;
	bintree tmp;
	while (l < r) {
		tmp = queue[l]; // ��¼����Ԫ��
		l++; // ���Ӳ���ӡ
		printf("%c ", tmp->data);
		if (tmp->lchild) {
			queue[r] = tmp->lchild;
			r++;
		}
		if (tmp->rchild) {
			queue[r] = tmp->rchild;
			r++; // ���
		}
	}
}

int main() {
	bintree t;
	t = creatbintree();
	printf("�������Ĳ������Ϊ:\n");
	levelbintree(t);
//	preorder(t);
//	puts("");
//	postorder(t);
	return 0;

}
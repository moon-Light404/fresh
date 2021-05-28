#include "ljjz.h"

typedef struct edgedata {
	int beg, en;
	int length;
} edge;

// n������ n-1����(0��n-2)
void prim(Mgraph g, edge tree[M - 1]) { // tree�����ʾ�Ķ�̬(��ʾ����֮���d)�ı��
	edge x;
	int d, min, j, k, s, v;

	for (v = 1; v <= g.n - 1; v++) {
		tree[v - 1].beg = 0;
		tree[v - 1].en = v;
		tree[v - 1].length = g.edges[0][v];
	}

	for (k = 0; k <= g.n - 3; k++) {
		min = tree[k].length;
		s = k;

		for (j = k + 1; j <= g.n - 2; j++)
			if (tree[j].length < min) {
				min = tree[j].length;
				s = j; // �ҵ���̵�������
			}
		v = tree[s].en;
		x = tree[s];
		tree[s] = tree[k];
		tree[k] = x; // xֻ��һ���м�������ڽ���,����С��������
		// �ŵ���δѡ�ı���ǰ��
		for (j = k + 1; j <= g.n - 2; j++) { // �����¶���ļ����޸������ߵ���Ϣ
			d = g.edges[v][tree[j].en]; // v���¼���Ķ��㣬��v��������������ľ���
			// ����tree������յ�en������v��������en�ľ�����û�и�С��
			if (d < tree[j].length) {
				tree[j].length = d;
				tree[j].beg = v; // ��������޸������Ϊv
			}
		}
	}
	printf("\n The minimum cost spanning tree is:\n"); // �����С������
	for (j = 0; j <= g.n - 2; j++) {
		printf("\n%c---%c %d\n", g.vexs[tree[j].beg], g.vexs[tree[j].en], tree[j].length);
		printf("\nThe root of it is %c\n", g.vexs[0]);
	}
}

int main() {
	Mgraph g;
	edge tree[M - 1];
	char filename[20];
	printf("please input filename of Graph:\n");
	gets(filename);
	creat(&g, filename, 0); // ����ͼ�ڽӾ���
	print(g);
	prim(g, tree);
	return 0;
}
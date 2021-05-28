#include "ljjz.h"

typedef struct edgedata {
	int beg, en;
	int length;
} edge;

// n个顶点 n-1条边(0到n-2)
void prim(Mgraph g, edge tree[M - 1]) { // tree数组表示的动态(表示两点之间的d)的表格
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
				s = j; // 找到最短的两西边
			}
		v = tree[s].en;
		x = tree[s];
		tree[s] = tree[k];
		tree[k] = x; // x只是一个中间变量用于交换,把最小的两西边
		// 放到还未选的边最前面
		for (j = k + 1; j <= g.n - 2; j++) { // 由于新顶点的加入修改两西边的信息
			d = g.edges[v][tree[j].en]; // v是新加入的顶点，从v出发到其他顶点的距离
			// 遍历tree数组的终点en，看从v出发到达en的距离有没有更小的
			if (d < tree[j].length) {
				tree[j].length = d;
				tree[j].beg = v; // 如果有则修改其起点为v
			}
		}
	}
	printf("\n The minimum cost spanning tree is:\n"); // 输出最小生成树
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
	creat(&g, filename, 0); // 无向图邻接矩阵
	print(g);
	prim(g, tree);
	return 0;
}
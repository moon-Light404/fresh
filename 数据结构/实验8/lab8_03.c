// 采用邻接表存储结构，对图进行深度优先遍历
#include "ljb.h"
int visited[M];

void dfs(LinkedGraph g, int i) {
	EdgeNode *p;
	printf("visit vertex: %c \n", g.adjlist[i].vertex);
	visited[i] = 1;
	p = g.adjlist[i].FirstEdge;
	while (p) { // 遍历该点的邻接表,一直把能够和该点连通的点一次性遍历
		if (!visited[p->adjvex])
			dfs(g, p->adjvex);
		p = p->next;
	}
}

void DfsTraverse(LinkedGraph g) {
	int i;
	for (i = 0; i < g.n; i++)
		visited[i] = 0;   /*初始化标志数组*/
	for (i = 0; i < g.n; i++)
		if (!visited[i])  /*vi未访问过*/
			dfs(g, i);
}

int main() {
	LinkedGraph g;
	creat(&g, "g11.txt", 0);
	printf("\n The graph is:\n");
	print(g);
	printf("深度优先遍历序列为: \n");
	DfsTraverse(g);
	return 0;
}
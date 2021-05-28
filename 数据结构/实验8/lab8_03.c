// �����ڽӱ�洢�ṹ����ͼ����������ȱ���
#include "ljb.h"
int visited[M];

void dfs(LinkedGraph g, int i) {
	EdgeNode *p;
	printf("visit vertex: %c \n", g.adjlist[i].vertex);
	visited[i] = 1;
	p = g.adjlist[i].FirstEdge;
	while (p) { // �����õ���ڽӱ�,һֱ���ܹ��͸õ���ͨ�ĵ�һ���Ա���
		if (!visited[p->adjvex])
			dfs(g, p->adjvex);
		p = p->next;
	}
}

void DfsTraverse(LinkedGraph g) {
	int i;
	for (i = 0; i < g.n; i++)
		visited[i] = 0;   /*��ʼ����־����*/
	for (i = 0; i < g.n; i++)
		if (!visited[i])  /*viδ���ʹ�*/
			dfs(g, i);
}

int main() {
	LinkedGraph g;
	creat(&g, "g11.txt", 0);
	printf("\n The graph is:\n");
	print(g);
	printf("������ȱ�������Ϊ: \n");
	DfsTraverse(g);
	return 0;
}
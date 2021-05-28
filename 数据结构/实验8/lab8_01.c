#include "ljb.h"

void degree(LinkedGraph g) {
	EdgeNode *p;
	int i;
	for (i = 0; i < g.n; i++) {
		printf("%c's degree is ", g.adjlist[i].vertex);
		p = g.adjlist[i].FirstEdge;
		int cnt = 0;
		while (p) {
			cnt++;
			p = p->next;
		}
		printf("%d\n", cnt);
	}
}

int main() {
	LinkedGraph g;
	creat(&g, "g11.txt", 0); // g11中存储了图的信息
	printf("\n The graph is:\n");
	print(g);
	degree(g);
	return 0;
}
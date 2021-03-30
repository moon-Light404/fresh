#include <iostream>
#include <cstring>
using namespace std;

const int N = 1010, M = 1010;

int h[N], e[M], w[M], nxt[M], eidx;

void add(int u, int v, int weight) { // �������� u->v, Ȩ��Ϊweight
	e[eidx] = v;        // ��¼�ߵ��յ�
	w[eidx] = weight;   // ��¼�ߵ�Ȩ��
	nxt[eidx] = h[u];   // ����һ����ָ����u��ʱ�ĵ�һ����
	h[u] = eidx;        // �����u�ĵ�һ���ߵı�Ÿ�Ϊ��ʱ��eidx
//	cout << "e" << " " << eidx << " : " << e[eidx] << endl;
//	cout << "nxt" << " " << nxt[eidx] << endl;
//	cout << "h" << "(" << u << ")" << eidx << endl;
	eidx++;             // �����ߵı��edix, Ϊ����ʹ��

}

void iterate(int u) { // �������u�������ڱ�
	// ��u�ĵ�һ���߿�ʼ������ֱ��eid==-1Ϊֹ
	for (int eid = h[u]; eid != -1; eid = nxt[eid]) {
		int v = e[eid];
		int weight = w[eid];
		cout << u << "->" << v << ", weight: " << weight << endl;
	}
}

int main() {
	int n, m;
	cin >> n >> m;

	memset(h, -1, sizeof h);  // ��ʼ��h����Ϊ-1
	eidx = 0;                 // ��ʼ���ߵı��Ϊ0

	while (m--) {
		int u, v, weight;
		cin >> u >> v >> weight;
		add(u, v, weight);
	}

	for (int i = 1; i <= n; i++)
		iterate(i);

	return 0;
}


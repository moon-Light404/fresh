//#include <iostream>


//
//int main() {
//	int n, a;
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		cin >> a;
//		int count = 0;
//		while (a) {
//			a = a & (a - 1);
//			count++;
//		}
//		cout << count << " ";
//	}
//	return 0;
//}

//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		int n, s = 0;
//		cin >> n;
//		while (n) {
//			if (n & 1)
//				s++;
//			n >>= 1;
//		}
//		cout << s << " ";
//	}
//
//	return 0;
//}



























//#include <iostream>
//#include <cstring>
//using namespace std;
//const int N = 1010, M = N * 2;
//int h[N], e[M], nxt[M], idx;
//int p[M];
//int t;
//bool st[M];
//void add(int a, int b) {
//	e[idx] = b; // �յ�
//	nxt[idx] = h[a];
//	h[a] = idx; // ��¼��ǰ�ߵı��
//	idx++;
//}
//
////eid != -1; eid = nxt[eid]
//void iterate(int u) {
//	for (int eid = h[u]; eid != -1; eid = nxt[eid]) {
//		int v = e[eid];
//		cout << u << "->" << v << endl;;
//	}
//}
//
//
//
//int main() {
//	int n, m;
//	cin >> m; // n�ǵ�����m �Ǳ���
//	memset(h, -1, sizeof h);
//	idx = 0;
//
//	while (m--) {
//		int u, v;
//		cin >> u >> v;
//		p[t++] = u; // ��¼ֱ�ߵ����
//		add(u, v); // u-->v
//	}
//	for (int k = 0; k < t; k++) {
//		iterate(p[k]);
//	}
//	return 0;
//}























//#include <iostream>
//#include <cstring>
//#include <algorithm>
//using namespace std;
//typedef long long LL;
//const int N = 1000010, M = N * 2;
//int h[N], e[N], ne[M], w[N], idx; // ע��w��ʾ�������֣������Ǳߵ�Ȩֵ
//LL f[N]; // ״̬����
//
//void add(int a, int b) {
//	e[idx] = b;
//	ne[idx] = h[a];
//	h[a] = idx++;
//}
//
//void dfs(int u, int fa) { // ��¼���ڵ��ֹ�ֻ�ͷ������,u ��ʾ���ǽ���Ŵ� 1 - n
//	cout << u << " ";
//	for (int i = h[u]; i != -1;
//	        i = ne[i]) // h[u]��ʾ���� u Ϊ���ıߵı�ţ�����ne[i]�ҵ���һ���� u Ϊ���ı�ţ�ֱ���ҵ�����
//		// ����֮ǰ��������
//	{
//		int j = e[i]; // ��¼�����յ�
//		if (j != fa) {
//			dfs(j, u); // ��ʱ�ĸ��ڵ���u
//		}
//	}
//}
//
//int main() {
//	int n;
//	cin >> n;
//	memset(h, -1, sizeof h);
//
//
//	// ���� = ���� - 1
//	for (int i = 0; i < n - 1; i ++) {
//		int a, b;
//		scanf("%d%d", &a, &b);
//		add(a, b), add(b, a);
//	}
//	dfs(1, -1); // �������1��㿪ʼ������
//	return 0;
//}
//
/**
	��������
*/



//#include <iostream>
//#include <vector>
//using namespace std;
//const int N = 20;
//int dp[N][N];
//int f[N][N];
//int n;
//
//void print_result() {
//	cout << f[1][1];
//	// ��ӡ·��
//	int j = 1;
//	for (int i = 1; i < n; i++) {
//		int value = dp[i][j] - f[i][j];
//		if (value == dp[i + 1][j + 1])
//			j++; // �е�λ�øı���
//		cout << "->" << f[i + 1][j];
//	}
//}
//
//int main() {
//	cin >> n;
//	for (int i = 1; i <= n; ++i) {
//		for (int j = 1; j <= i; j++)
//			cin >> f[i][j]; //������������
//	}
//	for (int j = 1; j <= n; j++) {
//		dp[n][j] = f[n][j];//n��ʾ����
//	}
//	for (int i = n - 1; i >= 1; i--) {
//		for (int j = 1; j <= i; j++) {
//			dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + 1]) + f[i][j];
//		}
//	}
//	cout << dp[1][1];
//	print_result();
//	return 0;
//}


// ����һ�����ҳ����м���������������������У���С��������
//#include <iostream>
//using namespace std;
//int n;
//
//const int N = 10;
//int res[N];
//
//void dfs(int u, int x, int c) { // u��ʾ�����±�λ��,x��ʾ��ǰ�ĺͣ�c��ʾ��ǰ��ʼ�������������Ҫ��ǰ��Ĵ��ڻ����
//	if (x > n)
//		return;
//
//	if (x == n) {
//		for (int i = 0; i < u; i++)
//			cout << res[i] << ' ';
//		cout << endl;
//		return;
//	}
//
//	for (int i = c; i <= n; i++) {
//		res[u] = i;
//		dfs(u + 1, x + i, i);
//	}
//}
//
//int main() {
//	cin >> n;
//	dfs(0, 0, 1);
//	return 0;
//}



#include <iostream>

using namespace std;

const int N = 1010;

int n;
int a[N];
int f[N], g[N];

// g[N] ��ʾ��˭ת�ƹ�����

int main() {
	cin >> n;
	for (int i = 1; i <= n; i ++)
		cin >> a[i];

	for (int i = 1; i <= n; i ++) {
		f[i] = 1;
		g[i] = 0;
		for (int j = 1; j < i; j ++)
			if (a[i] > a[j])
				if (f[i] < f[j] + 1) {
					f[i] = f[j] + 1;
					g[i] = j;
				}
	}

	int k = 1;
	// �ҳ�����f[i]
	for (int i = 1; i <= n; i ++)
		if (f[i] > f[k])
			k = i;
	cout << f[k] << endl;

	for (int i = 0, len = f[k]; i < len; i ++) {
		cout << a[k] << ' ';
		k = g[k];
	}
	return 0;
}


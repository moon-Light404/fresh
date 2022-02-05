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
//	e[idx] = b; // 终点
//	nxt[idx] = h[a];
//	h[a] = idx; // 记录当前边的编号
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
//	cin >> m; // n是点数，m 是边数
//	memset(h, -1, sizeof h);
//	idx = 0;
//
//	while (m--) {
//		int u, v;
//		cin >> u >> v;
//		p[t++] = u; // 记录直线的起点
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
//int h[N], e[N], ne[M], w[N], idx; // 注意w表示结点的评分，而不是边的权值
//LL f[N]; // 状态数组
//
//void add(int a, int b) {
//	e[idx] = b;
//	ne[idx] = h[a];
//	h[a] = idx++;
//}
//
//void dfs(int u, int fa) { // 记录父节点防止又回头往上搜,u 表示的是结点编号从 1 - n
//	cout << u << " ";
//	for (int i = h[u]; i != -1;
//	        i = ne[i]) // h[u]表示的是 u 为起点的边的编号，再用ne[i]找到上一个以 u 为起点的编号，直到找到所有
//		// 在其之前加入的领边
//	{
//		int j = e[i]; // 记录的是终点
//		if (j != fa) {
//			dfs(j, u); // 此时的父节点是u
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
//	// 边数 = 点数 - 1
//	for (int i = 0; i < n - 1; i ++) {
//		int a, b;
//		scanf("%d%d", &a, &b);
//		add(a, b), add(b, a);
//	}
//	dfs(1, -1); // 从上面的1结点开始向下搜
//	return 0;
//}
//
/**
	数塔问题
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
//	// 打印路径
//	int j = 1;
//	for (int i = 1; i < n; i++) {
//		int value = dp[i][j] - f[i][j];
//		if (value == dp[i + 1][j + 1])
//			j++; // 列的位置改变了
//		cout << "->" << f[i + 1][j];
//	}
//}
//
//int main() {
//	cin >> n;
//	for (int i = 1; i <= n; ++i) {
//		for (int j = 1; j <= i; j++)
//			cin >> f[i][j]; //输入塔的数字
//	}
//	for (int j = 1; j <= n; j++) {
//		dp[n][j] = f[n][j];//n表示层数
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


// 输入一个数找出所有加起来等于这个数的子序列，从小到大排列
//#include <iostream>
//using namespace std;
//int n;
//
//const int N = 10;
//int res[N];
//
//void dfs(int u, int x, int c) { // u表示数组下标位置,x表示当前的和，c表示当前开始的数，后面的数要比前面的大于或等于
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

// g[N] 表示从谁转移过来的

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
	// 找出最大的f[i]
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


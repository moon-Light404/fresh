// 递归、回溯
/*Red and Black找与某个黑砖连通的黑砖数量
//*/
#include <iostream>





















//using namespace std;
//const int N = 25;
//char g[N][N]; // 地图
//int sx, sy;
//int ans;
//int n, m;
//
//bool vis[N][N]; // 访问数组
//void search(int x, int y) {
//	if (x < 0 || x >= m || y < 0 || y >= n || g[x][y] == '#' || vis[x][y])
//		return;
//	vis[x][y] = true;
//	ans++;
//	search(x - 1, y);
//	search(x + 1, y);
//	search(x, y - 1);
//	search(x, y + 1);
//}
//
//int main() {
//	while (cin >> n >> m && n && m) {
//		for (int i = 0; i < m; i++)
//			for (int j = 0; j < n; j++) {
//				cin >> g[i][j];
//				if (g[i][j] == '@') {
//					sx = i, sy = j; // 起点位置
//				}
//			}
//		memset(vis, false, sizeof vis);
//		ans = 0;
//		search(sx, sy);
//		cout << ans << endl;
//	}
//
//	return 0;
//}

/*
The Sultan's Successors 八皇后问题
*/
#include <cstdio>
#include <vector>
using namespace std;
int p[1000][9]; // p[i][j]记录第i中方案中每一行中棋子的列位置
int temp[8]; // 0~7行中放置棋子的列位置
bool col[8];
bool Left[15];
bool Right[15];
int n = 0;
void init(int r) { // 搜索第r行
	if (r == 8) { // 0~7行搜索完毕
		for (int i = 0; i < 8; i++) {
			p[n][i] = temp[i];
		}
		n++;
		return;
	}
	for (int c = 0; c < 8; c++) { // 第r行的第c列
		int ld = r + c, rd = c - r + 7;
		if (!col[c] && !Left[ld] && !Right[rd]) {
			temp[r] = c;
			col[c] = 1, Left[ld] = 1, Right[rd] = 1;
			init(r + 1); // 递归下一行
			col[c] = 0, Left[ld] = 0, Right[rd] = 0;
		}
	}
}

void init2(char g[][8]) {
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			g[i][j] = '+';
}

void pnt(char g[][8]) {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++)
			cout << g[i][j];
		cout << endl;
	}

}

int main() {
	init(0); // 初始化所有情况
//	int Case;
//	int Board[8][8];
//	cin >> Case;
//	while (Case--) {
//		for (int i = 0; i < 8; i++) {
//			for (int j = 0; j < 8; j++) {
//				scanf("%d", &Board[i][j]); // 输入棋盘方格的数值
//			}
//		}
//		int ans = 0, sum;
//		for (int k = 0; k < n; k++) {
//			sum = 0;
//			for (int j = 0; j < 8; j++) {
//				sum += Board[j][p[k][j]];
//			}
//			if (sum > ans)
//				ans = sum;
//		}
//		cout << ans << endl;
//	}
	char map[8][8];
	for (int i = 0; i < n; i++) {
		init2(map);
		for (int j = 0; j < 8; j++) { // 每一行
			map[j][p[i][j]] = '*'; // 放棋子的位置
		}
		pnt(map);
		cout << endl << endl;
	}
}
// �ݹ顢����
/*Red and Black����ĳ����ש��ͨ�ĺ�ש����
//*/
#include <iostream>





















//using namespace std;
//const int N = 25;
//char g[N][N]; // ��ͼ
//int sx, sy;
//int ans;
//int n, m;
//
//bool vis[N][N]; // ��������
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
//					sx = i, sy = j; // ���λ��
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
The Sultan's Successors �˻ʺ�����
*/
#include <cstdio>
#include <vector>
using namespace std;
int p[1000][9]; // p[i][j]��¼��i�з�����ÿһ�������ӵ���λ��
int temp[8]; // 0~7���з������ӵ���λ��
bool col[8];
bool Left[15];
bool Right[15];
int n = 0;
void init(int r) { // ������r��
	if (r == 8) { // 0~7���������
		for (int i = 0; i < 8; i++) {
			p[n][i] = temp[i];
		}
		n++;
		return;
	}
	for (int c = 0; c < 8; c++) { // ��r�еĵ�c��
		int ld = r + c, rd = c - r + 7;
		if (!col[c] && !Left[ld] && !Right[rd]) {
			temp[r] = c;
			col[c] = 1, Left[ld] = 1, Right[rd] = 1;
			init(r + 1); // �ݹ���һ��
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
	init(0); // ��ʼ���������
//	int Case;
//	int Board[8][8];
//	cin >> Case;
//	while (Case--) {
//		for (int i = 0; i < 8; i++) {
//			for (int j = 0; j < 8; j++) {
//				scanf("%d", &Board[i][j]); // �������̷������ֵ
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
		for (int j = 0; j < 8; j++) { // ÿһ��
			map[j][p[i][j]] = '*'; // �����ӵ�λ��
		}
		pnt(map);
		cout << endl << endl;
	}
}
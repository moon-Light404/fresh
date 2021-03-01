#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 6;





char g[N][N], backup[N][N];  // 备份数组
int dx[5] = {-1, 0, 1, 0, 0}, dy[5] = {0, 1, 0, -1, 0};


void turn(int x, int y) {
	for (int i = 0; i < 5; i++) {
		int a = x + dx[i];
		int b = y + dy[i];

		if (a < 0 || a > 4 || b < 0 || b > 4)
			continue;

		g[a][b] ^= 1;
	}
}

int main() {
	int T;
	cin >> T;
	while (T--) {

		for (int i = 0; i < 5; i++)
			cin >> g[i]; // 输入字符串数组
		int res = 10;

		for (int op = 0; op < 32; op++) {
			memcpy(backup, g, sizeof g);
			int step = 0;
			for (int i = 0; i < 5; i++) {
				// op表示操作1表示该为按，0表示不按
				if (op >> i & 1) {
					step++;
					turn(0, i);
				}
			}

			for (int i = 0; i < 4; i++)
				for (int j = 0; j < 5; j++)
					if (g[i][j] == '0') {
						step++;
						turn(i + 1, j);
					}

			bool dark = false;
			for (int i = 0; i < 5; i++) {
				if (g[4][i] == '0') {
					dark = true;
					break;
				}
			}

			if (!dark)
				res = min(res, step); // 更新最小值
			memcpy(g, backup, sizeof g);

		}
		if (res > 6)
			res = -1;

		cout << res << endl;

	}
	return 0;
}
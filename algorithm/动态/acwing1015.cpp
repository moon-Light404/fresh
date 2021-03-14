#include <iostream>
using namespace std;

const int N = 105;
int a[N][N], f[N][N];
int q, row, col;

int main() {
	cin >> q;
	while (q--) {
		cin >> row >> col;
		for (int i = 1; i <= row; i++) {
			for (int j = 1; j <= col; j++) {
				cin >> a[i][j];
				f[i][j] = max(f[i - 1][j], f[i][j - 1]) + a[i][j];
			}
		}

		// f[i][j]指的是到(i, j)的最大花生数
//		for (int i = 1; i <= row; i++) {
//			for (int j = 1; j <= col; j++) {
//
//			}
//		}

		cout << f[row][col] << endl;
	}

	return 0;
}


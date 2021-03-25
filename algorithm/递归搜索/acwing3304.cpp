#include <iostream>
#include <algorithm>
#include <cstdio>
int s[110][110], n;
int f[110][110][110];


int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++)
			scanf("%d", &s[i][j]);
	}
	for (int i = 1; i <= n; i++)
		f[n][i][0] = s[n][i];/*在最后一层n，向左下走0步的最大值即为s[n][i]*/
	for (int i = n - 1; i >= 1; i--) { /*从下面往上遍历，避免边界等问题*/
		for (int j = 1; j <= i; j++) {
			for (int k = 0; k <= n - i; k++) {
				f[i][j][k] = f[i + 1][j + 1][k] + s[i][j]; /*从右下上来*/
				if (k >= 1)
					f[i][j][k] = std::max(f[i][j][k], f[i + 1][j][k - 1] + s[i][j]);
			}
		}
	}
	int res = 0;
	if (n % 2 == 1)
		printf("%d", f[1][1][(n - 1) / 2]);
	else
		printf("%d", std::max(f[1][1][(n - 1) / 2], f[1][1][(n - 1) / 2 + 1]));
	return 0;
}


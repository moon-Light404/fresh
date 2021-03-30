#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 105;
int f[N][N]; // f[i][j]表示从前i个物品中选，总和除以k的余数是j,求得是最大值
int w[N]; // 糖果数
// f[i][j] = f[i - 1][j] , f[i - 1][(j-w + n)%n] + w
// 选与不选之分，选的话那么前i-1个物品 + 第 i 个物品w 有余数的性质 余数为(j-w+n)%n
int main() {
	int m, n;
	cin >> m >> n; // n 是余数
	memset(f, -0x3f, sizeof f);
	f[0][0] = 0; // f数组表示的是值
	// f[0][i]都是无意义的,如果初始化为0的话结果会不正确
	for (int i = 1; i <= m; i++)
		cin >> w[i];

	for (int i = 1; i <= m; i++)
		for (int j = 0; j < n; j++) {
			cout << "现在是前几件物品：" << i << endl;
			cout << "现在的余数为:" << j << endl;
			f[i][j] = max(f[i - 1][j], f[i - 1][(j - w[i] % n + n) % n] + w[i]);
			cout << "余数应该为:" << (j - w[i] % n + n) % n << endl;
			cout << "前" << i << "个数加起来的余数为" << j << "的最大值" << f[i][j] << endl;
			cout << endl;
		}
	cout << f[m][0];
	return 0;
}
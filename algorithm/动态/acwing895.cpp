#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;

int n;
int a[N];
int f[N];

int main() {
	cin >> n ;
	for (int i = 1; i <= n; i ++ )
		cin >> a[i];

	int res = 0; // f[i] 表示的是以第i个数结尾的子序列的最大长度

	for (int i = 1; i <= n; i ++ ) {

		f[i] = 1; // 每次循环到第 i 个数就初始化为1

		for (int j = 1; j < i; j ++ )
			if (a[i] > a[j])
				f[i] = max(f[i], f[j] + 1);

		res = max(res, f[i]); // 将第二层循环得到的f[i]比较最大值记录下来
		// 测试语句
		for (int i = 1; i <= n; i++)
			cout << f[i] << ' ';
		cout << endl;
	}


	cout << res << endl;

	return 0;
}


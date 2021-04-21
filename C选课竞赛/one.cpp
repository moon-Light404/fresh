//#include <iostream>



//#include <cstring>
//#include <algorithm>
//using namespace std;
//const int N = 30;
//bool f[N + 1];
//int a[N + 1];
//int m, n, res;
//
//void dfs(int step, int sum, int num) { // num表示种了几棵树 step表示第几个花坛
//	if (num > m)
//		return;
//	if (step == n) { // 边界
//		if (!f[0] || !f[n - 1] && num == m) {
//			res = max(res, sum);
//		}
//		return;
//	}
//	if (step == 0) {
//		// 不种
//		dfs(step + 1, sum, num);
//		// 种
//		f[step] = true;
//		dfs(step + 1, sum + a[step], num + 1);
//		f[step] = false;
//		return;
//	}
//	if (!f[step - 1]) {
//		// 种树
//		f[step] = true;
//		dfs(step + 1, sum + a[step], num + 1);
//		f[step] = false;
//	}
//	// 不种树
//	dfs(step + 1, sum, num);
//
//}
//
//int main() {
//	cin >> n >> m;
//	for (int i = 0; i < n; i++) {
//		cin >> a[i];
//	}
//	if (m > n / 2) {
//		cout << "Error!" << endl;
//	} else {
//		res = 0;
//		dfs(0, 0, 0);
//		cout << res;
//	}
//
//	return 0;
//}
#include <iostream>

#include <algorithm>

#include <cmath>

#include <string.h>

using namespace std;

typedef long long ll;

int n;

int length[100];

int mark[100];

int stick_num;

int len;

int cmp(int a, int b) {

	?    ? return a > b;

}



int dfs(int nowLen, int nowGet, int cnt)

{

	?    if (cnt >= n)
		? return 0;

	?    ? if (nowGet == stick_num)
		? return 1;

	?    ? for (int i = cnt; i < n; i++)

		?    ? {

		?    ?    ? if (mark[i] == 0)

			?    ?    ? {

			?    ?    ?    ?    ? if (nowLen + length[i] == len)

				?    ?    ?    ?    ?    {

				?    ?    ?    ?    ?    ?    ? mark[i] = 1;

				?    ?    ?    ?    ?    ?    ? if (dfs(0, nowGet + 1, nowGet) == 1)
					? return1;

				?    ?    ?    ?    ?    ?    ? mark[i] = 0;

				?    ?    ?    ?    ?    ?    ? return 0;

				?    ?    ?    ?    ?    ?
			}

			?    ?    ?    ?    ? else if (nowLen + length[i] < len)

				?    ?    ?    ?    ? {

				?    ?    ?    ?    ?    ? mark[i] = 1;

				?    ?    ?    ?    ?    ? if (dfs(nowLen + length[i], nowGet, i + 1) == 1)
					? return1;

				?    ?    ?    ?    ?    ? mark[i] = 0;

				?    ?    ?    ?    ?    ? if (nowLen == 0)
					? return 0;

				?    ?    ?    ?    ?    ? for (; length[i] == length[i + 1] && i + 1 < n; i++);

				?    ?    ?    ?    ?
			}

			?    ?    ?
		}

		?    ?
	}

	?    ? return 0;

}

int main()

{

	? int i = 0;

	? int sum = 0;

	? cin >> n;

	? sum = 0;

	? for (int i = 0; i < n; i++)

		? {

		?    ? cin >> length[i];

		?    ? sum += length[i];

		?
	}

	? sort(length, length + n, cmp);

	? for (len = length[0]; len <= sum; len++)

		? {

		?    ? if (sum % len != 0)
			? continue;

		?    ? stick_num = sum / len;

		?    ? if (dfs(0, 0, 0) == 1)
			? break;

		?
	}

	? cout << len << endl;

}

? return 0;

}
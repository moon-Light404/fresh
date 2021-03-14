// 先遍历b数组，找出a数组中小于bi的个数和c数组中大于bi的个数
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 100010;
int a[N], b[N], c[N];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &b[i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &c[i]);

	sort(a, a + n);
	sort(b, b + n);
	sort(c, c + n);

	long long int  res = 0;
	for (int i = 0; i < n; i++) {
		int da = b[i];

		// 求a数组中第一个小于bi的下标
		int low = 0, high = 0;
		int l = 0, r = n - 1;
		while (l < r) { // 若a中数组没有比bi小的,那么r就一直减减,此时l=r等于0，满足条件数为0
			int mid = l + r + 1 >> 1;
			if (a[mid] < da)
				l = mid;
			else
				r = mid - 1;
		}

		low = l + 1;

		l = 0, r = n - 1;

		// 找到c数组中第一个大于bi的下标
		while (l < r) { // 这里也是一样，若c数组没有比bi大的
			int mid = l + r >> 1;
			if (c[mid] > da)
				r = mid;
			else
				l = mid + 1;
		}
		high = n - l;
		cout << "low的值" << low << endl;
		cout << " high的值" << high << endl;
		res += 1ll * low * high; // 把结果转为ll类型
	}
	cout << res << endl;
	return 0;
}
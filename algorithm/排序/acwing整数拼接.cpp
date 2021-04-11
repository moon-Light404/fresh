#include <iostream>
#include <cstring>
using namespace std;
const int N = 100010;
typedef long long ll;
int cnt[11][N]; // cnt[i][j]乘以10的i次方余上k = j的数的个数
int a[N];
int n, m;

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	for (int i = 0; i < n; i++) {
		ll t = a[i] % m;
		for (int j = 0; j < 11; j++) {
			cnt[j][t] ++; // 10的j次方 余数为t
			t = t * 10 % m;
		}
	}
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		ll t = a[i] % m;
		int len = to_string(a[i]).size();
		ans += cnt[len][(m - t) % m];
		// 判断是不是重复使用了同一个数
		ll r = t;
		while (len--)
			r = r * 10 % m;
		if (r == (m - t) % m)
			ans--;
	}
	cout << ans;
	return 0;
}
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;
int T;
int n, k, m; // 人数  原料的种树  动作数
int happ[N]; // 开心值
// 0 - m-1 编号动作
// 0 - n-1 人编号
int fav[N]; // 喜欢的原料
set<int> ss;

void move(int t) {
	int tt = t % n; // 第几个人做这个move
	if (ss.count(fav[tt])) {
		ss.erase(fav[tt]); // 吃掉最喜欢的原料fav
		happ[tt]++;
	} else {
		ss.insert(fav[tt]);
	}
}

int main() {
	cin >> T;
	while (T--) {
		memset(happ, 0, sizeof happ);
		ss.clear();
		cin >> n >> k >> m;
		for (int i = 0; i < n; i++)
			cin >> fav[i];
		// 遍历动作
		for (int t = 0; t < m; t++) {
			move(t);
		}
		for (int i = 0; i < n; i++)
			cout << happ[i] << " ";
		cout << endl;
	}
	return 0;
}
//#include <bits/stdc++.h>
//using namespace std;
//typedef long long ll;
//ll a1, a2, a3, d1, d2, d3, t;
//
//int main() {
//	cin >> t;
//	while (t--) {
//		cin >> a1 >> a2 >> a3 >> d1 >> d2 >> d3;
//		ll ans = 0;
//		if (a1 <= d2) {
//			ans += a1;
//			d2 -= a1;
//			a1 = 0;
//			if (a2 <= d3) {
//				ans += a2;
//				d3 -= a2;
//				a2 = 0;
//				if (a3 <= d1) {
//					ans += a3;
//					d1 -= a3;
//					a3 = 0;
//				} else if (a3 > d1) {
//					ans += d1;
//					a3 -= d1;
//					d1 = 0;
//				}
//			} else if (a2 > d3) {
//				ans += d3;
//				a2 -= d3;
//				d3 = 0;
//				if (a3 <= d1) {
//					ans += a3;
//					d1 -= a3;
//					a3 = 0;
//				}
//				if (a3 > d1) {
//					ans += d1;
//					a3 -= d1;
//					d1 = 0;
//				}
//			}
//		} else if (a1 > d2) {
//			ans += d2;
//			a1 -= d2;
//			d2 = 0;
//			if (a2 <= d3) {
//				ans += a2;
//				d3 -= a2;
//				a2 = 0;
//				if (a3 <= d1) {
//					ans += a3;
//					d1 -= a3;
//					a3 = 0;
//				} else if (a3 > d1) {
//					ans += d1;
//					a3 -= d1;
//					d1 = 0;
//				}
//			} else if (a2 > d3) {
//				ans += d3;
//				a2 -= d3;
//				d3 = 0;
//				if (a3 <= d1) {
//					ans += a3;
//					d1 -= a3;
//					a3 = 0;
//				} else if (a3 > d1) {
//					ans += d1;
//					a3 -= d1;
//					d1 = 0;
//				}
//			}
//		}
//		ll aa = d1, bb = d2, cc = d3;
//		d1 = d1 - min(d1, a1);
//		d2 = d2 - min(d2, a2);
//		d3 = d3 - min(d3, a3);
//		a1 = a1 - min(aa, a1);
//		a2 = a2 - min(bb, a2);
//		a3 = a3 - min(cc, a3);
//		ll sum = d1 + d2 + d3 + a1 + a2 + a3;
//		sum /= 2;
//		ans -= sum;
//		cout << ans << endl;
//	}
//
//	return 0;
//}




//#include <bits/stdc++.h>
//using namespace std;
//typedef long long ll;
//const int N = 1e5 + 1;
//int n, k;
//int cnt;
//int main() {
//	cin >> n >> k;
//	cnt = 0;
//	for (int i = 1; i <= k; i++) {
//		for (int j = 0; j * k <= n - i; j++) {
//			cnt++;
//			if (cnt < n) {
//				cout << j *k + i << " "; // 格式
//			} else
//				cout << j *k + i;
//		}
//	}
//	return 0;
//}


#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;
int n, k, m, a[N], b[N], c[N];
int main() {
	int T;
	cin >> T;
	while (T--) {
		cin >> n >> k >> m;
		for (int i = 0; i < k; i++)
			b[i] = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			c[i] = 0;
		}

		for (int i = 1; i < min(2 * n, m); i++) {
			int t = i % n;
			if (!t)
				t = n;
			if (b[a[t]]) {
				c[t]++;
				b[a[t]] = 0;
			} else
				b[a[t]] = 1;
		}
		if (m > 2 * n) {
			int t1 = m / (2 * n), t2 = m % (2 * n);
			for (int i = 0; i < n; i++)
				c[i] = c[i] * t1;
			for (int i = 0; i < k; i++)
				b[i] = 0;
			for (int j = 0; j < t2; j++)	{
				int t = j % n;
				if (!t)
					t = n;
				if (b[a[t]]) {
					c[t]++;
					b[a[t]] = 0;
				} else
					b[a[t]] = 1;
			}
		}
		for (int h = 0; h < n; h++)
			cout << c[h] << " ";
		cout << endl;
	}
	return 0;
}
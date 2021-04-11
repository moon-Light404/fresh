#include <iostream>
#include <cstring>
using namespace std;
const int N = 100010;
typedef long long ll;
int cnt[11][N]; // cnt[i][j]����10��i�η�����k = j�����ĸ���
int a[N];
int n, m;

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	for (int i = 0; i < n; i++) {
		ll t = a[i] % m;
		for (int j = 0; j < 11; j++) {
			cnt[j][t] ++; // 10��j�η� ����Ϊt
			t = t * 10 % m;
		}
	}
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		ll t = a[i] % m;
		int len = to_string(a[i]).size();
		ans += cnt[len][(m - t) % m];
		// �ж��ǲ����ظ�ʹ����ͬһ����
		ll r = t;
		while (len--)
			r = r * 10 % m;
		if (r == (m - t) % m)
			ans--;
	}
	cout << ans;
	return 0;
}
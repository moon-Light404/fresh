#include <iostream>
using namespace std;
const int N = 10;
int s[N];
bool vis[N];
int ans;

void dfs(int n) {
	if (n == 10) {
		int a, b, c, def, ghi;
		a = s[1], b = s[2], c = s[3];
		def = s[4] * 100 + s[5] * 10 + s[6];
		ghi = s[7] * 100 + s[8] * 10 + s[9];
		if (b * ghi + c * def == (10 - a)*c * ghi)
			ans++;
		return;
	}
	for (int i = 1; i <= 9; i++) {
		if (!vis[i]) {
			vis[i] = true;
			s[n] = i;
			dfs(n + 1);
			
			vis[i] = false;
		}
	}
}

int main() {
	dfs(1);
	cout << ans;
	return 0;
}
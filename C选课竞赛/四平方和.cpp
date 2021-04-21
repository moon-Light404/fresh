#include <iostream>
#include <cmath>
using namespace std;
int res[4];
int k = 0;
bool flag = false;

void dfs(int sum, int k) {
	if (flag) {
		return;
	}
	if (k == 4) {
		if (sum == 0) {
			flag = true;
			for (int j = 0; j < 4; j++)
				cout << res[j] << " ";
		}
		return;
	}
	for (int i = 0; i <= sqrt(sum) && !flag; i++) {
		res[k++] = i;
		dfs(sum - i * i, k);
		k--;
	}

}

int main() {
	int n, t;
	cin >> t;
	while (t--) {
		flag = false;
		cin >> n;
		dfs(n, 0);
	}
//	cin >> n;
//	dfs(n, 0);
	return 0;
}
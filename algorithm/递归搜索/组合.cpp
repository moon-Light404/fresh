#include <iostream>
using namespace std;
const int N = 110;
long long res[N][N];

long long C(int n, int m) { // C n M×éºÏÊı
	if (m == n || m == 0)
		return 1;
	if (res[n][m])
		return res[n][m];
	return res[n][m] = C(n - 1, m) + C(n - 1, m - 1);
}

int main() {
	int n = 50;
//	for (int i = 0; i <= n; i++) {
//		res[i][0] = res[i][i] = 1;
//	}
	cout << C(5, 2) << endl;
	return 0;
}
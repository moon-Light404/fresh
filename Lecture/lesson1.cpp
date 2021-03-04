#include <iostream>
using namespace std;

int n;
int ans = 1;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		ans *= n;
		ans %= 1000;
	}
	if (ans >= 100)
		cout << ans << endl;
	else
		printf("0%d\n", ans);
	return 0;
}

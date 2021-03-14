#include <iostream>
using namespace std;









//int main() {
//	int w, h;
//	cin >> w >> h;
//	int ans = 0;
//	while (w != h) {
//		if (w > h) {
//			w = w - h;
//			ans++;
//		} else {
//			h = h - w;
//			ans++;
//		}
//	}
//	cout << ans + 1 << endl;
//	return 0;
//}
bool is_vivid(int s) {
	while (s) {
		int a;
		a = s % 10;
		if (a == 2 || a == 0 || a == 1 || a == 9)
			return true;

		s /= 10;
	}
	return false;

}

int main() {
	int ans = 0, n; // ¼ÇÂ¼ºÍÖµ
	cin >> n;
	for (int i = 1; i <= n; i++) {
		if (is_vivid(i)) {
//			cout << i << endl;
			ans += i;
		}
	}
	cout << ans << endl;

	return 0;
}
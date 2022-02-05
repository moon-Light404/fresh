#include <iostream>
#include <map>
#include <iterator>
using namespace std;
const int N = 200010;
int a[N]; // 定义一个数组

int main() {
	int T;
	cin >> T; // T组数据
	while (T--) {
		int n;
		cin >> n;
		map<int, int> m; // 数字+出现次数
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			m[a[i]]++;
		}
		int num = -2e9;
		// 找出次数最小的数
		map<int, int>::iterator iter;
		for (iter = m.begin(); iter != m.end(); iter++ ) {
			if (iter->second == 1) { // 出现一次的数
				num = iter->first;
				break;
			}
		}
		if (num == -2e9) {
			cout << -1 << endl;
		} else {
			for (int i = 1; i <= n; i++) {
				if (a[i] == num) {
					cout << i << endl;
					break;
				}
			}
		}
	}
	return 0;
}
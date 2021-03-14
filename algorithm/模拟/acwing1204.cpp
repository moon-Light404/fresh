#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

const int N = 10010;
int a[N];
bool exist[N];
int m, d; // 断号和重号
int main() {
	int n;
	cin >> n;
	string line;
	getline(cin, line);
	while (n--) {
		getline(cin, line);
		stringstream ss(line);

		while (ss >> a[n]) {
			if (exist[a[n]])
				d = a[n]; // 重号
			else
				exist[a[n]] = true;
			n++;
		}
	}
	int k = 0;
	for (k = 0; !exist[k]; k++) { // 开始前几个都没出现，遍历找到第一个出现过的数字
	}
	for (int start = k; ; start++) {
		if (!exist[start])
			m = start;
	}
	cout << m << ' ' << d << endl;
	return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>>
using namespace std;

const int N = 1010;
vector<int> v[N]; // 每个兴趣对应的人
int main() {
	int n;
	cin >> n;
	int a, b, c, d;
	int ma = -10000;
	int temp;
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d%d", &a, &b, &c, &d);
		temp = max(max(b, c), d);
		if (temp > ma)
			ma = temp;

		v[b].push_back(a);
		v[c].push_back(a);
		v[d].push_back(a);
	}
	for (int i = 1; i <= ma; i++) {
		for (int j = 0; j < v[i].size(); j++)
			cout << v[i][j] << " ";
		cout << endl;
	}
	return 0;
}
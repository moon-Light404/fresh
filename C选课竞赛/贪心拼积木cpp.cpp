// 思路：我们肯定要优先满足那些不够的但是还需要数量比较少的小朋友，按照还需要的数量排序，
// 如果有一个人，
// 就算是全给他也不够，那这个游戏就无法进行下去了。

#include <iostream>
#include <algorithm>
using namespace std;
const int N = 10010;
int n; // 人数
struct node {
	int x, y, z;
	bool operator<(const node &t) const {
		return z < t.z;
	};
} p[N];

int main() {
	int m;
	cin >> m; // m组数据
	for (int i = 0; i < m; i++) {
		cin >> n; // 人数
		for (int j = 0; j < n; j++) {
			cin >> p[i].x >> p[i].y;
			p[i].z = p[i].y - p[i].x;
		}
		sort(p, p + n); // 把还需要多少积木从小到大排序
		bool st = true;
		int sum = 0;
		for (int i = 0; i < n; i++) {
			if (p[i].z <= 0)
				sum += p[i].x;
			// z < 0表示不需要这么多积木已经够了可以完成作品了
			else {
				if (p[i].z <= sum)
					sum += p[i].x; // 够完成作品，做完了就可以把小朋友的积木拿回来
				else {
					st = false;
					break;
				}
			}
		}
		if (st)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

	return 0;
}
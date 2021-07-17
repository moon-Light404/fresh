#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;
int N, L;
int d[100001], t[100001];
int R[1000001];
bool vis[1000001];
int M(3);
int chose[4];
int xchose[4];
set<long> cset;

void init() {
	cin >> N >> L;
	for (int i = 0; i < N; ++i) {
		cin >> d[i] >> t[i];
	}
	for (int i = 0; i <= L; ++i) {
		R[i] = i;
	}
	memset(vis, false, sizeof(bool) * 1000001);
	chose[3] = L;
}

long getCost(int i) {
	// 距离和人口数
	int td = d[i], tt = t[i];
	for (int j = 0; j < 4; ++j) {
		if (td > chose[j])
			continue;
		return (chose[j] - td) * tt;
	}
	return (L - td) * tt;
}

void process() {
	// 对于每一户人家，找到右边最近的，累加花销
	long cost(0);
	copy(chose, chose + 4, xchose);
	sort(xchose, xchose + 4);
	for (int i = 0; i < N; ++i) {
		long tcost = getCost(i);
		cost += tcost;
	}
	cset.insert(cost);
}

void dfs(int m) {
	if (m == 0) {
		process();
	} else {
		for (int i = 0; i < L; ++i) {
			if (!vis[i]) {
				chose[M - m] = R[i];
				vis[i] = true;
				dfs(m - 1);
				vis[i] = false;
			}
		}
	}
}

int main() {
	init();
	dfs(3);
	cout << *cset.begin();
	return 0;
}

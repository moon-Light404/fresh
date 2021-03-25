#include <iostream>
#include <cstring>
using namespace std;
const int MAXN = 505;
const int INF = 0x3f;
int value[MAXN];        //value[i]i城市的消防员个数
int g[MAXN][MAXN];      //存储每条边

int dis[MAXN];    //dis[i]表示到i的最短路
bool sign[MAXN];    //标记i是否是最短路
int cnt1[MAXN];     //cnt1[i]表示到i时的最短路个数
int cnt2[MAXN];     //cnt2[i]表示到i时的最短路的最多招集人数(不包含i城市的救援人数)
void dijkstra(int st, int n) {      //dijkstra求单源最短路
	memset(dis, INF, sizeof(dis));
	dis[st] = 0;
	cnt1[st] = 1;
	for (int i = 0; i < n - 1; i++) {
		int t = -1;
		for (int j = 0; j < n; j++) {
			if (!sign[j] && (t == -1 || dis[t] > dis[j])) {
				t = j;
			}
		}
		sign[t] = true;
		for (int j = 0; j < n; j++) {
			if (!sign[j] && dis[j] >= dis[t] + g[t][j]) {
				if (dis[j] == dis[t] + g[t][j]) {
					cnt1[j] += cnt1[t];     //表示有不同路径，但相同路径长的路径
				} else {
					cnt1[j] = cnt1[t];
				}
				cnt2[j] = max(cnt2[j], cnt2[t] + value[t]);     //更新最最多招集人数
				dis[j] = dis[t] + g[t][j];              //找到一个最短点，更新其他其到起点路径
			}
		}
	}
}

int main() {
	memset(g, INF, sizeof(g));
	int n, m, c1, c2;   //城市数、道路数、出发地、目的地
	cin >> n >> m >> c1 >> c2;
	for (int i = 0; i < n; i++) {
		g[i][i] = 0;
		cin >> value[i];
	}
	for (int i = 0; i < m; i++) {
		int a, b, l;
		cin >> a >> b >> l;
		g[a][b] = l;
		g[b][a] = l;
	}
	dijkstra(c1, n);
	//输出最多招集的救援人数时应加上本城市救援人数
	cout << cnt1[c2] << ' ' << cnt2[c2] + value[c2] << endl;
	return 0;
}

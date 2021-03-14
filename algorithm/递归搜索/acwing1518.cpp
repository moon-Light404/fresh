#include <iostream>
#include <string>
#include <map>
using namespace std;
const int maxn = 1010; // 总人数
const int INF = 1e9; // 无穷大

map<int, string> intToString; // 编号->姓名
map<string, int> stringToInt; // 姓名->编号
map<string, int> Gang; // head ->人数
int G[maxn][maxn], weight[maxn];
int n, k, numperson; // 边数n、下限k、总人数numperson;
bool vis[maxn]; // 标记是否被访问过

// 返回姓名对应的编号
int change(string s) {
	if (stringToInt.find(s) != stringToInt.end()) {
		return stringToInt[s]; // 返回编号
	} else {
		stringToInt[s] = numperson; // 设立编号
		intToString[numperson] = s; // 编号->姓名
		return numperson++; // 返回下标,且下标加1
	}
}
void dfs(int now, int &head, int &numMember, int &totalValue)

// 正在访问now, 头目head, 团伙数量numMember, 总边权重
{
	numMember++;
	vis[now] = true; // 标记来过
	if (weight[now] > weight[head]) {
		head = now; // 更新头目
	}
	for (int i = 0; i < numperson; i++) {
		if (G[now][i] > 0) { // 如果now能到达i
			totalValue += G[now][i];
			G[now][i] = G[i][now] = 0;
			if (vis[i] = false) {
				dfs(i, head, numMember, totalValue);
			}
		}
	}
}

void DFSTrave() {
	for (int i = 0; i < numperson; i++) {
		if (vis[i] == false) {
			int head = i, numMember = 0, totalValue = 0;
			dfs(i, head, numMember, totalValue);
			if (numMember >= 3 && totalValue > k) {
				Gang[intToString[head]] = numMember; // 头目姓名->成员数量
			}
		}
	}
}

int main() {
	int w;
	string s1, s2;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> s1 >> s2 >> w; // 端点和点权
		int id1 = change(s1);
		int id2 = change(s2);
		// 边权
		G[id1][id2] += w;
		G[id2][id1] += w;
		// 点权
		weight[id1] += w;
		weight[id2] += w;
	}
	// 枚举所有人
	DFSTrave();
	cout << Gang.size() << endl;
	map<string, int>:: iterator it;
	for (it = Gang.begin(); it != Gang.end(); it++) {
		cout << it->first << " " << it->second << endl;
	}
	return 0;
}
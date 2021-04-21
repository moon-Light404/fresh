#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
#include <cstring>
using namespace std;
string input, en;

map<string, bool> vis; // 标记该状态是否被访问过
struct node {
	string s;
	int step;
	node() {
		s = "";
		step = 0;
	}
} tmp;
int ans;

bool bfs(string s) {
	if (s == en) {
		cout << "0" << endl;
		return true;
	}
	queue<node> q;
	tmp.s = s;
	q.push(tmp);
	vis[tmp.s] = true;

	while (q.size()) {
		node top = q.front();
		q.pop();
		if (top.s == en) {
			cout << top.step << endl;
			return true;
		}
		int pos = top.s.find('.');
		// 开始寻找下一个状态
		// 向上
		if (pos - 3 >= 0) {
			string str = top.s;
			swap(str[pos], str[pos - 3]);
			if (vis[str] == false) {
				vis[str] = true;
				node t1;
				t1.s = str;
				t1.step = top.step + 1;
				q.push(t1);
			}
		}
		// 向下
		if (pos + 3 <= 8) {
			string str = top.s;
			swap(str[pos], str[pos + 3]);
			if (vis[str] == false) {
				vis[str] = true;
				node t1;
				t1.s = str;
				t1.step = top.step + 1;
				q.push(t1);
			}
		}

		// 向左
		if (pos - 1 >= 0 && pos - 1 != 2 && pos - 1 != 5) {
			string str = top.s;
			swap(str[pos], str[pos - 1]);
			if (vis[str] == false) {
				vis[str] = true;
				node t1;
				t1.s = str;
				t1.step = top.step + 1;
				q.push(t1);
			}
		}
		// 向右
		if (pos + 1 <= 8 && pos + 1 != 6 && pos + 1 != 3) {
			string str = top.s;
			swap(str[pos], str[pos + 1]);
			if (vis[str] == false) {
				vis[str] = true;
				node t1;
				t1.s = str;
				t1.step = top.step + 1;
				q.push(t1);
			}
		}
	}
	return false;

}

int main() {
	cin >> input >> en;
	if (bfs(input) == false) {
		cout << "-1" << endl;
	}
	return 0;
}
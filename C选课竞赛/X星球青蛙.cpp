#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
string s, e;

map<string, bool> vis; // ≈–÷ÿmap
struct state {
	string st;
	int step;
} tmp;

int bfs() {
	int len = s.length();
	queue<state> q;
	tmp.st = s;
	tmp.step = 0;
	q.push(tmp);
	vis[tmp.st] = true;
	state t2;
	while (q.size()) {
		t2 = q.front();
		q.pop();
		if (t2.st == e) {
			cout << t2.step;
			return 0;
		}
		int pos = t2.st.find('*');
		if (pos - 1 >= 0) {
			string str = t2.st;
			swap(str[pos], str[pos - 1]);
			if (vis[str] == false) {
				vis[str] = true;
				state t3 = {str, t2.step + 1};
				q.push(t3);
			}
		}

		if (pos + 1 < len) {
			string str = t2.st;
			swap(str[pos], str[pos + 1]);
			if (vis[str] == false) {
				vis[str] = true;
				state t3 = {str, t2.step + 1};
				q.push(t3);
			}
		}
		if (pos + 2 < len) {
			// ≤Ÿ◊˜¡Ÿ ±◊÷∑˚¥Æ
			string str = t2.st;
			swap(str[pos], str[pos + 2]);
			if (vis[str] == false) {
				vis[str] = true;
				state t3 = {str, t2.step + 1};
				q.push(t3);
			}
		}

		if (pos - 2 >= 0) {
			string str = t2.st;
			swap(str[pos], str[pos - 2]);
			if (vis[str] == false) {
				vis[str] = true;
				state t3 = {str, t2.step + 1};
				q.push(t3);
			}
		}

		if (pos - 3 >= 0) {
			string str = t2.st;
			swap(str[pos], str[pos - 3]);
			if (vis[str] == false) {
				vis[str] = true;
				state t3 = {str, t2.step + 1};
				q.push(t3);
			}
		}

		if (pos + 3 < len) {
			string str = t2.st;
			swap(str[pos], str[pos + 3]);
			if (vis[str] == false) {
				vis[str] = true;
				state t3 = {str, t2.step + 1};
				q.push(t3);
			}
		}
	}
	return -1;
}

int main() {
	cin >> s >> e;
	int t = bfs();
	if (t == -1)
		cout << "-1";
	return 0;
}
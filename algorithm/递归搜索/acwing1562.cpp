#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
const int N = 1010;


bool vis[N]; // 这个用户id加入过队列
struct Node {
	int id;
	int layer = 0; // 层数
};

vector<Node> fllowedby[N]; // 题目输入的是每个人关注的人，这里是被关注的人，即被关注的消息转发给关注的人 表示一条路
int BFSTrave(int s, int L) { // 起点和层数
	int numForward = 0; // 转发数
	Node start;
	start.id = s;

	queue<Node> q;
	q.push(start);
	vis[start.id] = true;
	while (q.size()) {
		auto t = q.front();
		q.pop();
		int u = t.id; // 记录当前用户id

		for (int i = 0; i < fllowedby[u].size(); i++) { // 遍历该用户的关注者
			Node next = fllowedby[u][i];
			next.layer = t.layer + 1; // 下一层
			if (vis[next.id] == false && next.layer <= L) {
				q.push(next);
				vis[next.id] = true; // 标记入队
				numForward++; // 转发数加1
			}
		}

	}
	return numForward;

}

int main() {
	Node user;
	int n, L;
	int numfllow, idfllow; // 关注的人数和id
	scanf("%d%d", &n, &L);
	for (int i = 1; i <= n; i++) {
		user.id = i;
		scanf("%d", &numfllow);
		for (int j = 0; j < numfllow; j++) {
			scanf("%d", &idfllow);
			fllowedby[idfllow].push_back(user);
		}

	}
	int numQuery, s; // 查询个数和转发用户id
	scanf("%d", &numQuery);
	for (int i = 0; i < numQuery; i++) {
		memset(vis, false, sizeof vis);
		scanf("%d", &s);
		int numForward = BFSTrave(s, L);
		printf("%d\n", numForward);
	}
	return 0;
}
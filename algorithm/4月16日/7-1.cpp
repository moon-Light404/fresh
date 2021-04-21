//#include <iostream>

//using namespace std;
////
////int main() {
////	int ans = 0;
////	for (int i = 10; i <= 150; i++) {
////		int fa_age = i;
////		int temp = i;
////		int son_age = 0;
////		while (fa_age) {
////			son_age = son_age * 10 + (fa_age % 10);
////			fa_age /= 10;
////		}
////		if (temp - son_age == 27)
////			ans++;
////	}
////	cout << ans;
////	return 0;
////}



// 生日蜡烛
//#include <iostream>
//using namespace std;
//
//int main() {
//	for (int i = 1; i < 30; i++) {
//		int sum = 0;
//		for (int start = i; start < 50; start++) {
//			sum += start;
//			if (sum == 236) {
//				cout << i << endl;
//				break;
//			}
//		}
//	}
//	return 0;
//}














































































































































































// 方格填数 答案：1580
//
//#include <iostream>
//#include <cstring>
//#include <cmath>
//using namespace std;
//int mp[5][5];
//int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
//
//int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
//bool vis[11]; // 排列数标记
//int ans; // 记录方案
//
//bool check(int k, int x, int y) {
//	for (int i = 0; i < 8; i++) {
//		int nx = x + dx[i], ny = y + dy[i];
//		if (mp[nx][ny] != -1 && (nx != 1 || ny != 1) && (nx != 3 || ny != 4)
//		        && nx < 4 && nx >= 1 && ny >= 1 && ny < 5) {
//			// 差为1不满足条件
//			if (abs(mp[nx][ny] - k ) == 1)
//				return false;
//		}
//	}
//	return true;
//}
//
//void dfs(int sx, int sy) { // 该点的坐标
//	for (int k = 0; k < 10; k++) {
//		if (!vis[k] && check(k, sx, sy)) {
//			if (sx == 3 && sy == 3) {
//				ans++;
//				return;
//			}
//			mp[sx][sy] = k; // 填数
//			vis[k] = true;
//			if (sy == 4) { // 一行的最后一个数
//				dfs(sx + 1, 1);
//			} else
//				dfs(sx, sy + 1); // 这一行的下一个数
//			vis[k] = false;
//			mp[sx][sy] = -1;
//		}
//	}
//}
//
//int main() {
//	memset(mp, -1, sizeof mp); // 没有填的格子标记为-1
//	dfs(1, 2); // 第一行第二列格子
//	cout << ans;
//	return 0;
//}
//


















































// 寒假作业
//#include <iostream>
//using namespace std;
//
//int a[20];
//bool vis[20];
//int ans = 0;
//void dfs(int u) {
//	// 剪枝
//	if (u >= 4 && a[1] + a[2] != a[3])
//		return;
//	if (u >= 7 && a[4] - a[5] != a[6])
//		return;
//	if (u >= 10 && a[7]*a[8] != a[9])
//		return;
//	if (u >= 13) { // 说明上述条件都通过了
//		if (a[12]*a[11] == a[10])
//			ans++;
//		return;
//	}
//	for (int i = 1; i <= 13; i++) {
//		if (!vis[i]) {
//			vis[i] = true;
//			a[u] = i;
//			dfs(u + 1); // 下一个位置
//			vis[i] = false;
//		}
//	}
//	return;
//}
//
//int main() {
//	dfs(1); // 下标从1开始
//	cout << ans;
//	return 0;
//}









































































































































// 剪邮票(wrong)
//#include <iostream>
//#include <set>
//#include <algorithm>
//using namespace std;
//set<set<int>> ss;
//int a[5][5];
//
//
//
//
////
//int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, 1, -1};
//int ans;
//bool vis[20][20];
//
//void dfs(set<int>s, int sx, int sy) {
//	// 提前判断5个格子
//	if (s.size() == 5) {
//		if (!ss.count(s)) {
//			ss.insert(s);
//			ans++;
//		}
//		return;
//	}
//	// 如果没有满5个格子,继续dfs
//	if (sx > 3 || sx < 1 || sy > 4 || sy < 1)
//		return;
//	if (vis[sx][sy])
//		return;
//	s.insert(a[sx][sy]);
//	vis[sx][sy] = true;
//	dfs(s, sx + 1, sy);
//	dfs(s, sx - 1, sy);
//	dfs(s, sx, sy + 1);
//	dfs(s, sx, sy - 1);
//	vis[sx][sy] = false;
//	s.erase(a[sx][sy]);
//}
//
////
//
//int main() {
//	int k = 1;
//	for (int i = 1; i <= 3; i++) { // 行和列
//		for (int j = 1; j <= 4; j++) {
//			a[i][j] = k++;
//		}
//	}
//	set<int>s;
//	for (int i = 1; i <= 3; i++) {
//		for (int j = 1; j <= 4; j++) {
//			dfs(s, i, j);
//		}
//	}
//	cout << ans;
//	return 0;
//


//
//
//
//// 剪邮票
//#include <bits/stdc++.h>
//using namespace std;
//long long ans = 0;
//int ss[3][4] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
//
//void dfs(int x, int y) { // dfs深度计算有几个连通块
//	if (x > 2 || x < 0 || y > 3 || y < 0)
//		return ;
//	//运行到这里，说明已经越界了，则需要返回上一级的dfs()，然后换个方向继续寻找
//	if (ss[x][y] == 0)
//		return ;
//	//这里，就是这个点不是需要剪的位置，则返回上一级的dfs()函数，
//	//继续执行未完成的dfs()函数，也就是换个方向继续找
//	ss[x][y] = 0;  //找到了，则将这个点标记
//	dfs(x + 1, y); // 把所有与开始标记的那个点相邻的格子都值为0
//	dfs(x, y + 1);
//	dfs(x - 1, y);
//	dfs(x, y - 1);
//
//}
//
////判断某5个数是否可行
//bool cc(int a[12]) {
//	int k = 0;
//	int x, y; //起点
//	for (int i = 0; i < 3; i++) {
//		for (int j = 0; j < 4; j++) {
//			if (a[k] == 1) {
//				x = i;
//				y = j;  //起点，就是从这个点，开始往四周寻找
//			}
//			ss[i][j] = a[k++]; // 赋值
//		}
//	}
//	dfs(x, y);   //开始寻找
//	int flag = 0;
//
//	for (int i = 0; i < 3; i++) {
//		for (int j = 0; j < 4; j++) {
//			if (ss[i][j] == 1)
//				flag = 1;
//			//5个邮票中存在没有遍历到的，也就是存在一个数，周围没有连着
//		}
//	}
//	if (flag == 1)
//		return false;
//	return true;
//}
//
//int main() {
//	int a[12] = {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1}; // a中1表示选这个格子
//	do {
//		if (cc(a))
//			ans++;
//	} while (next_permutation(a, a + 12));   //对a数组进行全排列，没有重复的
//	//  next_permutatio n每执行一次，都要调用 cc()函数 ，形成一种全排列
//
//	cout << ans;
//	return 0;
//}
//
//#include <bits/stdc++.h>
//using namespace std;
//const int N = 1e5 + 10;
//typedef long long ll;
//char str[N];
//int pre[N]; // pre[i]记录第几个位置内的字母上一次出现的位置
//int nex[N]; // nex[i]记录第i个位置的字母下一次出现的位置
//int h[26]; // 每一次更新a-z字母出现的下标(下标从1开始，表示第几个位置)
//ll ans;
//int main() {
//	scanf("%s", str + 1); // 从下标为1开始输入字符串
//	int len = strlen(str + 1);
//
//	for (int i = 1; i <= len; i++) {
//		int t = str[i] - 'a'; // 用下标表示字母 a-0 b-1 c-2 d-3 e-4.....
//		pre[i] = h[t];  // z这里有个技巧可以看到有两个t每次循环都在记录某一个字母新出现的位置,而这里恰好是在h[t]更新之前把h[t]赋给pre[i]-----记录第几个位置内的字母上一次出现的位置
//		h[t] = i;
//	}
//	for (int i = 0; i < 26; i++)
//		h[i] = len + 1;
//	for (int i = len; i >= 1; i--) {
//		int t = str[i] - 'a';
//		nex[i] = h[t]; // 这里同理,这里每个位置都会更新，如果没有出现下一个同样的字母,默认下一个为len+1
//		h[t] = i;
//	}
//	for (int i = 1; i <= len; i++) {
//		cout << pre[i] << " " ;
//	}
//	cout << endl;
//	for (int i = 1; i <= len; i++) {
//		cout << nex[i] << " ";
//	}
//	cout << endl;
//	for (int i = 1; i <= len; i++) {
//		ans += (ll)(i - pre[i]) * (nex[i] - i);
//	}
//	cout << ans << endl;
//	return 0;
//}

// 随意组合

//#include <iostream>
//using namespace std;
//const int N = 10;
//int a[4] = {2, 3, 5, 8}, b[4] = {1, 4, 6, 7};
//int c[N];
//bool vis[10]; // 标记数字是否被选过
//int ans;
//void dfs(int u) {
//	if (u == 4) {
//		int num1 = 0, num2 = 0;
//		for (int i = 0; i < 4; i++) {
//			num1 += c[i] * 10 + b[i];
//			num2 += b[i] * 10 + c[i];
//		}
//		if (num1 == num2) {
//			ans++;
//		}
//	}
//	for (int i = 0; i < 4; i++) {
//		if (!vis[a[i]]) {
//			vis[a[i]] = true;
//			c[u] = a[i];
//			dfs(u + 1);
//			vis[a[i]] = false;
//		}
//	}
//}
//int main() {
//	dfs(0);
//	cout << ans << endl;
//	return 0;
//}

// 密码脱落
//#include <iostream>
//#include <algorithm>
//using namespace std;
//const int  N = 1100;
//char a[N];
//int f[N][N]; // f[i][j]表示i到j之间的最大回文子串
//int main() {
//	cin >> a + 1;
//	int maxlen = strlen(a + 1);
//	for (int i = 1; i <= maxlen; i++)
//		f[i][i] = 1; // 初始化
//	for (int len = 1; len < maxlen; len++) { // 长度
//		for (int i = 1; i + len <= maxlen; i++ ) { // 起点
//			int r = i + len ; // 右端点
//			if (a[r] == a[i])
//				f[i][r] = f[i + 1][r - 1] + 2;
//
//			f[i][r] = max(f[i][r], f[i][r - 1]);
//			f[i][r] = max(f[i][r], f[i + 1][r]);
//		}
//	}
//	cout << maxlen - f[1][maxlen] << endl;
//	return 0;
//}


// 最大比例
//#include <iostream>
//#include <algorithm>
//using namespace std;
//int gcd(int a, int b) {
//	return b ?  gcd(b, a % b) : a;
//}
//int gcd_sub(int a, int b) { // 最大公底数
//	if (a < b)
//		swap(a, b);
//	if (b == 1)
//		return a;
//	return gcd_sub(b, a / b);
//}
//
//int main() {
//	int a, b;
//	while (1) {
//		cin >> a >> b;
//		cout << gcd_sub(a, b) << endl;
//	}
//
//	return 0;
//}

// 迷宫
//#include <iostream>
//#include <algorithm>
//#include <cstring>
//using namespace std;
//int ans;
//char mp[20][20] = {
//	{'U', 'D', 'D', 'L', 'U', 'U', 'L', 'R', 'U', 'L'},
//	{'U', 'U', 'R', 'L', 'L', 'L', 'R', 'R', 'R', 'U'},
//	{'R', 'R', 'U', 'U', 'R', 'L', 'D', 'L', 'R', 'D'},
//	{'R', 'U', 'D', 'D', 'D', 'D', 'U', 'U', 'U', 'U'},
//	{'U', 'R', 'U', 'D', 'L', 'L', 'R', 'R', 'U', 'U'},
//	{'D', 'U', 'R', 'L', 'R', 'L', 'D', 'L', 'R', 'L'},
//	{'U', 'L', 'L', 'U', 'R', 'L', 'L', 'R', 'D', 'U'},
//	{'R', 'D', 'L', 'U', 'L', 'L', 'R', 'D', 'D', 'D'},
//	{'U', 'U', 'D', 'D', 'U', 'D', 'U', 'D', 'L', 'L'},
//	{'U', 'L', 'R', 'D', 'L', 'U', 'U', 'R', 'R', 'R'},
//
//};
//bool vis[15][15];
//void dfs(int x, int y, int &s) { // 开始坐标
//	if (x < 0 || x > 9 || y < 0 || y > 9) {
//		s++;
//		return;
//	}
//	if (vis[x][y])
//		return;
//	vis[x][y] = true;
//	if (mp[x][y] == 'U')
//		dfs(x - 1, y, s);
//	if (mp[x][y] == 'D')
//		dfs(x + 1, y, s);
//	if (mp[x][y] == 'L')
//		dfs(x, y - 1, s);
//	if (mp[x][y] == 'R')
//		dfs(x, y + 1, s);
//}
//int main() {
//	for (int i = 0; i < 10; i++)
//		for (int j = 0; j < 10; j++) {
//			memset(vis, 0, sizeof vis);
//			int s = 0;
//			dfs(i, j, s);
//			if (s > 0)
//				ans++;
//		}
//	cout << ans;
//	return 0;
//}

// 跳蚱蜢 答案：20
//#include <iostream>
//#include <map>
//#include <queue>
//#include <cstring>
//using namespace std;
//string s1 = "12345678#";
//string s2 = "87654321#";
//map<string, bool> vis;
//
//struct node {
//	string s;
//	int step;
//} p1, p2;
//int bfs() {
//	queue<node> q;
//	p1.s = s1;
//	p1.step = 0;
//	q.push(p1);
//	vis[s1] = true; // 标记字符串
//
//	while (q.size()) {
//		auto t = q.front();
//		q.pop();
//		if (t.s == s2)
//			return t.step;
//		int k = t.s.find('#'); // 找到空盘位置
//		int pos;
//
//		string str1 = t.s;
//		pos = (k + 1 + 9) % 9;
//		swap(str1[k], str1[pos]);
//		if (!vis[str1]) {
//			vis[str1] = true;
//			p2.s = str1;
//			p2.step = t.step + 1;
//			q.push(p2);
//		}
//
//		string str2 = t.s;
//		pos = (k - 1 + 9) % 9;
//		swap(str1[k], str1[pos]);
//		if (!vis[str2]) {
//			vis[str2] = true;
//			p2.s = str2;
//			p2.step = t.step + 1;
//			q.push(p2);
//		}
//
//		string str3 = t.s;
//		pos = (k + 2 + 9) % 9;
//		swap(str3[k], str3[pos]);
//		if (!vis[str3]) {
//			vis[str3] = true;
//			p2.s = str3;
//			p2.step = t.step + 1;
//			q.push(p2);
//		}
//
//		string str4 = t.s;
//		pos = (k - 2 + 9) % 9;
//		swap(str4[k], str4[pos]);
//		if (!vis[str4]) {
//			vis[str4] = true;
//			p2.s = str4;
//			p2.step = t.step + 1;
//			q.push(p2);
//		}
//	}
//
//}
//int main() {
//	int k = bfs();
//	cout << k << endl;
//	return 0;
//}



// 数列求值
//#include <iostream>
//using namespace std;
//int main () {
//	int a = 1, b = 1, c = 1, d = 0;
//	for (int i = 4; i <= 20190324; i++) {
//		d = (a + b + c) % 10000;
//		a = b;
//		b = c;
//		c = d;
//	}
//	cout << d << endl;
//	return 0;
//}

//
//#include <iostream>
//#include <algorithm>
//using namespace std;
//const int N = 100010, INF = 0x3f;
//int a[N];
//int main() {
//	int n;
//	int sum = 0, res = -INF, mindeep = 0;
//	int deep = 0;
//	cin >> n;
//	for (int i = 1; i <= n; i++)
//		cin >> a[i];
//	for (int i = 1; i < n; i *= 2) {
//		deep++;
//		sum = 0;
//		for (int j = i; j <= 2 * i - 1; j++) {
//			sum += a[j];
//		}
//		if (res < sum) { // 比当前值要小
//			mindeep = deep; // 记录最小深度
//			res = sum;
//		}
//	}
//	cout << mindeep;
//	return 0;
//}
//
//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//int main() {
//	int a[5] = {1, 2, 3, 4, 5};
//	int i = 2;
//	while (next_permutation(a, a + 5)) {
//		if (i == 62) {
//			for (int i = 0; i < 5; i++)
//				cout << a[i];
//			break;
//		}
//		i++;
//	}
//	return 0;
//}


// 幸运数字
//#include <iostream>
//#include <set>
//#include <algorithm>
//using namespace std;
//typedef long long ll;
//ll maxn = 59084709587505;
//set<ll> ss;
//int main() {
//	int a[3] = {3, 5, 7};
//	ll t = 1;
//	while (1) {
//		for (int i = 0; i < 3; i++) {
//			if (t * a[i] <= maxn) {
//				ss.insert(t * a[i]);
//			}
//		}
//		t = *ss.upper_bound(t);
//		if (t == maxn)
//			break;
//	}
//	cout << ss.size();
//	return 0;
//}
//
//#include <iostream>
//#include <cmath>
//using namespace std;
//typedef long long ll;
//ll maxn = 59084709587505;
//int main() {
//	int ans = 0;
//	for (int i = 0; pow(3, i) <= maxn; i++ )
//		for (int j = 0; pow(5, j) <= maxn; j++)
//			for (int k = 0; pow(7, k) <= maxn; k++) {
//				if (pow(3, i)*pow(5, j)*pow(7, k) <= maxn)
//					ans++;
//			}
//	cout << ans - 1 << endl;
//	return 0;
//}
//
//
//#include <iostream>
//using namespace std;
//const int N = 110;
//int a[N];
//int num_2, num_5;
//int main() {
//	int n = 100;
//	for (int i = 0; i < n; i++)
//		cin >> a[i];
//	for (int i = 0; i < n; i++) {
//		int num = a[i];
//		while (1) {
//			if (num % 2 == 0) {
//				num_2 ++;
//				num /= 2;
//			} else if (num % 5 == 0) {
//				num_5++;
//				num /= 5;
//			} else
//				break;
//		}
//
//	}
//	int res = num_2 > num_5 ? num_5 : num_2;
//	cout << res;
//	return 0;
//}


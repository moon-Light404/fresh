// ģ�⣺Speed Limit
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <set>
#include <vector>
#define ll long long
using namespace std;

//int s[11], t[11]; // �ٶȺ��ܺķ�ʱ��
//int main() {
//	int T, i;
//	int All_miles;
//	while (cin >> T && T != -1) {
//		i = 1;
//		All_miles = 0;
//		while (T--) {
//			cin >> s[i] >> t[i];
//			All_miles += s[i] * (t[i] - t[i - 1]);
//			i++;
//		}
//		cout << All_miles << endl;
//	}
//	return 0;
//}

//int main() {
//	int n,i,x,y,z,ans;
//
//	while(cin >> n, n > 0) {
//		ans = z = 0;
//
//		for(i = 0;i < n;i++) {
//			cin >> x >> y;
//			ans += (y-z) * x;
//			z = y; // ��¼��һ��ʱ��
//		}
//		cout << ans << " miles" << endl;
//	}
//	return 0;
//}





// ģ�⣺
// Ride to School
//#include <cmath>
//int main() {
//	int T;
//	double v, t, min = 1e8; // �ٶȺ�ʱ��
//	while (cin >> T && T) {
//		while (T--) {
//			cin >> v >> t;
//			if ( t > 0 && t + 4.5 * 3600 / v < min) {
//				min = t + 4.5 * 3600 / v;
//			}
//		}
//		cout << ceil(min) << endl;
//	}
//	return 0;
//}



//--------------------------------------------------------
/*Self Numbersɸѡ��
��������d(n) = n + ��λ������ = m����n��m��������
*/











// ��������
//const int N = 1e4;
//bool isNumber[N];
//int sum, s = 0, i = 1;
//void init() {
//	for (i = 1; i < N; i++) {
//		s = i;
//		sum += s;
//		while (s > 0) {
//			sum += (s % 10);
//			s /= 10;
//		}
//		isNumber[sum] = true;
//		sum = 0;
//	}
//}
//
//int main() {
//	init();
//	for (int k = 1; k < N; k++) {
//		if (!isNumber[k])
//			cout << k << endl;
//	}
//	return 0;
//}






















// ������:���д�� ������û������������
//const int N = 10000;
//int g[N];
//
//int sumOfGigits(int n) {
//	if ( n < 10)
//		return n;
//	else
//		return (n % 10) + sumOfGigits(n / 10);
//}
//
//void generateSequence(int n) {
//	while (n < N) {
//		int next = n + sumOfGigits(n); // d[n]
//		if (next >= N || g[next] != next)
//			return; // ����������
//		g[next] = n;
//		n = next;	// ����������չ
//	}
//}
//
//int main() {
//	int n;
//	for (n = 1; n < N; n++)
//		g[n] = n;
//	for (n = 1; n < N; n++)
//		generateSequence(n);
//	for (n = 1; n < N; n++)
//		if (g[n] == n)
//			cout << n << endl;
//	return 0;
//}


// ģ�⣺Bee ����
// ����  1  ���� 0 ��ֻ���Բ�����ȥ
//       1      1   ��1��
//		 2 		2   ��2��
//		 3      4
// ���� == ��һ������� + 1
// ���� == ��һ��������۷���
//int main() {
//	int a = 1, b = 0, c, d;
//	int n;
//	while (cin >> n, n) {
//		a = 1, b = 0;
//		while (n--) {
//			c = b + 1; // ����
//			d = a + b; // ����
//			a = c, b = d;
//		}
//		cout << b << " " << a + b << endl;
//	}
//	return 0;
//}


// ģ�⣺Gold Coins
/*��1�� 1 2 2 3 3 3 4 4 4 4 5 5 5 5 5.....
���������������£���֧���Ľ����
*/
//int main() {
//	int n;
//	while (cin >> n && n) {
//		int ans = 0;
//		for (int i = 1, j = 1; i <= n; j++) { // iΪ����
//			int k = j; // jΪ��j��ʱ���
//			while (k-- && i++ <= n)
//				ans += j; // �ӵ�ǰʱ��ε����� == ʱ��ε����
//		}
//		cout << n << " " << ans << endl;
//	}
//
//	return 0;
//}












// ģ�⣺ 3n+1 Problem
//int solve(int num, int step) {
//	if (num == 1)
//		return step;
//	else if (num % 2 == 0) {
//		return solve(num / 2, step + 1);
//	} else  {
//		return solve(num * 3 + 1, step + 1);
//	}
//}
//
//
//
//int main() {
//	int a, b;
//
//	while (cin >> a >> b && a && b) {
//		int max_step = -1e8;
//		if (a >= 10000 || b >= 10000)
//			break;
//		if (a > b) {
//			int t = a;
//			a = b;
//			b = t;
//		}
//		for (int i = a; i <= b; i++) {
//			max_step = max(solve(i, 1), max_step);
//		}
//		cout << a << " " << b << " " <<  max_step << endl;
//	}
//	return 0;
//}


// Pascal Library
// ���룺һ�б�ʾһ������μ������ÿһ�д���У���Ƿ�μ����ⳡ����
//const int N = 500;
//int a[N][N];
//
//int att[N] ; // ��ʼ������У��ȫ��ϯ����
//int main() {
//	int n, m;
//
//	cin >> n >> m; //n-У�� m-����
//	while (n || m) {
//		int flag = 0;
//		for (int i = 0; i < m; i++)
//			for (int j = 0; j < n; j++) {
//				cin >> a[i][j];
//			}
//		for (int i = 0; i < n; i++) {
//			int sum = 0;
//			for (int j = 0; j < m; j++) {
//				sum += a[j][i];
//			}
//			if (sum == m) {
//				flag = 1;
//				break;
//			}
//		}
//		if (flag ==  1)
//			cout << "yes\n";
//		else
//			cout << "no\n";
//	}
//	return 0;
//}




















































// ģ�⣺Calendar
//
//int Day[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // ÿ���µ�����
//struct Node {
//	int day;
//	int month;
//	int level;
//	string a; // �����¼�
//} e[100];
//
//bool isLeap(int y) {
//	if (y % 4 == 0)
//		return true;
//	return false;
//}
//
//bool cmp(Node n1, Node n2) {
//	if (n1.month != n2.month)
//		return n1.month < n2.month;
//	else if (n1.day != n2.day)
//		return n1.day < n2.day;
//	else
//		return n1.level > n2.level;
//}
//
//void AddDay(int *month, int *day) { // ����һ��
//	if (*day + 1 > Day[*month]) {
//		*month += 1;
//		*day = 1;
//	} else	*day += 1;
//}
//
//
//int main() {
//	int year;
//	char c;
//	cin >> year;
//	cin >> c;
//	int i = 0;
//	if (isLeap(year))
//		Day[2] += 1; // 29������
//	int now_month, now_day, cnt;
//	while (c != '#') {
//		if (c == 'A') {
//			cin >> e[i].day >> e[i].month >> e[i].level >> e[i].a;
//			i++;
//		} else if (c == 'D') {
//			sort(e, e + i, cmp);
//			cin >> now_day >> now_month;
//			cout << "Today is:" << now_day << " " << now_month << endl;
//			cnt = -1;
//			int k = 0;
//			for (;; cnt < 7) {
//				if (cnt == -1) { // �ڵ��췢�������
//					while (now_month == e[k].month && now_day == e[k].day && k < i) {
//						cout << e[k].day << " " << e[k].month << "*TODAY*" << e[k].a << endl;
//						k++;
//					}
//				} else {
//					while (now_month == e[k].month && now_day == e[k].day && k < i) {
//						if (e[k].level - cnt <= 0)
//							break;
//						else
//							cout << e[k].day << " " << e[k].month << " " << (e[k].level - cnt)  << e[k].a << endl;
//						k++;
//					}
//				}
//				cnt++;
//				AddDay(&now_month, &now_day);
//			}
//		}
//		cin >> c;
//	}
//	return 0;
//}



//// 2.4.5 ģ�⣺ Manager
//multiset<int> s; // ����õļ�������������ͬ��Ԫ��
//vector<int> v; // ɾ��Ԫ�صĴ洢
//multiset<int>:: iterator it;
//int cho; // ѡ��
//void add() {
//	int cost;
//	cin >> cost;
//	s.insert(cost);
//}
//
//void dele(int p) {
//	if (p == 1) {
//		if (s.empty())
//			cout << "-1" << endl;
//		else {
//			it = s.begin();
//			v.push_back(*it); // ɾ������СԪ��
//			s.erase(*it);
//		}
//	} else if (p == 2) {
//		if (s.empty())
//			cout << "-1" << endl;
//		else {
//			int size = s.size();
//			it = --s.end();
//			v.push_back(*it);
//			s.erase(*it);
//		}
//	}
//}
//
//void p() {
//	int p;
//	cin >> p;
//	cho = p;
//}
//
//
//int main() {
//	int maxcost, len;
//	char op;
//	while (cin >> maxcost >> len) {
//		int *del = new int[len];
//		for (int i = 0; i < len; i++)
//			cin >> del[i]; // Ҫɾ�����б�ĳ���
//		s.clear();
//		v.clear();
//		cho = 1; // Ĭ��ѡ��Ϊ1
//		while (1) {
//			cin >> op;
//			if (op == 'a')
//				add();
//			else if (op == 'r')
//				dele(cho);
//			else if (op == 'p')
//				p();
//			else if (op == 'e')	{
//				break;
//			}
//		}
//		for (int i = 0; i < len; i++)
//			cout << v[del[i] - 1] << endl;
//		cout << endl;
//	}
//
//	return 0;
//}






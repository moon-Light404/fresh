//










// // ��С������
//#include <iostream>
//#include <cstdio>
//using namespace std;
//
//int gcd(int a, int b) {
//	if (b == 0)
//		return a;
//	else
//		return gcd(b, a % b);
//}
//
//int main() {
//	int t;
//	scanf("%d��", &t);
//	while (t--) {
//		int m, temp = 1;
//		cin >> m;
//		for (int i = 0; i < m; i++) {
//			int n;
//			cin >> n;
//			temp = n / gcd(n, temp) * temp; // ��С������
//		}
//		cout << temp << endl;;
//	}
//	return 0;
//}

/*
// ��100���ڵ�������
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int prime[1001], pNum = 0;
bool p[1001];
bool isPrime(int n) {
	if (n <= 1)
		return false;
	int sq = (int)sqrt(1.0 * n);
	for (int i = 2; i <= sq; i++) {
		if (n % i == 0)
			return false;
	}
	return true;
}

void Find_Prime() {
	for (int i = 1; i <= 1000; i++) {
		if (isPrime(i) == true) {
			prime[pNum++] = i;
			p[i] = true;
		}
	}
}

int main() {
	Find_Prime();
	for (int i = 0; i < pNum; i++) {
		if (i && i % 10 == 0)
			cout << endl;
		cout << prime[i] << " ";
	}
	return 0;
}
*/




/*
// codeup˭�����Ǳ������
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 210, M = N;
int fav_book[N]; // ��ϲ����book
int cnt[M]; // ϲ�����ΪM�������

int main() {
	int n, m;
	while (cin >> n >> m && n && m) {
		for (int i = 0; i < n; i++) {
			int id; // ��ı��
			cin >> id;
			cnt[id]++;
			fav_book[i] = id;
		}

		for (int i = 0; i < n; i++) {
			if (cnt[fav_book[i]] == 1)
				cout << "BeiJu" << endl;
			else
				cout << cnt[fav_book[i]] - 1 << endl;
		}
		memset(fav_book, 0, sizeof fav_book);
		memset(cnt, 0, sizeof cnt);
	}

	return 0;
}


*/


//
////// ����ͳ��
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 1100;
int cnt[N][N]; // cnt[i][j] i ��ʾ�飬j��ʾ����
int a[N], b[N]; // a��¼���ֵ����֣�b��¼��
int main() {
	int  t;
	cin >> t;
	while (t--) {
		int sum, len = 0;
		int num[N]; // ��¼����
		int g; // ��������
		cin >> sum; // ���ĸ���
		for (int i = 0; i < sum; i++) {
			cin >> num[i];
			a[len++] = num[i];
		}
		sort(a, a + len);
		int a_len = unique(a, a + len) - a;

		len = 0;
		for (int i = 0; i < sum; i++) {
			cin >> g;
			b[len++] = g;
			cnt[g][num[i]]++;
		}
		sort(b, b + len);
		len = unique(b, b + len) - b;
		for (int i = 0; i < len; i++) {
			printf("%d={", b[i]);
			for (int j = 0; j < a_len; j++) {
				if (j < a_len - 1)
					printf("%d=%d,", a[j], cnt[b[i]][a[j]]);
				else
					printf("%d=%d", a[j], cnt[b[i]][a[j]]);
			}
			printf("}");
			printf("\n");
		}
		memset(cnt, 0, sizeof cnt);
		memset(a, 0, sizeof a);
		memset(b, 0, sizeof b);
	}
	return 0;
}




// ����set����,ȥ��+����
//#include <iostream>
//#include <set>
//using namespace std;
//set<int> s;
//int main() {
//	s.insert(4);
//	s.insert(1);
//	s.insert(2);
//	s.insert(1);
//	for (auto x : s)
//		cout << x << endl;
//	return 0;
//}


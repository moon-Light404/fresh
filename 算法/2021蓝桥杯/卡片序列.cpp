// ��Ƭ����










//#include <iostream>
//using namespace std;
//const int N = 10;
//int cnt[N];
//
//bool check(int num) { // num�Ƿ���ƴ����
//	while (num) {
//		int x = num % 10; // ȡ��λ
//		cnt[x]--; // x��Ƭ��ȥ1
//		if (cnt[x] < 0)
//			return false;
//		num /= 10;
//	}
//	return true; // ��ƴ����
//}
//
//int main() {
//	for (int i = 0; i < 10; i++)
//		cnt[i] = 2021; // ����i�Ŀ�Ƭ��������2021
//
//	int j = 1;
//	while (1) {
//		if (check(j)) {
//			j++;
//		} else
//			break;
//	}
//	cout << j - 1 ;
//	return 0;
//}


// 3.����ڷ�

//#include <iostream>
//#include <algorithm>
//using namespace std;
//typedef long long LL;
//LL yue[101000], cnt;
//
//int main() {
//	LL n = 2021041820210418;
//	for (LL i = 1; i <= n / i; i++) { // �����е�Լ��
//		if (n % i == 0) {
//			yue[++cnt] = i;
//			if (i * i != n)
//				yue[++cnt] = n / i;
//		}
//	}
//	sort(yue + 1, yue + cnt + 1);
//	for (int i = 1; i <= cnt; i++)
//		cout << yue[i] << endl;
//	cout << cnt;
////    int ans=0;
//    for(int i=1;i<=cnt;i++){
//        for(int j=1;j<=cnt;j++){
//            if(n%(yue[i]*yue[j])==0)
//                ans++;
//        }
//    }
//    cout<<ans;
//	return 0;
//}









// 4.·��
//#include <iostream>
//#include <algorithm>
//#include <cstring>
//using namespace std;
//const int N = 2100;
//int g[N][N];
//bool st[N];
//int dist[N];
//int n = 2021; // 2021����
//int gcd(int a, int b) {
//	return b == 0 ? a : gcd(b, a % b);
//}
//
//int lcm(int a, int b) {
//	return a * b / gcd(a, b);
//}
//
//void dijkstra() {
//	memset(dist, 0x3f, sizeof dist);
//	dist[1] = 0;
//	for (int i = 0; i < n; i++) { // n�α���
//		int t = -1;
//		for (int j = 1; j <= n; j++) {
//			if (!st[j] && (t == -1 || dist[t] > dist[j])) {
//				t = j;
//			}
//		}
//		st[t] = true;
//
//		for (int j = 1; j <= n; j++) {
//			dist[j] = min(dist[j], dist[t] + dist[j]);
//		}
//	}
//}
//
//int main() {
//	memset(g, 0x3f, sizeof g);
//	for (int i = 1; i <= 2021; i++)
//		for (int j = 1; j <= 2021; j++) {
//			if (j - i <= 21)
//				g[i][j] = g[j][i] = lcm(i, j);
//		}
//	dijkstra();
//	cout << dist[n];
//	return 0;
//}

// 5.�������
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool dp[101][300001];
int n;
vector<int> v;
unordered_map<int, bool>ans;
const int shift = 100000;

int main() {
	cin >> n;

	for (int i = 0; i < n; ++i) {
		int temp;
		cin >> temp;
		v.push_back(temp);
	}

	//ƫ����shiftΪ150000��ԭ�����������������100000��ƫ�ƺ������������Χ��[50000,250000]�����鿪300000����

	//��0��������ұߣ�����ߣ�����
	dp[0][shift + v[0]] = dp[0][shift - v[0]] = dp[0][shift] = true;

	for (int i = 1; i < n; ++i) {
		for (int j = 1; j <= 2 * shift; ++j) {
			dp[i][j] |= dp[i - 1][j];//���ŵ�i������
			dp[i][j] |= dp[i - 1][j + v[i]];//���ұ�
			if (j - v[i] >= 1)
				dp[i][j] |= dp[i - 1][j - v[i]];//�����
		}
	}

	for (int i = 1; i <= 2 * shift; ++i) {
		if (dp[n - 1][i]) {
			ans[abs(shift - i)] = true;//�������ߺ��ұ߿��ܴ����ظ������ʹ��unordered_map��absȥ��
		}
	}

	cout << ans.size() - 1 << endl;//��ȥ�������붼��ѡ����������Ϊ0���������
}

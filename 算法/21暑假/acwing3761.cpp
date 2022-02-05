#include <iostream>
#include <map>
#include <iterator>
using namespace std;
const int N = 200010;
int a[N]; // ����һ������

int main() {
	int T;
	cin >> T; // T������
	while (T--) {
		int n;
		cin >> n;
		map<int, int> m; // ����+���ִ���
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			m[a[i]]++;
		}
		int num = -2e9;
		// �ҳ�������С����
		map<int, int>::iterator iter;
		for (iter = m.begin(); iter != m.end(); iter++ ) {
			if (iter->second == 1) { // ����һ�ε���
				num = iter->first;
				break;
			}
		}
		if (num == -2e9) {
			cout << -1 << endl;
		} else {
			for (int i = 1; i <= n; i++) {
				if (a[i] == num) {
					cout << i << endl;
					break;
				}
			}
		}
	}
	return 0;
}
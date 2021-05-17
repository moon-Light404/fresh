// ˼·�����ǿ϶�Ҫ����������Щ�����ĵ��ǻ���Ҫ�����Ƚ��ٵ�С���ѣ����ջ���Ҫ����������
// �����һ���ˣ�
// ������ȫ����Ҳ�������������Ϸ���޷�������ȥ�ˡ�

#include <iostream>
#include <algorithm>
using namespace std;
const int N = 10010;
int n; // ����
struct node {
	int x, y, z;
	bool operator<(const node &t) const {
		return z < t.z;
	};
} p[N];

int main() {
	int m;
	cin >> m; // m������
	for (int i = 0; i < m; i++) {
		cin >> n; // ����
		for (int j = 0; j < n; j++) {
			cin >> p[i].x >> p[i].y;
			p[i].z = p[i].y - p[i].x;
		}
		sort(p, p + n); // �ѻ���Ҫ���ٻ�ľ��С��������
		bool st = true;
		int sum = 0;
		for (int i = 0; i < n; i++) {
			if (p[i].z <= 0)
				sum += p[i].x;
			// z < 0��ʾ����Ҫ��ô���ľ�Ѿ����˿��������Ʒ��
			else {
				if (p[i].z <= sum)
					sum += p[i].x; // �������Ʒ�������˾Ϳ��԰�С���ѵĻ�ľ�û���
				else {
					st = false;
					break;
				}
			}
		}
		if (st)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

	return 0;
}
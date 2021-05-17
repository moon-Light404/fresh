// ��ˮ����
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 510;

int spend[N]; // ÿ������Ҫ���ѵ�ʱ��
int time[N]; // ÿ���˵ĵȴ�ʱ��+����ʱ��
int main() {
	int n, r;
	cin >> n >> r; // n���ˣ�r��ˮ��ͷ
	for (int j = 0; j < n; j++)
		cin >> spend[j];
	sort(spend, spend + n); // �����һ���ʱ����С��ǰ������
	for (int i = 0; i < r; i++)
		time[i] = spend[i];

	for (int i = r; i < n; i++)
		time[i] = time[i - r] + spend[i];
	// ��һ��ˮ��ͷһ���Ƚ�����ˮ
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += time[i];
	cout << sum;
	return 0;
}
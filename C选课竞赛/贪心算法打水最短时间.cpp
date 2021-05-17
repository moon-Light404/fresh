// 打水问题
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 510;

int spend[N]; // 每个人需要花费的时间
int time[N]; // 每个人的等待时间+花费时间
int main() {
	int n, r;
	cin >> n >> r; // n个人，r个水龙头
	for (int j = 0; j < n; j++)
		cin >> spend[j];
	sort(spend, spend + n); // 排序找花费时间最小的前几个人
	for (int i = 0; i < r; i++)
		time[i] = spend[i];

	for (int i = r; i < n; i++)
		time[i] = time[i - r] + spend[i];
	// 第一个水龙头一定先结束打水
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += time[i];
	cout << sum;
	return 0;
}
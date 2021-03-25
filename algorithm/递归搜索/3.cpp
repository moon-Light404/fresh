#include <iostream>
#include<vector>
using namespace std;
const int N = 100010;
int a[N], ne[N];
vector<int> t;

void add_to_head(int a)
{
	t.push_back(a);
}




void delete(int k) // k表示地址
{
	
}
int main() {
	int head, n;
	cin >> head >> n; // head是头节点
	int key, dress, next; // key 是键值
	for (int i = 0; i < n; i++) {
		cin >> dress >> key >> next;
		a[dress] = key;
		ne[dress] = next; // 该地址的下一个地址
	}
	for (int k = head; k != -1; k = ne[k]) {
		cout << a[k] << endl;
		cout << "value of k:" << k << endl;

	}
	return 0;
}
//#include <vector>

//#include <queue>
//#include <iostream>
//using namespace std;
//
//int main() {
//	priority_queue<int, vector<int>, greater<int>> small_heap;
//	small_heap.push(3);
//	small_heap.push(2);
//	small_heap.push(4);
//	small_heap.push(5);
//	small_heap.push(0);
//	while (!small_heap.empty()) {
//		cout << small_heap.top();
//		small_heap.pop();
//	}
//	// ���0 2 3 4 5
//	return 0;
//}
//

//#include <cstring>
//#include <iostream>
//using namespace std;
//
//int main() {
//	string s1;
//	cin >> s1;
//	cout << s1;
//	return 0;
//}


#include <iostream>
#include <set>
using namespace std;
set<int> p;
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		char op;
		int num;
		cin >> op >> num;
		if (op == 'I') {
			cout << "����" << endl;
			p.insert(num);
		}
		if (op == 'Q') {
			cout << "��ѯ" << endl;
			if (p.count(num)) {
				cout << "Yes" << endl;
			} else
				cout << "No" << endl;
		}
	}
	return 0;
}
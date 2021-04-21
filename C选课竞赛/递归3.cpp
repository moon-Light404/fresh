#include <iostream>
using namespace std;
int ans;
string s2 = "";
string s1 = "ABCD";

bool is_sucess() {
	int cnt = 0;
	for (int i = 0; i < 5; i++ ) {
		if (s2[i] == 'A')
			cnt++;
	}
	if (cnt % 2 == 0)
		return true;
	return false;
}

void g(int n) {
	if (n == 5) {
//		for (int i = 0; i < 5; i++)
//			cout << s2[i];
//		cout << endl;
		if (is_sucess())
			ans++;
		return;
	}
	for (int i = 0; i < 4; i++) {
		s2[n] = s1[i];
		g(n + 1);
	}
}

int main() {
	g(0); // 第一个位置开始
	cout << ans;
	return 0;
}
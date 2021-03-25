#include <bits/stdc++.h>
using namespace std;

int main() {
	string s1;
	stringstream ss;
	getline(cin, s1);
	ss << s1;
	int n;
	while (ss >> n) {
		cout << n << endl;
	}
	return 0;
}
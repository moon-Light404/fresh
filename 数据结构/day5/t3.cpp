#include <iostream>
#include <unordered_set>
using namespace std;

unordered_set<string> ss;
int main() {
	ss.insert("001100100");
	ss.insert("100110010");
	ss.insert("011001100");
	ss.insert("011001100");
	unordered_set<string>::iterator it = ss.begin();
	for (; it != ss.end(); it++) {
		cout << *it << endl;
	}
	return 0;
}
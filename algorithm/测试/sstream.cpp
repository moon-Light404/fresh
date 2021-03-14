#include <iostream>
#include <sstream>
using namespace std;

int main() {
	string line;
	getline(cin, line);
	stringstream sstream(line);
	string ss;
	while (sstream >> ss) {
		cout << ss << endl;
	}
	return 0;
}
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n;
	while (cin >> n) {
		vector<int> number; // 存取每一位的数字
		string str;
		string result;
		cin >> str;
		for (auto c : str) {
			number.push_back(c - '0');
		}
		reverse(number.begin(), number.end());
		vector<int> res;
		while (number.size()) {
			int r = 0;
			for (int i = number.size() - 1; i >= 0; i--) {
				number[i] += r * 10;
				r = number[i] % 2;
				number[i] = number[i] / 2;
			}
			res.push_back(r); // 记录余数,但是要记得反过来
			while (number.size() && number.back() == 0)
				number.pop_back();
		}
		reverse(res.begin(), res.end());
		for (int i = 0 ; i < res.size(); i++) {
			int a = res[i];
			if (a == 0)
				result += '0';
			else
				result += '1';
		}
		cout << result << endl;
	}
	return 0;
}
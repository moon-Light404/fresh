#include <iostream>
#include <cstring>
#include <unordered_map>
using namespace std;

int main() {
//	map<int, string> Student;
//	Student.insert(pair<int, string>(000, "丁俊"));
//	Student[123] = "邹昆";
//	Student[134] = "我";
//	Student[112] = "他";
//	map<int, string>::iterator iter;
//
//	for (iter = Student.begin(); iter != Student.end(); iter++) {
//		cout << iter->first << endl;
//		cout << iter->second << endl;
//	}
	unordered_map<string, string> remap;
	remap.insert(make_pair("123", "订"));
	remap.insert(make_pair("124", "俊"));
	remap.insert(make_pair("134", "我手机"));
	remap.insert(make_pair("145", "你适合"));

	for (auto iter = remap.begin(); iter != remap.end(); iter++)
		cout << iter->first << " " << iter ->second << endl;
	cout << remap.count("123");

	return 0;
}
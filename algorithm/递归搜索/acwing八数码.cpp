#include <iostream>
#include <cstring>
#include <unordered_map>
using namespace std;

int main() {
//	map<int, string> Student;
//	Student.insert(pair<int, string>(000, "����"));
//	Student[123] = "����";
//	Student[134] = "��";
//	Student[112] = "��";
//	map<int, string>::iterator iter;
//
//	for (iter = Student.begin(); iter != Student.end(); iter++) {
//		cout << iter->first << endl;
//		cout << iter->second << endl;
//	}
	unordered_map<string, string> remap;
	remap.insert(make_pair("123", "��"));
	remap.insert(make_pair("124", "��"));
	remap.insert(make_pair("134", "���ֻ�"));
	remap.insert(make_pair("145", "���ʺ�"));

	for (auto iter = remap.begin(); iter != remap.end(); iter++)
		cout << iter->first << " " << iter ->second << endl;
	cout << remap.count("123");

	return 0;
}
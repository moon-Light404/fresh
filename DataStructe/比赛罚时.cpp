/**
 * ��ʱ=�����ⱻ�����ʱ�� + (�ύ����-1) * 20
 * 
 * */
#include<iostream>
#include<cstring>
using namespace std;

int main() {
    string wname, name; // �ھ���
    int wpt, pt; // ��С��ʱ�� ��ʱ
    int firstSub = 0, sub; // �����������ύ����
    int time;
    int t;// ������
    int T;
    cin >> T;
    while(T--) {
        cin >> name;
        t = pt = 0;
        for(int i = 0;i < 4;i++) { // ����4��������
            cin >> sub >> time;
            if(time > 0) {
                pt += time + 20*(sub - 1); // �ܷ�ʱ
                t++; // ��������1
            }
        }
        // �Ƚϻ���
        if(t > firstSub || (t == firstSub && pt < wpt)) { // ������һ�� || ������һ�µ��ܷ�ʱ��С
            firstSub = t;
            wname = name;
            wpt = pt;
        }
   
    }
    cout << wname << " " << firstSub << " " << wpt << endl;
    return 0;
}
/**
 * 罚时=该问题被解出的时间 + (提交次数-1) * 20
 * 
 * */
#include<iostream>
#include<cstring>
using namespace std;

int main() {
    string wname, name; // 冠军队
    int wpt, pt; // 最小罚时、 罚时
    int firstSub = 0, sub; // 最多解题数、提交次数
    int time;
    int t;// 解题数
    int T;
    cin >> T;
    while(T--) {
        cin >> name;
        t = pt = 0;
        for(int i = 0;i < 4;i++) { // 输入4道题的情况
            cin >> sub >> time;
            if(time > 0) {
                pt += time + 20*(sub - 1); // 总罚时
                t++; // 解题数加1
            }
        }
        // 比较环节
        if(t > firstSub || (t == firstSub && pt < wpt)) { // 解题数一致 || 解题数一致但总罚时最小
            firstSub = t;
            wname = name;
            wpt = pt;
        }
   
    }
    cout << wname << " " << firstSub << " " << wpt << endl;
    return 0;
}
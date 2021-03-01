#include<bits/stdc++.h>
using namespace std;

void swap(int &a,int& b){
    int t = a;
    a = b;
    b = t;
}

int partition(vector<int> &arr,int L,int R){
    int p = arr[L];
    int mark = L;
    for(int i=L+1;i<=R;i++){
        if(p>arr[i]){
            mark++;
            swap(arr[i],arr[mark]);
        }
    }
    swap(arr[L],arr[mark]);
    return mark;
}
void quickSort(vector<int>& a,int L,int R){
   map<string,int> m;
   stack<map<string,int> > quickStack;
   m.insert(pair<string,int>("L",L));
   m.insert(pair<string,int>("R",R));
   quickStack.push(m);

    while(!quickStack.empty()){
        map<string,int> param = quickStack.top();
        quickStack.pop(); // É¾³ýÕ»¶¥ÔªËØ
        int prIndex = partition(a,param["L"],param["R"]);

        if(param["L"]<prIndex-1){
            map<string,int> leftparam;
            leftparam.insert(pair<string,int>("L",param["L"]));
            leftparam.insert(pair<string,int>("R",prIndex-1));
            quickStack.push(leftparam); 
        }

        if(prIndex+1<param["R"]){
            map<string,int> rightparam;
            rightparam.insert(pair<string,int>("L",prIndex+1));
            rightparam.insert(pair<string,int>("R",param["R"]));
             quickStack.push(rightparam); 
        }
    }
}


int main(){
   vector<int> a = {4,7,6,5,3,2,8,1};
    quickSort(a,0,a.size()-1);
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<" ";

    }
    return 0;
}
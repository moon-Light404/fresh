#include<bits/stdc++.h>
using namespace std;

void countSort(vector<int>& array){
   int max = array[0];
   for(int i=1;i<array.size();i++){
       if(array[i]>max){
           max = array[i];
       }
   }
   vector<int> countArray(max+1); // 容量为max+1 
    for(int i=0;i<array.size();i++){
        countArray[array[i]]++;
    }

    int index = 0;// countArray下标代表数字，对应的元素值表示
    //出现的次数
    for(int i=0;i<countArray.size();i++){
        for(int j=0;j<countArray[i];j++){
            array[index++] = i;
            // 直接修改原数组(参数)
        }
    }
}

int main(){
    vector<int> a={4,4,6,5,3,2,8,1,7,5,6,0,10};
    countSort(a);
   for(vector<int>:: iterator it = a.begin();it!=a.end();it++ ){
       cout<<*it<<endl;
   }

    return 0;
}
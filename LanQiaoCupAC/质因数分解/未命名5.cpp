//#include<iostream>
//using namespace std;
//	网友年龄 
//int sum;
//int main(){
//	for(int i=27;i<=99;i++){
//		sum=(i%10)*10+(i/10);
//		if(i-sum==27)
//		cout<<i<<endl;
//	}
//	
//	return 0;
//}


//生日蜡烛
//int main(){
//	int N = 236;
//	int m;
//	for(int n=1;n*(n+1)<=2*N;n++){
//		if((N-(n-1)*n/2)%n==0){
//		 m =(N-(n-1)*n/2)/n;
//		cout<<m<<endl;
//		
//	}
//	}
//} 

//寒假作业
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int hashtable[14]={false};
int a[14];
int res=0;
void generateP(int start){
	if(start>=4 )
	  if(a[1]+a[2]!=a[3]) return ;//对确定的前面三个数字进行等式判断，不符合，就不继续往下搜索
	if(start>=7)
	  if(a[4]-a[5]!=a[6]) return ;//同理进行第二个等式的判断，进行剪枝
	if(start>=10)
	  if(a[7]*a[8]!=a[9]) return ;
	if(start>=13)
	  if(a[12]*a[11]==a[10])
	  {
	  	for(int i=1;i<=12;i++)
	  	  cout<<a[i]<<" ";
	  	cout<<endl;
		res++;
		return ;
	  }
	  for(int x=1;x<=13;x++){
	  	if(hashtable[x]==false){
	  		a[start]=x;
	  		hashtable[x] = true;
	  		generateP(start+1);
	  		hashtable[x]=false;
		  }
	  }
}

int main(){
	generateP(1);
	cout<<res<<endl;
	return 0;
}



















 

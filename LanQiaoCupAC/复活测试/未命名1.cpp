#include<bits/stdc++.h>
using namespace std;
//int N,k,meid[202];//N表示信息数量,k表示最多显示的信息数量 
//set <int> q;//显示信息 
//queue<int> ss;//队列 
//vector<int> show;
//bool full(){
//	if(q.size()==k)
//	return true;//屏幕满了 
//	
//	return false;
//}
//int main(){
//	cin>>N>>k;
//	for(int i=1;i<=N;i++){
//		cin>>meid[i];//输入信息 id 
//	}
//	
//	for(int i=1;i<=N;i++){
//		if(!q.count(meid[i])){
//			q.insert(meid[i]);//不重复的信息 
//			if(!full())//信息没满直接插入 
//			ss.push(meid[i]);//信息入队显示
//			 
//			 else{//满了 
//			 	int tem = ss.front();
//				q.erase(tem);//在集合中擦除这个数字 
//			 	ss.pop();//弹出下面的消息---第一个消息
//				ss.push(meid[i]);
//			 }
//		}
//		
//		
//		 
//	}
//	for(int i=1;i<=k&&!ss.empty();i++){
//		show.push_back(ss.front());
//		ss.pop();
//	}
//	cout<<show.size()<<endl;
//	for(vector<int> ::iterator it=show.end()-1;it>=show.begin();it--){
//		cout<<*it<<" ";
//	}
//	
//	return 0;
//} 

//int qiuyu(int m,int n){
//	int a,b;
//	a=m/n;
//	b=m-n*a;
//	return b;
//}
//
//int main(){
//	int m,n,sum,a=0;
//	vector<int> number;//存放各位数字 
//	cin>>m>>n;
//	if(m==0){
//	cout<<"-1";
//	return 0;
//	}
//	int shang=n/m;
//	int i=0;//商数 
//	while(n>0){
//		number.push_back(n%10);
//		n/=10;
//	}
//	for(vector<int> ::iterator it=number.end()-1;it>=number.begin();it--){
//			int k=*it+a*10;
//			a =qiuyu(k,m);
//			sum+=a;
//	}
//	cout<<shang<<endl<<sum;
//	return 0;
//}
vector<int> data;
int N,mi,ma,ans;//ans操作次数 
int main(){
	cin>>N;
	for(int i=0;i<N;i++){
	int da;
	cin>>da;
	data.push_back(da);
}

	sort(data.begin(),data.end());//排序
	mi=*(data.begin());//最小值 
	ma=*(data.end()-1);//最大值 
	
	if(ma<=2*mi){
	cout<<0;
	return 0;
}
	for(vector<int> ::iterator it=data.begin();ma>2*mi&&it!=data.end();it++){
		mi = *it;
		ans++;
	}

	cout<<ans-1;
	return 0;
}




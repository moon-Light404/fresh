#include<bits/stdc++.h>
using namespace std;
//int N,k,meid[202];//N��ʾ��Ϣ����,k��ʾ�����ʾ����Ϣ���� 
//set <int> q;//��ʾ��Ϣ 
//queue<int> ss;//���� 
//vector<int> show;
//bool full(){
//	if(q.size()==k)
//	return true;//��Ļ���� 
//	
//	return false;
//}
//int main(){
//	cin>>N>>k;
//	for(int i=1;i<=N;i++){
//		cin>>meid[i];//������Ϣ id 
//	}
//	
//	for(int i=1;i<=N;i++){
//		if(!q.count(meid[i])){
//			q.insert(meid[i]);//���ظ�����Ϣ 
//			if(!full())//��Ϣû��ֱ�Ӳ��� 
//			ss.push(meid[i]);//��Ϣ�����ʾ
//			 
//			 else{//���� 
//			 	int tem = ss.front();
//				q.erase(tem);//�ڼ����в���������� 
//			 	ss.pop();//�����������Ϣ---��һ����Ϣ
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
//	vector<int> number;//��Ÿ�λ���� 
//	cin>>m>>n;
//	if(m==0){
//	cout<<"-1";
//	return 0;
//	}
//	int shang=n/m;
//	int i=0;//���� 
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
int N,mi,ma,ans;//ans�������� 
int main(){
	cin>>N;
	for(int i=0;i<N;i++){
	int da;
	cin>>da;
	data.push_back(da);
}

	sort(data.begin(),data.end());//����
	mi=*(data.begin());//��Сֵ 
	ma=*(data.end()-1);//���ֵ 
	
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




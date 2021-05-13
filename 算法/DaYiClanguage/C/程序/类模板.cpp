#include<iostream>
using namespace std;
struct Student{
	int id;
	float gpa;
};
template <class T>
class Store{
	private:
		T item;
		bool havevalue;
		public:
			Store();
			T &getElem();
			void putElem(const T &x);
};
template  <class T>
T &Store<T>::getElem(){
	if(!havevalue){
		cout<<"No item present!" <<endl;
		exit(1);
	}
	return item;
}
template <class T>
void Store<T>::putElem(const T &x){
	havevalue =true;
	item=x;
}


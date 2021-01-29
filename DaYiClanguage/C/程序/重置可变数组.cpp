#include<iostream>
using namespace std;
template <class T>
void Array<T>::resize(int sz){
	assert(sz>=0);
	if(sz=size)
	return;
	T* newlist = new T[sz];
	int n=(sz<size)?sz:size;
	
	for(int i=0;i<n;i++)
	{
		newlist[i]=list[i];
		delete[] list;
		list =newlist;
		size=sz;
	 } 
}


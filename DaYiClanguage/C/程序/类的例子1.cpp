#include<iostream>
using namespace std;
class Array
{
	private:
		int *p;
		int length;
		
		public:
			Array(int length)
			{
				if(length<0)
				{
					length=0;
				}
				this->length=length;
				p=new int[this->length];
			}
			void setData(int index,int data)
			{
				p[index]=data;
			}
			int getData(int index)
			{
				return p[index];
			}
			Array(const Array& obj)
			{
				this->length=obj.length;
				p=new int[this->length];
				for(int i=0;i<this->length;i++)
				{
					p[i]=obj.p[i];
				}
			}
			int GetLength()
			{
				return this->length;
			}
			~Array()
			{
				if(p!=NULL)
				{
					delete[]p;
				}
				this->length=0;
			}
};
int main()
{
	Array arr(10);
	for(int i=0;i<arr.GetLength();i++)
	{
		arr.setData(i,i);
	}
	for(int i=0;i<arr.GetLength();i++)
	{
		cout<<arr.getData(i)<<" ";
		
	}
	cout<<"³õÊ¼»¯"<<endl;
	
	Array brr=arr;
	for(int i=0;i<brr.GetLength();i++)
	{
		cout<<brr.getData(i)<<endl;
	}
	return 0;
	
}

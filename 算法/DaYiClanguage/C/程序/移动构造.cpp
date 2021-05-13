#include<iostream>
using namespace std;
class IntNum{
	public:
		IntNum(int x=0):xptr(new int(x)){
			cout<<"Calling constructor"<<endl;
		}
		
		IntNum(const IntNum &n):xptr(new int(*n.xptr))
		{
			cout<<"Calling copy consturctor"<<endl;
		}  //����һ���µĶ�����������ԭ������ָ�������ֵ��һ���ģ�ռ�ò�ͬ�ڴ�ռ䣬Ҳ����������ͬ����ֻ��ָ��ָ�����ֵ���...
		~IntNum(){
			
			delete xptr;
			cout<<"Destructing.."<<endl;
		}
		int getInt()
		{
			return *xptr; 
		}
		private:
			int *xptr;
};
IntNum getNum()
{
    IntNum a;
    return a; //a��һ���Ǿ�̬�ľֲ��������뿪��������Ժ󣬾ͽ�����...�����������Ҫ����һ����ʱ�������󣬷��ص��������У�����Ҫʹ�ø��ƹ��캯��(return  a֮ǰ)
}
int main()
{
    cout<<getNum().getInt()<<endl;
    return 0;
}

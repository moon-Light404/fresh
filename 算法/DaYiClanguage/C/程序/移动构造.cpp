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
		}  //构造一个新的对象，这个对象和原来对象指向参数的值是一样的，占用不同内存空间，也就是两个不同对象，只是指针指向的数值相等...
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
    return a; //a是一个非静态的局部变量。离开这个函数以后，就结束了...在这个过程中要构造一个临时无名对象，返回到主函数中，所以要使用复制构造函数(return  a之前)
}
int main()
{
    cout<<getNum().getInt()<<endl;
    return 0;
}

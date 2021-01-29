#include<iostream>
using namespace std;
class Base{
    public:
    virtual ~Base();
};
Base::~Base(){
    cout<<"Base destructor"<<endl;
}
class Dervied:public Base{
    public:
    Dervied();
    virtual ~Dervied();

private:
	
int *p;
};
Dervied::Dervied(){
    p=new int(0);
}
Dervied::~Dervied(){
    cout<<"Dervied destructor"<<endl;
}
void fun(Base* b)
{
    delete b; //静态情况下只能知道是基类指针，会调用Base类的析构函数
}
int main()
{
Base *b=new Dervied();
fun(b);  //
return 0;
}

#include<iostream>
#include<string>
using namespace std;
//纯虚函数 和 抽象类
class Base
{
private:
    /* data */
public:
    virtual void func() = 0;    //纯虚函数，这个类是抽象类
                        //1.无法实例化对象
                        //2.抽象类的子类 必须要重写父类中的纯虚函数，否则也属于抽象类
};
class Son:public Base
{
private:
    /* data */
public:
    void func(){    //子类必须重写父类中纯虚函数，否则无法实例化
        cout<<"Func() Loading!"<<endl;
    }
};

void test01(){
    Son s;  //不重写，Son类为 抽象类。 必须重写父类中的虚函数，否则无法实例化对象
    Base * base = new Son;  //多态技术：父类的指针 指向子类对象
    base->func();   //指向子类的对象不同，最终调用的函数不同
}

int main(){
    test01();
}
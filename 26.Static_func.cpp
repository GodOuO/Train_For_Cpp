#include<iostream>
#include<string>
using namespace std;
//静态成员函数
class Person
{
private:
public:
    static int m_A;
    int m_B;
    static void func(); //静态成员函数
    Person(/* args */);
    ~Person();
};
int Person::m_A = 0;
void Person::func(){
    m_A = 100;  //静态成员函数 可 访问静态成员变量
 // m_B = 200;  //非静态成员 无法访问
    cout<<"Static func() 调用"<<endl;
}

Person::Person(/* args */)
{
}

Person::~Person()
{
}

void test01(){
    //通过对象调用
    Person p1;
    p1.func();
    //通过类名调用
    Person::func();
}

int main(){
    test01();
}
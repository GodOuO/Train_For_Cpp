#include<iostream>
#include<string>
using namespace std;

class Person
{
private:
    int m_A;
    static int m_B;
public:
    void func();
    static void func2();
    Person(/* args */);
    ~Person();
};
int Person::m_B = 0;
Person::Person(/* args */)
{
}

Person::~Person()
{
}
void test01(){
    Person p;
    cout<<"Size of P = "<<sizeof(p)<<endl;  //空对象占用内存
}
void test02(){
    Person p;
    cout<<"Size of P = "<<sizeof(p)<<endl;  //非静态有成员变量对象占用内存
}
int main(){
    //test01();
    test02();
}
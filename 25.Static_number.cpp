#include<iostream>
#include<string>
using namespace std;
//静态成员变量
class Person
{
private:
                //1.所有对象共享同一份数据
                //2.编译阶段分配内存
                //3.类内进行声明，类外初始化
    static int m_A; //类内声明     
public:
    static int m_B;
    int getA(){
        return m_A;
    }
    void setA(int a){
        m_A = a;
    }
    Person(/* args */);
    ~Person();
};
int Person::m_A = 100; //类外初始化
int Person::m_B = 51; //类外初始化

Person::Person(/* args */)
{
}

Person::~Person()
{
}

void test01(){
    Person p;
    cout<<"P1's A:\t"<<p.getA()<<endl;
    Person p2;
    p2.setA(200);
    cout<<"P2's A:\t"<<p2.getA()<<endl;
    cout<<"P1's A:\t"<<p.getA()<<endl;  //共享数据内存后，数据更新

}

void test02(){
    //静态成员变量不属于某个对象，所有对象共享一份数据
    //因此静态成员变量有两种
    Person p1;
    cout<<"P1's A:\t"<<p1.getA()<<endl;             //通过对象访问
    cout<<"P1's B:\t"<<Person::m_B<<endl;           //通过类名访问
    
}

int main(){
    //test01();
    test02();
}
#include<iostream>
#include<string>
using namespace std;
class Person
{
private:
    int m_A;
    int m_B;
    int m_C;
public:
    int getA(){
        return m_A;
    }
    int getB(){
        return m_B;
    }
    int getC(){
        return m_C;
    }
//Person(int a,int b,int c);
    Person(int a,int b,int c);
    ~Person();
};

// Person::Person(int a,int b,int c){  //传统意义赋值
//     m_A = a;
//     m_B = b;
//     m_C = c;
// }
Person::Person(int a,int b,int c):m_A(a),m_B(b),m_C(c){}  //初始化列表

Person::~Person()
{
}

void test01(){
//Person p(10,20,30);             //传统意义赋值
    Person p(30,20,30);
    cout<<"m_A: "<<p.getA()<<endl;
    cout<<"m_B: "<<p.getB()<<endl;
    cout<<"m_C: "<<p.getC()<<endl;
}

int main(){
    test01();

}
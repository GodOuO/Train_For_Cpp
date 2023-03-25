#include<iostream>
#include<string>
using namespace std;
//左移运算符重载
class Person
{
friend ostream & operator<<(ostream &cout,Person &p);
private:
    int m_A;
    int m_B;
public:
    //void operator<<(cout);        //不会利用成员函数 重载<<左移运算符
    int getA();
    int getB();
    void setAB(int a,int b);
    Person(/* args */);
};

Person::Person(/* args */)
{
}
int Person::getA(){
    return m_A;
}
int Person::getB(){
    return m_B;
}
void Person::setAB(int a,int b){
    m_A = a;
    m_B = b;
}

ostream & operator<<(ostream &cout,Person &p){  //全局函数重载<<左移运算符
    cout<<"P_a: "<<p.getA()<<endl<<"P_b: "<<p.getB();   //重载输出ab
    cout<<endl;
    cout<<"P_a: "<<p.m_A<<endl<<"P_b: "<<p.m_B;   //Friend友元 支持访问private
    return cout;    //cout 可以起别名 都支持实现
}

void test01(){
    Person p;
    p.setAB(10,10);
    cout<<p<<endl;
    //cout<<"P_a: "<<p.getA()<<endl<<"P_b: "<<p.getB()<<endl;   //通用输出ab
}


int main(){
    test01();
}
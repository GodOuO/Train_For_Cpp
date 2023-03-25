#include<iostream>
#include<string>
using namespace std;
//+ 运算符重载
class Person
{
private:
    int m_A;
    int m_B;
public:
    void setAB(int a,int b);
    int getA();
    int getB();
    //Person operator+(Person &p);        //通过成员函数-重载+
    Person();
};

Person::Person()
{
}

void Person::setAB(int a,int b){
    m_A = a;
    m_B = b;
}
int Person::getA(){
    return m_A;
}
int Person::getB(){
    return m_B;
}

// Person Person::operator+(Person &p){
//     Person temp;
//     temp.setAB((this->getA())+(p.getA()),(this->getB())+(p.getB()));
//     return temp;
// }

Person operator+(Person &p1,Person &p2){    //通过全局函数-重载+
    Person temp;
    temp.setAB(p1.getA()+p2.getA(),p1.getB()+p2.getB());
    return temp;
}

Person operator+(Person &p1,int num){    //通过全局函数 做 重载+的重载
    Person temp;
    temp.setAB(p1.getA()+num,p1.getB()+num);
    return temp;
}


void test01(){
    Person p1;
    Person p2;
    p1.setAB(10,10);
    p2.setAB(10,10);
    
    Person p3 = p1 + p2;           //运算符重载+
    
    Person p4 = p1 + 5;            //运算符重载 也支持发生函数重载 Person + int

    //Person p3 = p1.operator+(p2);   //成员函数调用的本质
    //Person p3 = operator+(p1,p2);   //全局函数调用的本质
    cout<<"P3.m_A :\t"<<p3.getA()<<endl<<"P3.m_B :\t"<<p3.getB()<<endl;
    cout<<"P4.m_A :\t"<<p4.getA()<<endl<<"P4.m_B :\t"<<p4.getB()<<endl;
}

int main(){
    test01();
}
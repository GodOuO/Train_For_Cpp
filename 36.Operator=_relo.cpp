#include<iostream>
#include<string>
using namespace std;
//关系运算符重载
class Person
{
private:
    string m_Name;
    int m_Age;
public:
    Person(string name,int age);
    bool operator==(Person &p); //成员重载 ==
    bool operator!=(Person &p); //成员重载 !=
};

Person::Person(string name,int age)
{
    m_Name = name;
    m_Age = age;
}

bool Person::operator==(Person &p){
    if(this->m_Age == p.m_Age && this->m_Name == p.m_Name)
        return 1;
    else
        return 0;
}

bool Person::operator!=(Person &p){
    if(this->m_Age == p.m_Age && this->m_Name == p.m_Name)
        return 0;
    else
        return 1;
}

void test01(){
    Person p1("Tom",18);
    Person p2("Tom",18);
    if(p1 == p2)
        cout<<"P1 is same as P2!"<<endl;
    else
        cout<<"P1 and P2 are different!"<<endl;
    if (p1!=p2)
        cout<<"P1 and P2 are different!"<<endl;
    else
        cout<<"P1 is same as P2!"<<endl;
}

int main(){
    test01();
}
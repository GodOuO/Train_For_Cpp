#include<iostream>
#include<string>
using namespace std;
class Phone
{
private:
    string p_Name;
public:
    string getpName(){
        return p_Name;
    }
    Phone(string pName);
    ~Phone();
};

Phone::Phone(string pName)
{
    p_Name = pName;
}
Phone::~Phone()
{
    cout<<"Phone 析构函数"<<endl;
}

class Person
{
private:
    string m_Name;
    Phone m_Phone;  //当其他类成员作为本来成员时，先构造其他类对象，再构造自身
public:
    string getmName(){
        return m_Name;
    }
    Phone getmPhone(){
        return m_Phone;
    }
    Person(string mName,string pName);
    ~Person();
};

Person::Person(string mName,string pName):m_Name(mName),m_Phone(pName)
{                                       //隐式转换法 Phone m_Phone = pName;
}
Person::~Person()
{                   //析构顺序与构造相反
    cout<<"Person 析构函数"<<endl;
}


void test01(){
    Person p("Zhang3","iPhone");
    cout<<"Name:\t\t"<<p.getmName()<<endl<<"PhoneName:\t"<<p.getmPhone().getpName()<<endl;
}

int main(){
    test01();
}
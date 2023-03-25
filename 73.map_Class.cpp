#include<iostream>
#include<string>
#include<map>
using namespace std;
// map <Person,int> + Age倒叙规则 存储 并输出
class Person
{
public:
    string m_Name;
    int m_Age;
    Person(string name,int age);
};

class mCompare
{
public:
    bool operator()(const Person &p1,const Person &p2)const{
        return p1.m_Age > p2.m_Age;
    }
};


void printMap(const map<Person,int,mCompare>&m){
    for (map<Person,int,mCompare>::const_iterator it = m.begin(); it != m.end(); it++)
        cout<<"Key Name : "<<it->first.m_Name
            <<"\tKey Age : "<<it->first.m_Age
            <<"\tValue : "<<it->second<<endl;
    cout<<endl;
}

Person::Person(string name,int age)
{
    this->m_Name = name;
    this->m_Age = age;
}

void test01(){
    map<Person,int,mCompare> m;
    Person p1("GodOuO",51);
    Person p2("Wendy",384);
    Person p3("Math",51);

    m.insert(make_pair(p1,51));
    m.insert(make_pair(p2,51));
    m.insert(make_pair(p3,51));

    printMap(m);

}

int main(){
    test01();
}
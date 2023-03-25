#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
class Person
{
public:
    int m_Age;
    string m_Name;
    Person(string name,int age){
        this->m_Name = name;
        this->m_Age = age;
    }
};


//常用查找算法 count_if

class Greater5
{
public:
    bool operator()(int a){
        return a>5;
    }
};

class AgeGreater
{
public:
    bool operator()(const Person &p){
        return p.m_Age>300;
    }
};



//统计内置数据类型
void test01(){
    vector<int> v;
    for (int i = 0; i < 10; i++)
        v.push_back(i+1);
    
    int ret = count_if(v.begin(),v.end(),Greater5());
    cout<<"The number of Elem bigger than 5 is : "<<ret<<endl;
    
}


//统计自定义数据类型
void test02(){
    vector<Person> v;

    Person p1("GodOuO",23);
    Person p2("Wendy",23);
    Person p3("MonkT",304);
    Person p4("SunWK",384);

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);

    int ret = count_if(v.begin(),v.end(),AgeGreater());
    if (0 != ret)
        cout<<"The number of the elem which is Age older than 300 is : "<<ret<<endl;
    else
        cout<<"No one older than 20 !"<<endl;
    
}



int main(){
    //test01();
    test02();

}
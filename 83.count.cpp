#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
class Person
{
public:
    string m_Name;
    int m_Age;
    Person(string name,int age);
    bool operator==(const Person &p);
};

Person::Person(string name,int age)
{
    this->m_Name = name;
    this->m_Age = age;
}
bool Person::operator==(const Person &p){
        if (this->m_Age == p.m_Age)
            return 1;
        else
            return 0;
    }


//常用查找算法 count

//统计内置数据类型
void test01(){
    vector<int> v;
    for (int i = 0; i < 5; i++)
        v.push_back(10);
    v.push_back(51);

    int ret = count(v.begin(),v.end(),10);
    cout<<"elem 40's times : "<<ret<<endl;
    
}


//统计自定义数据类型
void test02(){
    vector<Person> v;
    Person p1("GodOuO",51);
    Person p2("Wendy",384);
    Person p3("LiuB",126);
    Person p4("ZhaoY",51);

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);

    Person pSearch("Fucking",51);

    int ret = count(v.begin(),v.end(),pSearch);
    cout<<"The number of Elems which is Same as Fucking 's Age 51 is : "<<ret<<endl;

}

int main(){ 
    //test01();
    test02();
}   
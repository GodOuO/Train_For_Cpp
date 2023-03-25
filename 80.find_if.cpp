#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
//常用查找算法 find_if
class Person
{
public:
    string m_Name;
    int m_Age;
    Person(string name,int age){
        this->m_Name = name;
        this->m_Age = age;
    }
};



class Greater5
{
public:
    bool operator()(int a){
        return a>5;
    }
};


class Greater51
{
public:
    bool operator()(const Person &p){
        return p.m_Age>51;
    }
};



//查找内置数据类型
void test01(){
    vector<int> v;
    for (int i = 0; i < 10; i++)
        v.push_back(i+1);
    


    vector<int>::iterator it = find_if(v.begin(),v.end(),Greater5());
    if(it == v.end())
        cout<<"Not Found!"<<endl;
    else{
        cout<<"Find elem which is bigger than 5 is : "<< *it<<endl;
    }

}



//查找自定义数据类型
void test02(){
    vector<Person> v;
    Person p1("GodOuO",51);
    Person p2("Wendy",384);
    Person p3("Fury",126);
    Person p4("P4",304);

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);

    //找年龄 >20 elem
    vector<Person>::iterator it = find_if(v.begin(),v.end(),Greater51());
    if (it == v.end())
        cout<<"Not Found the elem > 51 "<<endl;
    else{
        cout<<"Find it _Name : "<<it->m_Name<<"\tAge : "<<it->m_Age<<endl;
    }
    


}




int main(){
    //test01();
    test02();
}
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
    //重载 == 底层find 知晓如何对比 Person数据类型
    bool operator ==(const Person &p){
        if (this->m_Name == p.m_Name && this->m_Age == p.m_Age)
            return 1;
        else
            return 0;
    }
};

Person::Person(string name,int age)
{
    this->m_Name = name;
    this->m_Age = age;
}



class princIntVector
{
private:
    /* data */
public:
    void operator()(int a){
        cout<<a<<" ; ";
    }
};


//常用查找算法 find
void test01(){      //内置数据类型
    vector<int> v;
    for (int i = 0; i < 10; i++)
        v.push_back(i+1);
    for_each(v.begin(),v.end(),princIntVector());
    cout<<endl;

    //查找容器中是否有 elem = 5
    vector<int>::iterator it = find(v.begin(),v.end(),5);
    if (it == v.end())
        cout<<"Vector doesn't contain the elem 5 !"<<endl;
    else{
        cout<<"Find it "<<*it<<endl;
    }

    
    
}

void test02(){      //自定义数据类型
    vector<Person> v;
    Person p1("GodOuO",51);
    Person p2("Wendy",384);
    Person p3("MonkT",304);
    Person p4("SunWK",126);

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);

    Person pSearch("Wendy",384);

    vector<Person>::iterator it = find(v.begin(),v.end(),pSearch);
    if (it == v.end())
    {
        cout<<"Not Finded !"<<endl;
    }
    else{
        cout<<"Find it __Name : "<<it->m_Name<<"\tAge : "<<it->m_Age<<endl;
    }

}


int main(){
    //test01();
    test02();
}
#include<iostream>
#include<string>
#include<set>
using namespace std;

class Person        //Perosn 自定义数据类型
{
public:
    string m_Name;
    int m_Age;
    Person(string name,int age);
};

class mCompare  //仿函数类型
{
public:
    bool operator()(int a,int b);
};

class pCompare
{
public:
    bool operator()(const Person &p1,const Person &p2); //对比中只读const，引用做传递，防止拷贝构造出现
};


void printSet(const set<int>&s){
    for (set<int>::const_iterator it = s.begin(); it != s.end(); it++)
        cout<<*it<<" ; ";
    cout<<endl;
}

void printMultiset(const multiset<int> &s){
    for (multiset<int>::const_iterator it = s.begin(); it != s.end(); it++)
        cout<<*it<<" ; ";
    cout<<endl;
}

void printReset(const set<int,mCompare> &rs){
    for (set<int,mCompare>::const_iterator it = rs.begin(); it != rs.end(); it++)
        cout<<*it<<" ; ";
    cout<<endl;
}

void printPersonSet(const set<Person,pCompare> &sp){
    for (set<Person,pCompare>::const_iterator it = sp.begin(); it != sp.end(); it++)
        cout<<"Name : "<<it->m_Name<<"\tAge : "<<it->m_Age<<endl;
    cout<<endl;
}


//set 构造和赋值
void test01(){
    set<int> s1;
    for (int i = 5; i > 0; i--)
        s1.insert(i);       //按照 所有元素 自动排序
    s1.insert(5);           //set 不允许 重复插入值
    printSet(s1);

    set<int> s2(s1);
    printSet(s2);
    
}


//set 大小 交换
void test02(){
    set<int> s1;
    for (int i = 5; i > 0; i--)
        s1.insert(i);
    
    set<int> s2;
    for (int i = 0; i < 10; i++)
        s2.insert(i);


    if (s1.empty())
        cout<<"Set is Empty!"<<endl;
    else{
        cout<<"Set1's Size : "<<s1.size()<<endl;
        printSet(s1);
    }
    printSet(s2);

    s1.swap(s2);

    cout<<"Exchange :"<<endl;
    printSet(s1);
    printSet(s2);

}

//set 插入删除
void test03(){
    set<int> s1;
    for (int i = 5; i > 0; i--)
        s1.insert(i);

    printSet(s1);

    s1.erase(s1.begin());
    printSet(s1);

    s1.erase(3);
    printSet(s1);

    s1.clear();
    printSet(s1);

}

//set 查找 统计
void test04(){
    set<int> s1;
    for (int i = 5; i > 0; i--)
        s1.insert(i);

    set<int>::iterator pos = s1.find(3);

    if (pos != s1.end())
    {
        cout<<"Find "<<*pos<<endl;
    }
    else
        cout<<"Unfounded !"<<endl;
    
    int num = s1.count(3);
    cout<<"Counting 3's time : "<<num<<endl;
    
}

//set 和 multiset
void test05(){
    set<int> s1;
    for (int i = 3; i > 0; i--){
        pair<set<int>::iterator,bool> ret = s1.insert(10);
        if (ret.second)
        {
            cout<<"Input Done!"<<endl;
        }
        else{
            cout<<"ERROR"<<endl;
        }
    }


    multiset<int> s2;
    for (int i = 3; i > 0; i--)
        s2.insert(10);
    printMultiset(s2);


}

//pair
void test06(){
    pair<string,int> p("Tom",23);
    cout<<"Name : "<<p.first<<"\tAge : "<<p.second<<endl;


    pair<string,int> p2 = make_pair("Wendy",23);
    cout<<"Name : "<<p2.first<<"\tAge : "<<p2.second<<endl;

}

//set 存放内置数据类型 容器排序

//仿函数技术
bool mCompare::operator()(int a,int b){
    return a>b;
}

void test07(){
    set<int> s1;
    for (int i = 5; i > 0; i--)
        s1.insert(i);

    printSet(s1);

    //制定规则 排序 从大到小
    set<int,mCompare> s2;
    for (int i = 0; i < 10; i++)
        s2.insert(i+1);
    printReset(s2);

}

//set 存放自定义数据类型 容器排序
bool pCompare::operator()(const Person &p1,const Person &p2){
    return p1.m_Age > p2.m_Age;     //实现降序 前边Age 大于 后边Age
}

Person::Person(string name,int age)
{
    this->m_Name = name;
    this->m_Age = age;
}


void test08(){
    set<Person,pCompare> s;      //自定义数据类型 都需要指定排序规则

    Person p1("GodOuO",24);
    Person p2("Wendy",23);
    Person p3("Sun",999);
    Person p4("MonkTang",1000);

    s.insert(p1);
    s.insert(p2);
    s.insert(p3);
    s.insert(p4);

    printPersonSet(s);    

}

int main(){
    //test01();
    //test02();
    //test03();
    //test04();
    //test05();
    //test06();
    //test07();
    test08();
    
}
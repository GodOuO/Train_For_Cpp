#include<iostream>
#include<string>
#include<vector>
using namespace std;
//vector 容器存放 自定义数据类型
class Person
{
private:
    string m_Name;
    int m_Age;
public:
    Person(string name,int age);
    string getName();
    int getAge();
};

Person::Person(string name,int age){
    this->m_Name = name;
    this->m_Age = age;
}

string Person::getName(){
    return m_Name;
}

int Person::getAge(){
    return m_Age;
}

void test01(){
    vector<Person> v;

    Person p1("GodOuO",23);
    Person p2("GA",33);
    Person p3("GB",23);
    Person p4("GC",23);
    Person p5("Wendy",23);

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);


    //遍历容器数组
    for (vector<Person>::iterator i = v.begin(); i != v.end(); i++){
                        //*i 的数据类型 == <>内的数据类型
        cout<<"Name : "<<(*i).getName()<<"\tAge : "<<(*i).getAge()<<endl;
    }

    cout<<endl;

    for (vector<Person>::iterator i = v.begin(); i != v.end(); i++){
                        //i 类似指针类型
        cout<<"Name : "<<i->getName()<<"\tAge : "<<i->getAge()<<endl;
    }
}

//存放自定义数据类型的 指针
void test02(){
    vector<Person*> v;

    Person p1("GodOuO",23);
    Person p2("Ga",33);
    Person p3("Gb",23);
    Person p4("Gc",23);
    Person p5("Wendy",23);

    //容器中 存放五个元素的数据地址
    v.push_back(&p1);
    v.push_back(&p2);
    v.push_back(&p3);
    v.push_back(&p4);
    v.push_back(&p5);

    //遍历 容器
    for (vector<Person*>::iterator i = v.begin(); i != v.end(); i++)
        cout<<"Name : "<<(*i)->getName()<<"\tAge : "<<(*i)->getAge()<<endl;

    cout<<endl;

    for (vector<Person*>::iterator i = v.begin(); i != v.end(); i++){
        Person *p = (*i);   //the same as before
        cout<<"Name : "<<p->getName()<<"\tAge : "<<p->getAge()<<endl;
    }
        
}

int main(){
    //test01();
    test02();
}
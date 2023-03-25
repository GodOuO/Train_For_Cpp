#include<iostream>
#include<string>
#include<queue>
using namespace std;

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

Person::Person(string name,int age)
{
    this->m_Name = name;
    this->m_Age = age;
}

string Person::getName(){
    return m_Name;
}
int Person::getAge(){
    return m_Age;
}


//queue 队列
void test01(){
    queue<Person> q;
    Person p1("GodOuO",23);
    Person p2("Wendy",23);
    Person p3("MonkeySun",999);
    Person p4("MonkTang",9999);

    q.push(p1);
    q.push(p2);
    q.push(p3);
    q.push(p4);

    cout<<"Queue's Size : "<<q.size()<<endl;
    while (!q.empty())
    {
        cout<<"Queue's Top Name : "<<q.front().getName()
            <<"\tTop Age : "<<q.front().getAge()<<endl;

        cout<<"Queue's Back Name : "<<q.back().getName()
            <<"\tBack Age : "<<q.back().getAge()<<endl;

        q.pop();
    }

    cout<<"PopQueue's Size : "<<q.size()<<endl;
    
}

int main(){
    test01();
}
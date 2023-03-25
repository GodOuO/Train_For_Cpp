#include<iostream>
#include<string>
using namespace std;
class Person
{
private:
    int m_age;
public:
    void showClassName(){
        if(NULL == this)
            return;
        cout<<"This is Person Class!"<<endl;
    }
    void showAge(){
        if(NULL == this)
            return;
        cout<<"Age :\t"<<this->m_age<<endl;   //报错原因是因为 传入的指针为空this->m_age
    }
       
    
    Person(/* args */);
    ~Person();
};

Person::Person(/* args */)
{
}

Person::~Person()
{
}

void test01(){
    Person *p = NULL;
    p->showClassName();
    p->showAge();
}

int main(){
    test01();
}
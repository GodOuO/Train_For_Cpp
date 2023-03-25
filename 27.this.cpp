#include<iostream>
#include<string>
using namespace std;
class Person
{
private:
    int age;
public:
    int getAge(){
        return age;
    }
    void PersonAddAge(Person &p);       //Person &p传入
    Person& PersonAddAge_Plus(Person &p);  //Person &连续传入
    Person(int age);
    ~Person();
};

Person::Person(int age)
{
    this->age = age;    //this指针指向 被调用函数 所属的对象
}

void Person::PersonAddAge(Person &p){
    this->age += p.age; //将传入的P的age 加入自身age中
}

Person& Person::PersonAddAge_Plus(Person &p){
    this->age += p.age;
    return *this;
}

Person::~Person()
{
}

void test01(){
    Person p1(18);
    cout<<"P1's Age:\t"<<p1.getAge()<<endl;
}

void test02(){
    Person p1(10);
    Person p2(51);
    p2.PersonAddAge(p1);
    cout<<"P2's Age:\t"<<p2.getAge()<<endl;

}

void test03(){
    Person p3(51);
    Person p4(100);
    p3.PersonAddAge_Plus(p4).PersonAddAge_Plus(p4).PersonAddAge_Plus(p4);
    cout<<"P3's Age_Plus:\t"<<p3.getAge()<<endl; 
}

int main(){
    //test01();
    test02();
    test03();
}
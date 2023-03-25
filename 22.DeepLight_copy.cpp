#include<iostream>
#include<string>
using namespace std;
//深拷贝浅拷贝
class Person
{
private:
    int m_age;
public:
    int *m_height;
    int getAge(){
        return m_age;
    }
    void setAge(int age){
        m_age = age;
    }
    Person(){
        cout<<"Person's 默认构造函数调用"<<endl;
    }
    Person(int age,int height){
        setAge(age);
        m_height = new int (height);        //堆区开辟数据
        cout<<"Person's 有参构造函数调用"<<endl;
    };
    ~Person(){
        if (m_height != NULL){
            delete m_height;    //浅拷贝的问题，内存将重复释放，用深拷贝解决
            m_height = NULL;
        }
        cout<<"Person's 析构函数调用"<<endl;
    }
    Person(const Person &p){                //拷贝构造函数，深拷贝
        cout<<"Person's 拷贝构造函数调用"<<endl;
        m_age = p.m_age;            //编译器完成
        //m_height = p.m_height;    //编译器完成，浅拷贝
        m_height = new int(*p.m_height);    //深拷贝，新指针
    }
};

void test01(){
    Person p1(18,160);
    int age = p1.getAge();
    cout<<"P1's Age : \t"<<age<<endl
        <<"P1's Height :\t"<<*p1.m_height<<endl;    //解引用
    Person p2(p1);              //编译器自动做拷贝构造函数，实现浅拷贝
    int age2 = p2.getAge();
    cout<<"P2's Age :\t"<<age2<<endl<<"P2's Height :\t"<<*p2.m_height<<endl;

}

int main(){
    test01();
}
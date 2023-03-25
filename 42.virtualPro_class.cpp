#include<iostream>
#include<string>
using namespace std;
//虚析构 和 纯虚析构

class Animal    //有了纯虚析构函数后，此类也为抽象类，无法实例化对象
{
private:
    /* data */
public:
    virtual void speak() = 0;   //纯虚函数
    Animal(/* args */);
    //virtual ~Animal();            //利用虚析构 解决父类指针释放子类对象不干净问题
    virtual ~Animal() = 0;          //利用纯虚析构 也能解决，但是需要集体函数
};

Animal::Animal(/* args */)
{
    cout<<"Animal createFunc()"<<endl;
}

Animal::~Animal(){          //纯虚函数的 具体函数实现
    cout<<"Animal Pure deleteFunc()"<<endl;
}

// Animal::~Animal()
// {
//     cout<<"Animal deleteFunc()"<<endl;
// }

class Cat : public Animal
{
private:
    string *m_Name;     //堆区属性
public:
    virtual void speak(){
        cout<<*m_Name<<"Cat is Speaking"<<endl;
    }
    Cat(string name);
    ~Cat();
};

Cat::Cat(string name)
{
    cout<<"Cat createFunc()"<<endl;
    m_Name = new string(name);   //new 出string的指针
}

Cat::~Cat()
{       //设计子类析构代码
    if (m_Name != NULL){
        cout<<*m_Name<<"Cat deleteFunc()"<<endl;
        delete m_Name;
        m_Name = NULL;
    }
}

void test01(){
    Animal * animal = new Cat("Tom");
    animal->speak();
    delete animal;        //释放 父类指针在析构时 不会调用子类析构函数，
                            //导致子类如果有堆区属性，导致内存泄漏
}
int main(){
    test01();
}
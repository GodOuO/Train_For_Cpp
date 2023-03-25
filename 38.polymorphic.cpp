#include<iostream>
#include<string>
using namespace std;
//多态
class Animal
{
private:
    /* data */
public:
    Animal(/* args */);
    virtual void speak(){       //父类 函数进行虚函数
        cout<<"Cat is Speaking!"<<endl;
    }
};

Animal::Animal(/* args */)
{
}

class Cat:public Animal
{
private:
    /* data */
public:
    Cat(/* args */);
    void speak(){    
        cout<<"Cat is Speaking!"<<endl;
    }
};

Cat::Cat(/* args */)
{
}

class Dog:public Animal
{
private:
    /* data */
public:
    Dog(/* args */);
    virtual void speak(){
        cout<<"Dog is Speaking!"<<endl;
    }
};

Dog::Dog(/* args */)
{
}

//地址早绑定，编译阶段「确定函数地址」
//virtual 父类函数 实现虚函数，支持地址晚绑定
void doSpeak(Animal &a){        //Animal & a = cat;
    a.speak();                  
}

void test01(){
    Cat cat;
    doSpeak(cat);           //允许父子之间的类型转换
    Dog dog;
    doSpeak(dog);
}

void test02(){
    cout<<sizeof(Animal)<<endl;     //指针8字节，Animal 类
}

int main(){
    //test01();
    test02();
}
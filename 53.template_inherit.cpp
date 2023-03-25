#include<iostream>
#include<string>
using namespace std;
//类模版与继承

template<class T>
class Base{
private:
    T m;
public:
};


//class Son : public Base   //错误，必须知道父类 T 类型，才能继承子类
class Son : public Base<int>
{
private:
public:
};

//灵活继承父类中 T类型 子类也需要类模版
template<class T1,class T2>
class Son2 : public Base<T1>
{
private:
    T2 obj; 
public:
    Son2(){
        cout<<"T1's type is : "<<typeid(T1).name()<<endl
            <<"T2's type is : "<<typeid(T2).name()<<endl;
    }
};


void test01(){
    Son s1;
    Son2<int,char>s2;   //T1 = int;  T = T2 = char;
}

int main(){
    test01();
}
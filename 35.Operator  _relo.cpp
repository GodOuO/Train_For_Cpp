#include<iostream>
#include<string>
using namespace std;
//重载 ++ -- 递增运算符
class MyInteger
{
friend ostream & operator<<(ostream &cout,MyInteger myint);
private:
    int m_Num;
public:
    MyInteger(/* args */);
    MyInteger & operator++();       //前置递增
    MyInteger operator++(int);      //后置递增  int占位符,返回值（销毁temp）
    MyInteger & operator--();       //前置递增
    MyInteger operator--(int);      //后置递增  int占位符,返回值（销毁temp）
};

MyInteger::MyInteger(/* args */)
{
    m_Num = 0;
}

ostream & operator<<(ostream &cout,MyInteger myint){  //全局函数重载<<左移运算符
    cout<<myint.m_Num;
    return cout;
}

MyInteger & MyInteger::operator++(){    //实现 ++MyInteget 成员函数-前置递增
    m_Num++;
    return *this;   //返回 自身指针解引用 == 自身
}

MyInteger MyInteger::operator++(int){    //实现 MyInteget++ 成员函数-后置递增
    MyInteger temp = *this; //1.记录自身结果
    m_Num++;                //2.递增
    return temp;            //3.记录返回
}

MyInteger & MyInteger::operator--(){    //实现 --MyInteget 成员函数-前置递减
    m_Num--;
    return *this;   //返回 自身指针解引用 == 自身
}

MyInteger MyInteger::operator--(int){    //实现 MyInteget-- 成员函数-后置递减
    MyInteger temp = *this; //1.记录自身结果
    m_Num--;                //2.递增
    return temp;            //3.记录返回
}

void test01(){  //前置递增
    MyInteger myint;
    cout<<myint<<endl;
    cout<<++myint<<endl;
    cout<<++myint<<endl;
}

void test02(){  //后置递增
    MyInteger myint;
    cout<<myint<<endl;
    cout<<myint++<<endl;
    cout<<myint++<<endl;
}

void test03(){  //前置递减
    MyInteger myint;
    cout<<myint<<endl;
    cout<<--myint<<endl;
    cout<<--myint<<endl;
}

void test04(){  //后置递减
    MyInteger myint;
    cout<<myint<<endl;
    cout<<myint--<<endl;
    cout<<myint--<<endl;
}

int main(){
    //test01();
    //test02();
    //test03();
    test04();
}
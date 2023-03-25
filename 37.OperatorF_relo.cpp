#include<iostream>
#include<string>
using namespace std;
//函数调用运算符重载，仿函数
class MyPrint
{
private:
    /* data */
public:
    MyPrint(/* args */);
    void operator()(string thing);
};
class MyAdd
{
private:
    /* data */
public:
    int operator()(int num1,int num2);
    MyAdd(/* args */);
    
};

MyAdd::MyAdd(/* args */)
{
}

int MyAdd::operator()(int num1,int num2){   //函数调用运算符（）重载 传 int*2
    return num1+num2;
}

MyPrint::MyPrint(/* args */)
{
}
void MyPrint::operator()(string thing){     //函数调用运算符（）重载 传 string
    cout<<thing<<endl;
}

void MyPrint02(string thing){
    cout<<thing<<endl;
}

void test01(){
    MyPrint p;
    p("Hello word");            //重载 ( )  仿函数
    MyPrint02("Hello word");    //函数调用
}

void test02(){
    MyAdd add;
    int ret = add(100,100);
    cout<<"Result: "<<ret<<endl; 
}

void test03(){
    cout<<"Result: "<<MyAdd()(100,200)<<endl;   //匿名 函数对象（仿函数）
}
int main(){
    //test01();
    //test02();
    test03();
}
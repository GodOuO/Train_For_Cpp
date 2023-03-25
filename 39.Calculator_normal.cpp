#include<iostream>
#include<string>
using namespace std;
//普通案例，设计实现两个操作数进行运算的计算机类
class Calculator
{
private:
    int m_Num1;
    int m_Num2;
public:
    void setNum(int num1,int num2);
    int getNum1();
    int getNum2();
    int getResult(string oper);
};
void Calculator::setNum(int num1,int num2){
    m_Num1 = num1;
    m_Num2 = num2;
}
int Calculator::getNum1(){
    return m_Num1;
}
int Calculator::getNum2(){
    return m_Num2;
}
int Calculator::getResult(string oper){
    if("+" == oper)
        return m_Num1+m_Num2;
    else if("-" == oper)
        return m_Num1-m_Num2;
    else if("*" == oper)
        return m_Num1*m_Num2;
    else
        return 0;
}

void test01(){
    Calculator c;
    c.setNum(10,10);
    cout<<c.getNum1()<<" + "<<c.getNum2()<<" = "<<c.getResult("+")<<endl;
    cout<<c.getNum1()<<" - "<<c.getNum2()<<" = "<<c.getResult("-")<<endl;
    cout<<c.getNum1()<<" * "<<c.getNum2()<<" = "<<c.getResult("*")<<endl;
}

int main(){
    test01();
}
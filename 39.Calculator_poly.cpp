#include<iostream>
#include<string>
using namespace std;
//多态案例，设计实现两个操作数进行运算的计算机类
/*  如果需要扩展新功能，需要 修改源码
      
    开闭原则：对扩展进行开放，对修改进行关闭 
    
    多态的好处：
            1.组织结构清晰
            2.可读性强
            3.对于后期/前期 的拓展维护性高
            4.支持 开闭原则
    */

//实现计算器抽象类
class AbstractCalculator
{
private:
    int m_Num1;
    int m_Num2;
public:
    void setNum(int n1,int n2);
    int getNum1();
    int getNum2();
    virtual int getResult(){
        return 0;
    }
    AbstractCalculator(/* args */);
};
void AbstractCalculator::setNum(int n1,int n2){
    m_Num1 = n1;
    m_Num2 = n2;
}
int AbstractCalculator::getNum1(){
    return m_Num1;
}
int AbstractCalculator::getNum2(){
    return m_Num2;
}
AbstractCalculator::AbstractCalculator(/* args */)
{
}


class AddCalculator:public AbstractCalculator
{   //加法类实现
private:
    /* data */
public:
    int getResult(){
        return getNum1()+getNum2();
    }
};

class SubCalculator:public AbstractCalculator
{       //减法类实现
private:
    /* data */
public:
    int getResult(){
        return getNum1()-getNum2();
    }
};

class MulCalculator:public AbstractCalculator
{       //乘法类实现
private:
    /* data */
public:
    int getResult(){
        return getNum1()*getNum2();
    }
};

void test01(){
    //多态使用条件 ： 父类指针/引用 指向子类对象
    AbstractCalculator * abc = new AddCalculator;   //创建加法计算器对象
                    //用父类指针    //子类对象
    abc->setNum(10,10);
    cout<<abc->getNum1()<<" + "<<abc->getNum2()<<" = "<<abc->getResult()<<endl;
    delete abc;     //用完记得销毁！

    abc = new SubCalculator;    //重新 new 堆区数据
    abc->setNum(100,100);
    cout<<abc->getNum1()<<" - "<<abc->getNum2()<<" = "<<abc->getResult()<<endl;
    delete abc;
    
    abc = new MulCalculator;    //重新 new 堆区数据
    abc->setNum(100,100);
    cout<<abc->getNum1()<<" * "<<abc->getNum2()<<" = "<<abc->getResult()<<endl;
    delete abc;
}
int main(){
    test01();
}
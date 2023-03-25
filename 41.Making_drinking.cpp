#include<iostream>
#include<string>
using namespace std;
/*  制作饮品 ：煮水-冲泡-倒入杯中-加入辅料
    利用多态，提供抽象类制作饮品基类，
    提供子类制作：咖啡，茶叶
*/
class AbstractDrinking
{
private:
    /* data */
public:
    virtual void Boil() = 0;
    virtual void Brew() = 0;
    virtual void PourInCup() = 0;
    virtual void PutSth() = 0;
    void makeDrink();
    virtual ~AbstractDrinking(){
        cout<<"delete AbstractDrinking Func()"<<endl;
        };
};

void AbstractDrinking::makeDrink(){
    Boil();
    Brew();
    PourInCup();
    PutSth();
}

class Coffee : public AbstractDrinking
{
private:
    /* data */
public:
    virtual void Boil(){
        cout<<"Boiling..."<<endl;
    }
    virtual void Brew(){
        cout<<"Brewing Coffee..."<<endl;
    }
    virtual void PourInCup(){
        cout<<"Pour In the CoffeeCup!"<<endl;
    }
    virtual void PutSth() {
        cout<<"Put In the Suger and Milk!"<<endl;
    }
};

class Tea : public AbstractDrinking
{
private:
    /* data */
public:
    virtual void Boil(){
        cout<<"Boiling..."<<endl;
    }
    virtual void Brew(){
        cout<<"Brewing Tea..."<<endl;
    }
    virtual void PourInCup(){
        cout<<"Pour In the TeaCup!"<<endl;
    }
    virtual void PutSth() {
        cout<<"Put In the Lemon!"<<endl;
    }
};


void doWork(AbstractDrinking * abs){    //父类的指针 指向子类对象
    abs->makeDrink();
    delete abs;     //Visual Studio，指针释放
}

void test01(){
    doWork(new Coffee); //制作咖啡
    cout<<"--------------------"<<endl;
    doWork(new Tea);    //制作茶
}
int main(){
    test01();
}
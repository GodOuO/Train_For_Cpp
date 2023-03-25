#include<iostream>
#include<string>
using namespace std;
//函数对象 （仿函数）
/* 
    函数对象使用时，有自己的参数 返回值
    函数对象超出普通函数概念 可以有自己的状态
    函数对象 可以作为参数传递
 */

class mAdd
{
private:
    /* data */
public:
    int operator()(int a,int b){
        return a+b;
    }
};

class mPrint
{
private:
    int m_Count;
public:
    void operator()(string test){
        this->m_Count++;
        cout<<test<<endl;
    }
    mPrint(){
        this->m_Count = 0;
    }
    int getCount(){
        return m_Count;
    }
};


void test01(){
    mAdd madd;
    cout<<"10+10 = "<<madd(10,10)<<endl;        //像普通函数的调用
}

void test02(){
    mPrint mp;
    for(int i = 0; i < 5;i++)
        mp("Hello world");

    cout<<"mPrint Running time : "<<mp.getCount()<<endl;

}

void doPrint(mPrint &mp,string test){
    mp(test);
}
void test03(){
    mPrint mp;
    doPrint(mp,"Hello World, C++");
}
    

int main(){
    //test01();
    //test02();
    test03();
}
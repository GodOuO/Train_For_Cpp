#include<iostream>
#include<string>
#include"30.Class_Building.h"
using namespace std;
//类做友元

class GoodGay
{
private:
    /* data */
public:
    Building * build;
    void visit();       //参观函数，访问Building中属性
    GoodGay(/* args */);
};

GoodGay::GoodGay(/* args */){
    build = new Building;   //堆区 创建建筑物对象，上文有 *build
}

void GoodGay::visit(){
    cout<<"Class GoodGay is visiting : "<<build->m_SittingRoom<<endl;
    cout<<"Class GoodGay is visiting : "<<build->m_BedRoom<<endl;   //friend
}

void test01(){
    GoodGay g;
    g.visit();
}

int main(){
    test01();
}
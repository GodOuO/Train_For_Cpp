#include<iostream>
#include<string>
using namespace std;
class Building;
class GoodGay
{
private:
    Building * build;
public:
    GoodGay(/* args */);
    void visit();       //让visit函数 可以访问Building中 私有成员
    void visit2();      //visit2   不可以访问Building中 私有成员
};

class Building
{
friend void GoodGay::visit();   //GoodGay下 visit函数 在本类可以访问私有成员
private:
    string m_BedRoom;
public: 
    Building(/* args */);
    string m_SittingRoom;
};

Building::Building(/* args */)
{
    this->m_SittingRoom = "SittingRoom";
    this->m_BedRoom = "BedRoom";
}

GoodGay::GoodGay(/* args */){
    build = new Building;   //堆区 创建建筑物对象，上文有 *build
}

void GoodGay::visit(){
    cout<<"funVisit is visiting : "<<build->m_SittingRoom<<endl;
    cout<<"funVisit is visiting : "<<build->m_BedRoom<<endl;   //friend
}

void GoodGay::visit2(){
    cout<<"funVisit2 is Loading :\t"<<build->m_SittingRoom<<endl;
    //cout<<"Visit2 is Loading :\t"<<build->m_BedRoom<<endl;    //无权限
}

void test01(){
    GoodGay g;
    g.visit();
    g.visit2();
}

int main(){
    test01();
}
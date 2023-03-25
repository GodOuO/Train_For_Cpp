#include<iostream>
#include<string>
#include"30.Class_Building.h"
using namespace std;
//全局函数做友元


void goodGay(Building *Build){
    cout<<"goodGay is Loading: "<<Build->m_SittingRoom<<endl;
    cout<<"goodGay is Loading: "<<Build->m_BedRoom<<endl;
}

void test01(){
    Building b;
    goodGay(&b);
}

int main(){
    test01();
}
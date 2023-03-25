#include<iostream>
#include<string>
using namespace std;
//设计一个类 圆的周长
const double PI = 3.14159265;
class Circle{
public:
    double m_r;
    double calculateZC(){
        return 2*PI*m_r;
    }
};

int main(){
    Circle c1;
    cout<<"Please Input R:"<<endl;
    cin>>c1.m_r;
    cout<<"Circile's circumferenec: "<<c1.calculateZC()<<endl;
}
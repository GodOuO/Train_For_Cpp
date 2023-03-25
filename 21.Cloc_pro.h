#pragma once
#include<iostream>
#include<string>
#include"21.Ploc_pro.h"
using namespace std;
class Cricle{
private:
    double m_R;
    Point m_Center;     //在类中 可以让另一个类作为本类成员
public:
    void setR(double r);
    void setCenter(Point c);
    double getR();
    Point getCenter();
};


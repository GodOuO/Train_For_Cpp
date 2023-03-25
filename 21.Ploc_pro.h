#pragma once
#include<iostream>
#include<string>
using namespace std;
class Point{
private:
    double m_x;
    double m_y;
public:
    void setX(double x);
    void setY(double y);
    double getX();
    double getY();
    void showPoint();
};

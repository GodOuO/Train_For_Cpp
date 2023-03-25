#include"21.Ploc_pro.h"

void Point::setX(double x){     //成员函数
        m_x = x;
    }
void Point::setY(double y){
        m_y = y;
    }
double Point::getX(){
        return m_x;
    }
double Point::getY(){
        return m_y;
    }
void Point::showPoint(){
        cout<<"( "<<m_x<<" , "<<m_y<<" )"<<endl;
    }
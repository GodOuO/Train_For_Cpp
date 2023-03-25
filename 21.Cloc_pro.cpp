#include"21.Cloc_pro.h"

void Cricle::setR(double r){
        m_R = r;
    }
void Cricle::setCenter(Point c){
        m_Center = c;
    }
double Cricle::getR(){
        cout<<"Crecle's R:\t"<<m_R<<endl;
        return m_R;
    }
Point Cricle::getCenter(){
        return m_Center;
    }
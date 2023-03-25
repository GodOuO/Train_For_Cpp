#include<iostream>
#include<string>
#include<math.h>
using namespace std;
class Point{
private:
    double m_x;
    double m_y;
public:
    void setX(double x){
        m_x = x;
    }
    void setY(double y){
        m_y = y;
    }
    double getX(){
        return m_x;
    }
    double getY(){
        return m_y;
    }
    void showPoint(){
        cout<<"( "<<m_x<<" , "<<m_y<<" )"<<endl;
    }
};

class Cricle
{
private:
    double m_R;
    Point m_Center;     //在类中 可以让另一个类作为本类成员
public:
    void setR(double r){
        m_R = r;
    }
    void setCenter(Point c){
        m_Center = c;
    }
    double getR(){
        cout<<"Crecle's R:\t"<<m_R<<endl;
        return m_R;
    }
    Point getCenter(){
        return m_Center;
    }
};

void isCercleLoc(Cricle &c,Point &p){
    double dis = pow(c.getCenter().getX()-p.getX(),2)
                +pow(c.getCenter().getY()-p.getY(),2);
    double disR = pow(c.getR(),2);
    if(dis == disR)
        cout<<"Point On the Cricle!"<<endl;
    else if(dis > disR)
        cout<<"Point Out of Circle!"<<endl;
    else
        cout<<"Point In the Circle!"<<endl;
}

int main(){
    Cricle c;
    Point c_p;
    Point p;
    double p_x,p_y,c_x,c_y,c_r;
    cout<<"Please Input Point's X:"<<endl;
    cin>>p_x;
    cout<<"Please Input Point's Y:"<<endl;
    cin>>p_y;
    cout<<"Please Input Circle's X:"<<endl;
    cin>>c_x;
    cout<<"Please Input Circle's Y:"<<endl;
    cin>>c_y;
    cout<<"Please Input Circle's R:"<<endl;
    cin>>c_r;
    p.setX(p_x);
    p.setY(p_y);
    
    c.setR(c_r);
    c_p.setX(c_x);
    c_p.setY(c_y);
    c.setCenter(c_p);
    
    cout<<"Point:\t";
    p.showPoint();

    cout<<"Circle:\t";
    c_p.showPoint();

    isCercleLoc(c,p);

}
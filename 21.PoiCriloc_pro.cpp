#include<iostream>
#include<string>
#include<math.h>
#include"21.Ploc_pro.h"
#include"21.Cloc_pro.h"
#include"21.Ploc_pro.cpp"
#include"21.Cloc_pro.cpp"
using namespace std;

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
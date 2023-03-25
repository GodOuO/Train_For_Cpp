#include<iostream>
#include<string>
using namespace std;
/* 立方体类：
    求立方体面积，体积
    全局函数 成员函数 判断两个立方体是否相等
 */
class Cube
{
public:
void setL(double l){
    m_L = l;
}
void setW(double w){
    m_W = w;
}
void setH(double h){
    m_H = h;
}
double getL(){
    return m_L;
}
double getW(){
    return m_W;
}
double getH(){
    return m_H;
}

double cubeS(){
    return (m_H*m_L+m_H*m_W+m_L*m_W)*2;
}
double cubeV(){
    return (m_H*m_L*m_W);
}

bool isSame_class(Cube &c){             //成员函数判断
    if(m_H==c.getH()&&m_L==c.getL()&&m_W==c.getW()){
        cout<<"They are SAME!"<<endl;
        return 1;
    }
    else{
        cout<<"A is NOT same as B!" <<endl;
        return 0;
    }
}

private:
    double m_L;
    double m_W;
    double m_H;
};

bool IsSame(Cube &c1,Cube &c2){         //全局函数判断
    if(c1.getH()==c2.getH()&&c1.getL()==c2.getL()&&c1.getW()==c2.getW()){
        cout<<"They are SAME!_ByClass"<<endl;
        return 1;
    }
    else{
        cout<<"A is NOT same as B!_ByClass" <<endl;
        return 0;
    }
}

int main(){
    Cube c1;
    Cube c2;
    double h,w,l;
    cout<<"Input CubeA's H:"<<endl;
    cin>>h;
    c1.setH(h);
    cout<<"Input CubeA's W:"<<endl;
    cin>>w;
    c1.setW(w);
    cout<<"Input CubeA's L:"<<endl;
    cin>>l;
    c1.setL(l);
    cout<<"CubeA's S: "<<c1.cubeS()<<endl<<"CubeA's V: "<<c1.cubeV()<<endl;
    
    cout<<"Input CubeB's H:"<<endl;
    cin>>h;
    c2.setH(h);
    cout<<"Input CubeB's W:"<<endl;
    cin>>w;
    c2.setW(w);
    cout<<"Input CubeB's L:"<<endl;
    cin>>l;
    c2.setL(l);
    cout<<"CubeB's S: "<<c2.cubeS()<<endl<<"CubeB's V: "<<c2 .cubeV()<<endl;
    IsSame(c1,c2);
    c1.isSame_class(c2);

}
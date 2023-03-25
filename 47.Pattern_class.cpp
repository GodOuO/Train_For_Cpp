#include<iostream>
#include<string>
using namespace std;
//函数模版

void swapInt(int &a,int &b){
    int temp = a;
    a = b;
    b = temp;
}

void swapDouble(double &a,double &b){
    double temp = a;
    a = b;
    b = temp;
}

//声明一个模版，告诉编译器代码后紧跟的 T 不要报错，T 为通用数据列型
template <typename T> // twmplate <class T> 也可以
void Swap(T &a,T &b){
    T temp = a;
    a = b;
    b = temp;
}

int main(){
    int a = 10;
    int b = 20;
    double c = 1.1;
    double d = 2.2;

    swapInt(a,b);
    cout<<a<<" "<<b<<endl;
    swapDouble(c,d);
    cout<<c<<" "<<d<<endl;
    Swap(a,b);      //自动类型推导
    cout<<a<<" "<<b<<endl;
    Swap<double>(c,d);
    cout<<c<<" "<<d<<endl;
}
#include<iostream>
#include"12.swap.h"
using namespace std;
int main(){
    int a=0;
    int b=10;
    //swap_01(a,b);     //值传递
    //swap_02(&a,&b);   //地址传递
    swap_03(a,b);       //引用传递
    cout<<"Const a: "<<a<<", Const b: "<<b<<endl;
}


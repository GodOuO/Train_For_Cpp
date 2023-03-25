#include<iostream>
using namespace std;
void PrintArr(int * arr,int len){
    for(int i =0;i<len;i++)
        cout<<*(arr++)<<";";
}
int Max(int a,int b){
    return (a>=b?a:b);
}
void swap_01(int a,int b){  //值传递,形参不改变实参
    cout<<"Before a: "<<a<<", b: "<<b<<endl;
    int temp= a;
    a=b;
    b=temp;
    cout<<"Now a: "<<a<<", b: "<<b<<endl;
}
void swap_02(int *a,int *b){//地址传递
    int temp = *a;
    *a=*b;
    *b=temp;
}
void swap_03(int &a,int &b){  //引用传递
    int temp = a;
    a = b;
    b = temp;
}
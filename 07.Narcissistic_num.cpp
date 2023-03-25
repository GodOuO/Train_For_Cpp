#include<iostream>
#include<math.h>
using namespace std;
int main(){
    //水仙花数 三位数，每个位上数字的三次幂之和为本身
    //获取个位 %10
    cout<<"From 100 to 999,the narcissistic number is: \t";
    int num = 100;
    do
    {
        if(num==pow(num%10,3)+pow(num/10%10,3)+pow(num/100,3))
            cout<<num<<";";
        num++;
    } while (num<1000);
    cout<<endl;
}
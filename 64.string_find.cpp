#include<iostream>
#include<string>
using namespace std;
//string 查找 替换
void test01(){
    string s1 = "abcdefgde";
    int pos = s1.find("de");
    cout<<"'de''sPosition (find): "<<pos<<endl;

    pos = s1.find('z'); //未找到 return -1；
    cout<<"'z''sPosition : "<<pos<<endl;

    pos = s1.rfind("de");   //从右往左
    cout<<"'de''sPosition (rfind): "<<pos<<endl;
    
}

void test02(){
    string s1 = "abcdefgde";
    s1.replace(1,3,"1111");
    cout<<"S1_replace : "<<s1<<endl;
}
int main(){
    //test01();
    test02();
}
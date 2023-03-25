#include<iostream>
#include<string>
using namespace std;
//string 的构造函数

void test01(){
    string s1;      //默认构造
    
    const char * str = "Helloworld";
    string s2(str);
    cout<<"S2 : "<<s2<<endl;

    string s3(s2);
    cout<<"S3 : "<<s3<<endl;

    string s4(10,'a');
    cout<<"S4 : "<<s4<<endl;

}
int main(){
    test01();
}
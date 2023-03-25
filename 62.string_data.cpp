#include<iostream>
#include<string>
using namespace std;
//string 赋值操作

void test01(){
    string s1 = "Hello world";
    cout<<"S1 : "<<s1<<endl;

    string s2 = s1;
    cout<<"S2 : "<<s2<<endl;

    string s3;
    s3 = 'a';
    cout<<"S3 : "<<s3<<endl;

    string s4;
    s4.assign("Hello C++");
    cout<<"S4 : "<<s4<<endl;

    string s5;
    s5.assign("Hello C++",5);
    cout<<"S5(pre 5) : "<<s5<<endl;

    string s6;
    s6.assign(s5);
    cout<<"S6 : "<<s6<<endl;

    string s7;
    s7.assign(10,'w');
    cout<<"S7 : "<<s7<<endl;

}
int main(){
    test01();
}
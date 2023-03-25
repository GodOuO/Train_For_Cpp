#include<iostream>
#include<string>
using namespace std;
//string 字符串追加

void test01(){
    string s1 = "I";
    s1+=" love SH";
    cout<<"S1 : "<<s1<<endl;

    s1+='!';
    cout<<"S1+ : "<<s1<<endl;

    string s2 = " PUBG ";
    s2+=s1;
    cout<<"S2+ : "<<s2<<endl;

    string s3 = "Fu*k ";
    s3.append("Love");
    cout<<"S3 : "<<s3<<endl;

    s3.append(" your vagina",4);
    cout<<"S3(+4) : "<<s3<<endl;

    s3.append(s2);
    cout<<"S3+s2 : "<<s3<<endl;

    s3.append(s2,0,5);
    cout<<"S3+s2(0-4) : "<<s3<<endl;
}

int main(){
    test01();
}
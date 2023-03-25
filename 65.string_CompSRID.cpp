#include<iostream>
#include<string>
using namespace std;
//string 比较操作
void test01(){
    string s1 = "hello";
    string s2 = "hello";

    string s3 = "xello";

    if (s1.compare(s2) == 0){
        cout<<"S1 is SAME as s2!"<<endl;
    }
    if (s3.compare(s1) >0){
        cout<<"S3 Biger than S1!"<<endl;
    }
    if(s1.compare(s3) <0){
        cout<<"S1 smaller than S3!"<<endl;
    }
}

//string 存 取
void test02(){
    string s1 = "Hello";

    for (int i = 0; i < s1.size(); i++)
    {
        cout<<s1[i]<<" ";
    }
    cout<<endl;


    for (int i = 0; i < s1.size(); i++)
    {
        cout<<s1.at(i)<<";";
    }
    cout<<endl;
    
    s1.at(1) = 'F';
    s1[0] = 'F';

    cout<<"Exchange:"<<endl;
    for (int i = 0; i < s1.size(); i++)
    {
        cout<<s1.at(i)<<";";
    }
    cout<<endl;

}

//string 插 删
void test03(){
    string s1 = "Hello";

    s1.insert(1,"111");
    cout<<"S1 : "<<s1<<endl;

    s1.erase(1,3);
    cout<<"S1 : "<<s1<<endl;

}

//string 求 子串
void test04(){
    string s1 = "abcdef";
    string subs = s1.substr(1,3);
    cout<<"Sub string : "<<subs<<endl;
}

//从邮件地址中 获取 用户名信息
void test05(){
    string email = "13234159933@sina.cn";
    int pos = email.find('@');
    string userName = email.substr(0,pos);
    cout<<"UserName : "<<userName<<endl;

}

int main(){
    //test01();
    //test02();
    //test03();
    //test04();
    test05();
}
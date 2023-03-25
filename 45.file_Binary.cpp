#include<iostream>
#include<string>
#include<fstream>
using namespace std;
//二进制文件 写 读
/* 
    1.包含头文件
    2.创建流对象
    3.打开文件
        （3.）是否打开成功
    4.写/读文件
    5.关闭文件
 */
class Person
{
private:
    char m_Name[64];    //写入字符串，最好用 char字符数组
    int m_Age;
public:
    Person(char const name[64],int age);  //加const,因为char字符串值 不允许修改
    //无const:warning: conversion from string literal to 'char *' is deprecated
};
Person::Person(char const name[64],int age){
    strcpy(m_Name,name);
    m_Age = age;
}

class PersonRead
{
public:
    char m_Name[64];    //写入字符串，最好用 char字符数组
    int m_Age;
};

void Input01(){
    Person p("Zhang3",18);
    ofstream ofs("person.txt",ios::out | ios::binary);
    ofs.write((const char *)&p,sizeof(Person)); //变量1:const char * 数据地址；
                                                //变量2:int 长度(sizeof(类))
    ofs.close();
    cout<<"Output Done!!!"<<endl<<endl;
}

void Output01(){
    PersonRead p1;
    ifstream ifs("person.txt",ios::in | ios::binary);
    if (!ifs.is_open())
    {
        cout<<"File Open Fail!!!"<<endl;
        return;
    }

    ifs.read((char *)&p1,sizeof(Person));   //参数1: char * ； 参数2 int len
    cout<<"Name : "<<p1.m_Name<<endl<<"Age : "<<p1.m_Age<<endl;
    ifs.close();
}
int main(){
    Input01();
    Output01();
}
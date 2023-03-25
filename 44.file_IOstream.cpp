#include<iostream>
#include<string>
#include<fstream>
using namespace std;

void Input(){
    ofstream ofs;   //创建输出流对象
    ofs.open("44.IOstream.txt",ios::out);  //指定打开方式
    ofs<<"Name : Zhang3"<<endl<<"Sex : Male"<<endl<<"Age : 18"<<endl;
    ofs.close();
}

void Output01(){  //读数据
    ifstream ifs;   //创建输入流对象
    ifs.open("44.IOstream.txt",ios::in);    //指定读取方式
    if (!ifs.is_open()){
        cout<<"File is NOT exist!!!"<<endl;
        return;
    }

    //读数据01
    char buf[1024] = {0};
    cout<<"OutPut Way1:"<<endl;
    while(ifs>>buf){    //当行数据为空，退出
        cout<<buf<<endl;
    }
    ifs.close();
}

void Output02(){
    ifstream ifs;   //创建输入流对象
    ifs.open("44.IOstream.txt",ios::in);    //指定读取方式
    if (!ifs.is_open()){
        cout<<"File is NOT exist!!!"<<endl;
        return;
    }

    //读数据02
    char buf[1024] = {0};
    cout<<"OutPut Way2:"<<endl;
    while(ifs.getline(buf,sizeof(buf))){    //函数一行一行获取，
                                            //参数1 char*（放入哪个数组）
                                            //参数2 Count（读多大空间）
        cout<<buf<<endl;
    }
    ifs.close();
}

void Output03(){
    ifstream ifs;   //创建输入流对象
    ifs.open("44.IOstream.txt",ios::in);    //指定读取方式
    if (!ifs.is_open()){
        cout<<"File is NOT exist!!!"<<endl;
        return;
    }

    //读数据03
    string buf;
    cout<<"OutPut Way3:"<<endl;
    while (getline(ifs,buf)){  //通过全局函数
                                //参数1 basic_istream（输入流对象）
                                //参数2 string（准备的 读取字符串）
        cout<<buf<<endl;
    }
    ifs.close();
}

void Output04_Useless(){
    ifstream ifs;   //创建输入流对象
    ifs.open("44.IOstream.txt",ios::in);    //指定读取方式
    if (!ifs.is_open()){
        cout<<"File is NOT exist!!!"<<endl;
        return;
    }

    //读数据04_不推荐
    char c;
    cout<<"OutPut Way4:"<<endl;
    while ((c =ifs.get()) != EOF ){  //get()函数 每次只读一个字符，EOF文件尾
        cout<<c;
    }
    ifs.close();
}

int main(){
    Input();
    Output01();
    Output02();
    Output03();
    Output04_Useless();
}
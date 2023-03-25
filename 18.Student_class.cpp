#include<iostream>
#include<string>
using namespace std;
/*  设计学生类：姓名，学号
    可以赋值姓名学号，可以展示姓名学号
*/
class Student{
public:
    string s_Name;
    int s_Id;
    void showStudent(){
        cout<<"sName:\t"<<s_Name<<endl<<"s_Id:\t"<<s_Id<<endl;
    }
    void setStudent(string name,int id){
        s_Id = id;
        s_Name = name;
    }

};
int main(){
    Student s1;
    s1.s_Id = 181203616;
    s1.s_Name = "GodOuO";
    s1.showStudent();

    Student s2;
    string name;
    int num;
    cout<<"Input Name:"<<endl;
    cin>>name;
    cout<<"Input Id:"<<endl;
    cin>>num;
    s2.setStudent(name,num);
    s2.showStudent();
}
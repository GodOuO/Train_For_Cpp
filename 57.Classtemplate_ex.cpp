#include<iostream>
#include<string>
#include"57.mArray.hpp"
using namespace std;
/* 
    内置数据类型和自定义数据进行存储
        1.数组存入堆区
        2.构造函数可 传入数组容量
        3.提供对应拷贝构造函数 operator= 深拷贝，防止浅拷贝
        4.提供尾插法 尾删法 对数组中数据进行 增加删除
        5.通过index下标 访问数组元素
        6.获取数组元素个数 数组容量

    Goal：
    定义 Class mArray{
        private
            T * pAddress;   //数组（开辟在堆区）    T* = new T[len];
            m_Capacity;     //容量
            m_Size;         //大小
        public:
            构造函数（容量）；
            拷贝构造；
            operator=；
            index访问；
            尾插法；
            尾删法；
            获取数组容量；
            获取数组大小；
            ～析构；
        }
 */

void printIntArray(mArray<int>& arr){           //打印 T == int 类型数据
    for (int i = 0; i < arr.getSize(); i++)
    {
        cout<<arr[i]<<" ; ";
    }
    cout<<endl;
}

void test01(){
    mArray <int>arr1(5);    //有参构造
    mArray <int>arr2(arr1); //实现 深拷贝
    mArray <int>arr3(100);  //有参
    arr3 = arr1;            //operator +调用
}

void test02(){
    int len = 5;
    mArray <int>arr4(len);
    for (int i = 0; i < len; i++)
    {
        arr4.Push_Back(i);          //利用尾插法 向数组插入数据
    }
    cout<<"Array arr4's Data is :"<<endl;
    printIntArray(arr4);

    cout<<"Array arr4's Capacity : "<<arr4.getCapacity()<<endl
        <<"Array arr4's Size : "<<arr4.getSize()<<endl;

    mArray <int>arr5(arr4);
    cout<<"Array arr5's Data is :"<<endl;
    printIntArray(arr5);

    arr5.Pop_Back();                //尾删测试

    cout<<"PopBack Done!!!"<<endl
        <<"Array arr5's Data is :"<<endl;
    printIntArray(arr5);

    cout<<"Array arr5's Capacity : "<<arr5.getCapacity()<<endl
        <<"Array arr5's Size : "<<arr5.getSize()<<endl;
    
}


//测试 自定义数据类型
class Person
{
private:
    string m_Name;
    int m_Age;
public:
    Person();
    Person(string name,int age);
    string getName();
    int getAge();
};
Person::Person(){}

Person::Person(string name,int age){
    this->m_Name = name;
    this->m_Age = age;
}

string Person::getName(){
    return m_Name;
}

int Person::getAge(){
    return m_Age;
}

void printPersonArray(mArray<Person>& arr){     //打印 T = Person 类型数据
    for (int i = 0; i < arr.getSize(); i++)
        cout<<"Name : "<<arr[i].getName()<<"\tAge : "<<arr[i].getAge()<<endl;
    cout<<endl;
}

void test03(){          //测试自定义 Person数据类型
    mArray<Person> arr6(10);
    Person p1("GodOuO",23);
    Person p2("Wendy",23);
    Person p3("Sean",23);
    Person p4("Tom",999);
    Person p5("Jerry",998);
    //数据插入数组中
    arr6.Push_Back(p1);
    arr6.Push_Back(p2);
    arr6.Push_Back(p3);
    arr6.Push_Back(p4);
    arr6.Push_Back(p5);

    printPersonArray(arr6);

    cout<<"Array arr6's Capacity : "<<arr6.getCapacity()<<endl
        <<"Array arr6's Size : "<<arr6.getSize()<<endl;
}

int main(){
    test01();
    test02();
    test03();
}
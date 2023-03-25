//通用数组类
#pragma once
#include<iostream>
#include<string>
using namespace std;

template<class T>
class mArray
{
private:
    T * pAddress;   //指针指向堆区 开辟真实数组
    int m_Capacity; //数组容量
    int m_Size;     //数组大小

public:
    mArray(int capacity);                   //有参构造，在堆区创建T数据类型
    mArray(const mArray& arr);              //拷贝构造      防止浅拷贝
    mArray& operator=(const mArray& arr);   //操作符重载    防止浅拷贝
    void Push_Back(const T& val);           //尾插法    const 常量修饰
    void Pop_Back();                        //尾删法
    T& operator[](int index);               //通过下标访问数组元素  重载[]运算符，且作为左值赋值操作，需要为 引用数据类型
    int getCapacity();                      //返回数组容量
    int getSize();                          //返回数组大小
    ~mArray();                              //析构函数      释放堆区数据
};

template<class T>
mArray<T>::mArray(int capacity){
    //cout<<"Test :mArray Func(T)"<<endl;
    this->m_Capacity = capacity;
    this->m_Size = 0;
    this->pAddress = new T[this->m_Capacity];
}

template<class T>
mArray<T>::mArray(const mArray& arr){
    //cout<<"Test :mArray Copy Func(T)"<<endl;
    this->m_Capacity = arr.m_Capacity;
    this->m_Size = arr.m_Size;
    //this->pAddress = arr.pAddress;    //指针 重写拷贝构造函数，进行深拷贝
    this->pAddress = new T[arr.m_Capacity]; //实现深拷贝（22.cpp）
    for (int i = 0; i < this->m_Size; i++)
    {
        this->pAddress[i] = arr.pAddress[i];
    }
}

template<class T>
mArray<T>& mArray<T>::operator=(const mArray& arr){    //operator= 防止浅拷贝
    //先判断堆区是否有数据，如果有 先释放
    //cout<<"Test :mArray Operator="<<endl;
    if (this->pAddress != NULL)
    {
        delete this->pAddress;
        this->pAddress = NULL;
        this->m_Capacity = 0;
        this->m_Size = 0;
    }

    //深拷贝
    this->m_Capacity = arr.m_Capacity;
    this->m_Size = arr.m_Size;
    this->pAddress = new T[arr.m_Capacity];
    for (int i = 0; i < this->m_Size; i++)
        this->pAddress[i] = arr.pAddress[i];
    return *this;   //解引用
}

template<class T>
void mArray<T>::Push_Back(const T& val){    //尾插法
    //判断容量是否满
    if (this->m_Capacity == this->m_Size){
        cout<<"Array is FULL!!!"<<endl;
        return;
    }
    this->pAddress[this->m_Size] = val;     //末尾插入数据
    this->m_Size++;                         //更新数组大小
}

template<class T>
void mArray<T>::Pop_Back(){    //尾删法
    //让用户无法访问最后元素，尾删成功。    属于逻辑删除
    if (0 == this->m_Size)   //判断数据是否为空，空 无法删除
        return;
    this->m_Size--;
}

template<class T>
T& mArray<T>::operator[](int index){
    return this->pAddress[index];
}

template<class T>
int mArray<T>::getCapacity(){
    return m_Capacity;
}

template<class T>
int mArray<T>::getSize(){
    return m_Size;
}

template<class T>
mArray<T>::~mArray(){
    if (this->pAddress != NULL){
        //cout<<"Test :mArray DelFunc(T)"<<endl;
        delete[] this->pAddress;
        this->pAddress = NULL;
    }
}


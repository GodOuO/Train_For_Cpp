#include<iostream>
#include<string>
#include<deque>
#include<algorithm>
using namespace std;

void printDeque(const deque<int> &d){
    for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
        cout<<*it<<" ; ";
    cout<<endl;
}


//deque 构造函数
void test01(){
    deque<int> d1;
    for (int i = 0; i < 10; i++)
        d1.push_back(i+1);
    printDeque(d1);

    deque<int> d2(d1.begin(),d1.end()); //区间
    printDeque(d2);

    deque<int> d3(10,100);
    printDeque(d3);

    deque<int> d4(d3);
    printDeque(d4);

}

//deque 赋值操作
void test02(){
    deque<int> d1;
    for (int i = 0; i < 10; i++)
        d1.push_back(i+1);
    printDeque(d1);

    deque<int> d2;
    d2 = d1;
    printDeque(d2);

    deque<int> d3;
    d3.assign(d1.begin(),d1.end());
    printDeque(d3);

    deque<int> d4;
    d4.assign(10,100);
    printDeque(d4);

}

//deque 大小操作
void test03(){
    deque<int> d1;
    for (int i = 0; i < 10; i++)
        d1.push_back(i+1);
    printDeque(d1);

    if (d1.empty())
        cout<<"Deque is Empty!!!"<<endl;
    else{
        cout<<"Deque is Exist!"<<endl;
        cout<<"Deque's Size is : "<<d1.size()<<endl;    //deque 容器没有容量概念
    }

    d1.resize(15);
    printDeque(d1);

    d1.resize(16,1);
    printDeque(d1);

    d1.resize(5);
    printDeque(d1);

}

//deque 插入
void test04(){
    deque<int> d1;
    for (int i = 0; i < 5; i++)
        d1.push_back(i+1);
    printDeque(d1);

    d1.push_front(100);
    printDeque(d1);

    d1.pop_back();
    printDeque(d1);

    d1.pop_front();
    printDeque(d1);

}

//deque insert插入
void test05(){
    deque<int> d1;
    for (int i = 0; i < 5; i++)
        d1.push_back(i+1);
    printDeque(d1);

    d1.insert(d1.begin(),1000);
    printDeque(d1);

    d1.insert(d1.begin(),2,999);
    printDeque(d1);



    d1.clear();
    for (int i = 0; i < 5; i++)
        d1.push_back(i+1);
    deque<int> d2;
    for (int i = 0; i < 5; i++)
        d2.push_back(i);
    

    d1.insert(d1.begin(),d2.begin(),d2.end());
    printDeque(d1);

}

//deque 删除
void test06(){
    deque<int> d1;
    for (int i = 0; i < 5; i++)
        d1.push_back(i+1);
    printDeque(d1);

    deque<int>::iterator it = d1.begin();
    it++;
    d1.erase(it);   //删除第二个 elem
    printDeque(d1);

    d1.erase(d1.begin(),d1.end());
    printDeque(d1);

}

//deque 数据读取
void test07(){
    deque<int> d1;
    for (int i = 0; i < 5; i++)
        d1.push_back(i+1);

    for (int i = 0; i < d1.size(); i++)
        cout<<d1[i]<<" ; ";
    cout<<endl;
    
    for (int i = 0; i < d1.size(); i++)
        cout<<d1.at(i)<<" ; ";
    cout<<endl;

    cout<<"Begin with : "<<d1.front()<<endl;
    cout<<"End as     : "<<d1.back()<<endl;

}

//deque 容器排序
void test08(){
    deque<int> d;
    for (int i = 0; i < 5; i++){
        d.push_back(i+1);
        d.push_front(i);
    }

    printDeque(d);
    sort(d.begin(),d.end());    //对于支持随机访问的迭代器容器 均可采用sort进行直接排序
    cout<<"Sort : "<<endl;  
    printDeque(d);

}

int main(){
    //test01();
    //test02();
    //test03();
    //test04();
    //test05();
    //test06();
    //test07();
    test08();

    
}
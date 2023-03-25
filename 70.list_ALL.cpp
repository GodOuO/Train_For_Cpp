#include<iostream>
#include<string>
#include<list>
using namespace std;
//list 链表

void printList(const list<int> &l){
    for (list<int>::const_iterator it = l.begin(); it != l.end(); it++)
        cout<<*it<<" ; ";
    cout<<endl;
}

//list 容器 构造函数
void test01(){
    list<int> l1;
    for (int i = 0; i < 10; i++)
        l1.push_back(i+1);
    printList(l1);

    list<int> l2(l1.begin(),l1.end());
    printList(l2);

    list<int> l3;
    l3 = l2;
    printList(l3);

    list<int> l4(10,100);
    printList(l4);
}

//list 赋值 交换
void test02(){
    list<int> l1;
    for (int i = 0; i < 10; i++)
        l1.push_back(i+1);
    //printList(l1);


    list<int> l2;
    l2.assign(l1.begin(),l1.end());
    printList(l2);

    list<int> l3;
    l3.assign(10,100);
    printList(l3);

    cout<<"Change : "<<endl;
    l2.swap(l3);
    printList(l2);
    printList(l3);

}

//list 大小操作
void test03(){
    list<int> l1;
    for (int i = 0; i < 10; i++)
        l1.push_back(i+1);

    //l1.clear();

    if (!l1.empty())
        cout<<"List is Exist!"<<endl
            <<"List's Size : "<<l1.size()<<endl;
    else
        cout<<"List is Empty!"<<endl;

    l1.resize(15);
    printList(l1);

    l1.resize(20,51);
    printList(l1);

    l1.resize(0);
    printList(l1);
    cout<<"SIZE : "<<l1.size()<<endl;
    
}

//list 插入 删除
void test04(){
    list<int> l1;
    for (int i = 0; i < 10; i++)
        l1.push_back(i+1);
    printList(l1);

    l1.pop_back();
    l1.pop_front();
    printList(l1);

    list<int>::iterator it = l1.begin();
    l1.insert(it,1);
    l1.insert(l1.end(),10);
    printList(l1);

    l1.erase(l1.begin());
    printList(l1);


    l1.remove(2);
    printList(l1);
    
}

//list 数据存取
void test05(){
    list<int> l1;
    for (int i = 0; i < 10; i++)
        l1.push_back(i+1);
    printList(l1);

    //不支持 [] at()    不允许 it = it + 1;  仅支持it++；it--；
    list<int>::iterator it = l1.begin();
    it++;
    it--;
    //it = it + 1 ;     //ERROR


    cout<<"The Top elem : "<<l1.front()<<endl;
    cout<<"The Least elem : "<<l1.back()<<endl;

}

//list 反转排序
bool myCmopare(int v1,int v2){  //降序 成员函数内需要填入 其 回调函数
    //降序      让第一个数 大于第二个数
    return v1>v2;
}

void test06(){
    list<int> l1;
    for (int i = 0; i < 10; i++){
        l1.push_back(i+1);
        l1.push_front(i);
    }
    printList(l1);

    cout<<"Reverse_List : "<<endl;
    l1.reverse();
    printList(l1);
    
    cout<<"Sort_List :"<<endl;
    //l1.sort(l1.begin(),l1.end()); //所有不支持随机访问迭代器的容器，无法使用标准算法
    l1.sort();
    printList(l1);

    cout<<"reSort_List :"<<endl;
    l1.sort(myCmopare);
    printList(l1);

}



int main(){
    //test01();
    //test02();
    //test03();
    //test04();
    //test05();
    test06();
}
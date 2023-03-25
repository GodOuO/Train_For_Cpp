#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

void printIntVector(const vector<int> &v){
    for (vector<int>::const_iterator it = v.begin(); it != v.end(); ++it)
        cout<<*it<<" ; ";
    cout<<endl;
}
class mCompare
{
public:
    bool operator()(int a,int b){
        return a>b;
    }
};


//仿函数 返回值 bool类型，一个参数 == 一元谓词
class Greater5
{
public:
    bool operator()(int val){
        return val>5;
    }
};


void test01(){
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i+1);
    }

    //查找容器中 >5 的数据
    vector<int>::iterator it = find_if(v.begin(),v.end(),Greater5());  //传入 匿名函数对象
    if (it == v.end())
    {
        cout<<"Over5 is not in Vector"<<endl;
    }
    else{
        while (it != v.end())
            cout<<"Over5's data : "<<*(it++)<<endl;
    }

}

//仿函数 返回值 bool类型，2个参数 == 二元谓词
void test02(){
    vector<int> v;
    for (int i = 0; i < 10; i++){
        v.push_back(i+1);
    }
    for (int i = 5; i > 0; i--){
        v.push_back(i);
    }

    sort(v.begin(),v.end());
    printIntVector(v);
        
    //使用函数对象（仿函数）    改变算法策略，降序排序
    sort(v.begin(),v.end(),mCompare());       //参数加入 匿名函数对象，调用重载sort函数
    printIntVector(v);

}

int main(){
    //test01();
    test02();
}
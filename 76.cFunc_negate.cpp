#include<iostream>
#include<string>
#include<functional>
#include<vector>
#include<algorithm>
using namespace std;
class mCompare
{
public:
    bool operator()(int a,int b){
        return a>b;
    }
};


void printIntVector(const vector<int> &v){
    for (vector<int>::const_iterator it = v.begin(); it != v.end(); it++)
        cout<<*it<<" ; ";
    cout<<endl;
}

void printboolVector(const vector<bool> &v){
    for (vector<bool>::const_iterator it = v.begin(); it != v.end(); it++)
        cout<<*it<<" ; ";
    cout<<endl;
}


//内建函数对象 算数仿函数

//negate 取反 一元仿函数
void test01(){
    negate<int> n;
    cout<<"Negate 50 : "<<n(50)<<endl;      //-50

}

//plus 加法 二元仿函数
void test02(){
    plus<int> p;
    cout<<"50+50 = "<<p(50,50)<<endl;

}

//大于 greater  内建构造函数 ——关系仿函数
void test03(){
    vector<int> v;
    for (int i = 0; i < 5; i++)
        v.push_back(i+1);
    for (int i = 10; i >5; --i)
        v.push_back(i+1);
    printIntVector(v);

    //降序
    sort(v.begin(),v.end(),mCompare());
    printIntVector(v);
    sort(v.begin(),v.end(),greater<int>());     //greater<T>() 内建函数对象
    printIntVector(v);

}

//logical_not 逻辑非 ——逻辑仿函数
void test04(){
    vector<bool> v;
    for (int i = 0; i < 2; i++)
    {
        v.push_back(1);
        v.push_back(false);
    }
    printboolVector(v);

    //利用逻辑非 ，将容器v 搬运到 容器v2中，并执行取反
    vector<bool> v2;
    v2.resize(v.size());    //定义空间大小

    transform(v.begin(),v.end(),v2.begin(),logical_not<bool>());
    printboolVector(v2);

}



int main(){
    //test01();
    //test02();
    //test03();
    test04();
}
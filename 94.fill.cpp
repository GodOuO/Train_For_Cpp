#include<iostream>
#include<string>
#include<vector>
#include<numeric>
using namespace std;
//常用算数生成算法

class printIntVector
{
public:
    void operator()(int a){
        cout<<a<<" ; ";
    }
};


void test01(){
    vector<int> v;
    v.resize(10);
    for_each(v.begin(),v.end(),printIntVector());
    cout<<endl;

    //重新填充操作
    fill(v.begin(),v.end(),51);
    for_each(v.begin(),v.end(),printIntVector());
    cout<<endl;

}

int main(){
    test01();
}
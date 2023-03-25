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
    for (int i = 0; i < 100; i++)
        v.push_back(i+1);

    for_each(v.begin(),v.end(),printIntVector());
    cout<<endl;

    int ret = accumulate(v.begin(),v.end(),0);  //第三个参数 为 起始累加值
    cout<<"Total : "<<ret<<endl;
    
}

int main(){
    test01();
}
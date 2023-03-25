#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
//常用拷贝替换算法 copy

class printIntVector
{
public:
    void operator()(int a){
        cout<<a<<" ; ";
    }
};



void test01(){
    vector<int> v;
    for (int i = 0; i < 10; i++)
        v.push_back(i+1);
    for_each(v.begin(),v.end(),printIntVector());
    cout<<endl;


    vector<int> v2;
    v2.resize(v.size());

    copy(v.begin(),v.end(),v2.begin());     // = 重载一样可以实现功能
    for_each(v2.begin(),v2.end(),printIntVector());
    cout<<endl;

}

int main(){
    test01();
}
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
//常用拷贝和替换函数 replace_if
class printIntVector
{
public:
    void operator()(int a){
        cout<<a<<" ; ";
    }
};

class Greater5
{
public:
    bool operator()(int a){
        return a>=5;
    }
};




void test01(){
    vector<int> v;
    for (int i = 0; i < 20; i++)
        v.push_back(i+1);
    for_each(v.begin(),v.end(),printIntVector());
    cout<<endl;

    //将大于等于 5的 替换为 51
    replace_if(v.begin(),v.end(),Greater5(),51);
    cout<<"Replace elem which is biger than 5 to 51 !"<<endl;
    for_each(v.begin(),v.end(),printIntVector());
    cout<<endl;

}

int main(){
    test01();
}
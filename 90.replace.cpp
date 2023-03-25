#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
//常用拷贝替换算法 replace

class printIntVector
{
public:
    void operator()(int a){
        cout<<a<<" ; ";
    }
};


void tese01(){
    vector<int> v;
    for (int i = 0; i < 5; i++)
        v.push_back(i+1);
    for (int i = 0; i < 5; i++)
        v.push_back(1);
    for_each(v.begin(),v.end(),printIntVector());
    cout<<endl;

    //替换 ALL elem 1 为 51
    replace(v.begin(),v.end(),1,51);
    cout<<"Replact 1 to 51 !"<<endl;
    for_each(v.begin(),v.end(),printIntVector());
    cout<<endl;
 
}

int main(){
    tese01();
}
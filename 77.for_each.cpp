#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;


//便利算法 for_each
void printV(int a){     //普通函数
    cout<<a<<" ; ";
}

class printVcopy
{
public:
    void operator()(int a){
        cout<<a<<" ; ";
    }
};



void test01(){
    vector<int> v;
    for (int i = 0; i < 5; i++)
        v.push_back(i+1);
    
    for_each(v.begin(),v.end(),printV);     //键入函数名即可
    cout<<endl;

    for_each(v.begin(),v.end(),printVcopy());   //仿函数 匿名参数对象
    cout<<endl;

}



int main(){
    test01();
}
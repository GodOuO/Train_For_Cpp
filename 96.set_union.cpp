#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
//常用集合算法 set_union

class printIntVector
{
public:
    void operator()(int a){
        cout<<a<<" ; ";
    }
};


void test01(){
    vector<int> v;
    vector<int> v2;
    vector<int> vTarget;

    for (int i = 0; i < 100; i++)
    {
        v.push_back(i+1);
        v2.push_back(i+6);
    }

    for_each(v.begin(),v.end(),printIntVector());
    cout<<endl;
    for_each(v2.begin(),v2.end(),printIntVector());
    cout<<endl;

    vTarget.resize(v.size()+v2.size()); //最特殊 两个容器没交集 空间开辟两个size和

    vector<int>::iterator itEnd = set_union(v.begin(),v.end(),v2.begin(),v2.end(),vTarget.begin());

    for_each(vTarget.begin(),itEnd,printIntVector());   //使用 itEnd！否则将全部空间输出（可能多0）
    cout<<endl;

}

int main(){
    test01();
}
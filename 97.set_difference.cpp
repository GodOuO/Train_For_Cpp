#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
//常用的集合算法 set_difference

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

    vTarget.resize(max(v.size(),v2.size())); //最特殊 两个容器大-小 空间开辟Max_Size

    vector<int>::iterator itEnd = set_difference(v.begin(),v.end(),v2.begin(),v2.end(),vTarget.begin());

    cout<<endl<<"V1 difference V2 :"<<endl;
    for_each(vTarget.begin(),itEnd,printIntVector());   //使用 itEnd！否则将全部空间输出（可能多0）
    cout<<endl;

    itEnd = set_difference(v2.begin(),v2.end(),v.begin(),v.end(),vTarget.begin());

    cout<<endl<<"V2 difference V1 :"<<endl;
    for_each(vTarget.begin(),itEnd,printIntVector());   //使用 itEnd！否则将全部空间输出（可能多0）
    cout<<endl;

}

int main(){
    test01();
}
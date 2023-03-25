#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
//常用集合算法 set_intersection

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

    for (int i = 0; i < 10; i++){
        v.push_back(i+1);
        v2.push_back(i);
    }

    for_each(v.begin(),v.end(),printIntVector());
    cout<<endl;
    for_each(v2.begin(),v2.end(),printIntVector());
    cout<<endl;

    vTarget.resize(min(v.size(),v2.size()));    //algorithm库中 比较两个数 输出最小值

    //获取交集
    vector<int>::iterator itEnd = set_intersection(v.begin(),v.end(),v2.begin(),v2.end(),vTarget.begin());
    cout<<"Intersection both :"<<endl;
    
    for_each(vTarget.begin(),itEnd,printIntVector());   //使用 itEnd！否则将全部空间输出（可能多0）
    cout<<endl;

}

int main(){
    test01();
}
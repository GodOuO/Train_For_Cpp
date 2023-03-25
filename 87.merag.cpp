#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
class printIntVector
{
public:
    void operator()(int a){
        cout<<a<<" ; ";
    }
};


//常用排序算法 merge
void test01(){
    vector<int> v1;
    vector<int> v2;
    vector<int> vTarget;

    for (int i = 0; i < 10; i++)
        v1.push_back(i+1);
    for (int i = 10; i < 15; i++)
        v2.push_back(i+1);
    
    vTarget.resize(v1.size()+v2.size());

    for_each(v1.begin(),v1.end(),printIntVector());
    cout<<endl;

    for_each(v2.begin(),v2.end(),printIntVector());
    cout<<endl;
    
    merge(v1.begin(),v1.end(),v2.begin(),v2.end(),vTarget.begin());
    
    for_each(vTarget.begin(),vTarget.end(),printIntVector());
    cout<<endl;




    
    




}

int main(){
    test01();
}
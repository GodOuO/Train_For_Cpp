#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
class mPrint
{
public:
    void operator()(int a){
        cout<<a<<" ; ";
    }
};

class mTransform
{
public:
    int operator()(int a){
        return a;
    }
};


//transform 转运 搬运容器

void test01(){
    vector<int> v;
    for (int i = 0; i < 10; i++)
        v.push_back(i+1);
    for (int i = 5; i > 0; i--)
        v.push_back(i);
    
    for_each(v.begin(),v.end(),mPrint());
    cout<<endl;

    vector<int> vTarget;
    vTarget.resize(v.size());

    transform(v.begin(),v.end(),vTarget.begin(),mTransform());
    for_each(vTarget.begin(),vTarget.end(),mPrint());
    cout<<endl;










    
}


int main(){
    test01();
}
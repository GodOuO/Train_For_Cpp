#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
//常见拷贝和替换算法 swap

class printIntVector
{
public:
    void operator()(int a){
        cout<<a<<" ; ";
    }
};

void test01(){
    vector<int> v1;
    vector<int> v2;

    for (int i = 0; i < 5; i++)
        v1.push_back(i+1);
    for (int i = 0; i < 10; i++)
        v2.push_back(i);
    
    for_each(v1.begin(),v1.end(),printIntVector());
    cout<<endl;
    for_each(v2.begin(),v2.end(),printIntVector());
    cout<<endl;

    swap(v1,v2);

    cout<<"SWAP !!!"<<endl;

    for_each(v1.begin(),v1.end(),printIntVector());
    cout<<endl;
    for_each(v2.begin(),v2.end(),printIntVector());
    cout<<endl;

}

int main(){
    test01();
}
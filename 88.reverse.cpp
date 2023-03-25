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

//常用排序算法 reverse
void test01(){
    vector<int> v;
    for (int i = 0; i < 5; i++)
        v.push_back(i+1);
    for_each(v.begin(),v.end(),printIntVector());
    cout<<endl;

    cout<<"Reverse!"<<endl;
    reverse(v.begin(),v.end());
    for_each(v.begin(),v.end(),printIntVector());
    cout<<endl;

}

int main(){
    test01();
}
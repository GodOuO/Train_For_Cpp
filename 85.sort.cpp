#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
class printIntVertor
{
public:
    void operator()(int a){
        cout<<a<<" ;";
    }
};


//常用排序算法 sort

void test01(){
    vector<int> v;
    for (int i = 0; i < 5; i++)
        v.push_back(i);
    for (int i = 10; i > 5; i--)
        v.push_back(i+1);
    
    sort(v.begin(),v.end());    //默认升序
    for_each(v.begin(),v.end(),printIntVertor());
    cout<<endl;

    sort(v.begin(),v.end(),greater<int>());     //降序排序
    for_each(v.begin(),v.end(),printIntVertor());
    cout<<endl;
    
}

int main(){
    test01();
}
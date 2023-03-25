#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
//常用查找算法 adjacent_find
class printIntVector{
public:
    void operator()(int a){
        cout<<a<<" ; ";
    }
};

void test01(){
    vector<int> v;
    for (int i = 0; i < 5; i++)
        v.push_back(i+1);
    //v.push_back(5);

    for_each(v.begin(),v.end(),printIntVector());
    cout<<endl;

    vector<int>::iterator it = adjacent_find(v.begin(),v.end());
    if (it == v.end())
        cout<<"No Repete elem !"<<endl;
    else
        cout<<"Repete ! elem : "<<*it<<endl;
    
    

    
}



int main(){
    test01();
}
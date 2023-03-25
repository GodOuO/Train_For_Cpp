#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
//查找有序序列 二分查找法 binary_search

void test01(){
    vector<int> v;
    for (int i = 0; i < 10; i++)
        v.push_back(i+1);

    //查找元素是否有9
    //容器必须有序！
    bool ret = binary_search(v.begin(),v.end(),9);
    if(1 == ret)
        cout<<"Find elem 9"<<endl;
    else    
        cout<<"Elem isn't Exist !"<<endl;
    
}


int main(){
    test01();
}
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<ctime>
using namespace std;

class printIntVector
{
public:
    void operator()(int a){
        cout<<a<<" ; ";
    }
};



//常用排序算法 random_shuffle 洗牌算法


void test01(){
    vector<int> v;
    for (int i = 0; i < 10; i++)
        v.push_back(i+1);
    for_each(v.begin(),v.end(),printIntVector());
    cout<<endl;


    //利用洗牌算法 打乱顺序
    //random_shuffle(v.begin(),v.end());
    for_each(v.begin(),v.end(),printIntVector());

    
}

int main(){
    srand((unsigned int)time(NULL));    //随机数 种子！
    test01();
}
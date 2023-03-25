#include<iostream>
#include<string>
#include<vector>
using namespace std;
//容器嵌套容器
void test01(){
    vector<vector<int> > v;
    //创建小容器
    vector<int> v1;
    vector<int> v2;

    //小容器 赋值
    for (int i = 0; i < 4; i++)
    {
        v1.push_back(i+1);
        v2.push_back(i+2);
    }

    //小容器 插入大容器
    v.push_back(v1);
    v.push_back(v2);

    //通过大容器 便利
    for (vector<vector <int> >::iterator it = v.begin(); it != v.end(); it++){
        // (*it) == vector<int>
        for (vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); vit++)
            cout<<*vit<<" ; ";
        cout<<endl;   
    }

    
}
int main(){
    test01();
}
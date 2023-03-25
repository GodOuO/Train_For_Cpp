#include<iostream>
#include<string>
#include<vector>
using namespace std;

void printVector(vector<int> &v){       //使用 &引用 的方式
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
        cout<<*it<<";";
    cout<<endl;
}

//vector 构造函数
void test01(){
    vector<int> v1;     //默认 无参构造

    for (int i = 0; i < 10; i++)
        v1.push_back(i+1);
    printVector(v1);

    vector<int> v2(v1.begin(),v1.end());        //利用区间方式 进行构造
    printVector(v2);

    vector<int> v3(10,100);     // n个 elem 方式构造
    printVector(v3);

    vector<int> v4(v3);         //拷贝构造
    printVector(v4);

}


//vector 赋值
void test02(){
    vector<int> v1;
    for (int i = 0; i < 10; i++)
        v1.push_back(i+1);
    printVector(v1);

    vector<int> v2;
    v2 = v1;        //赋值 operator=
    printVector(v2);

    vector<int> v3;
    v3.assign(v1.begin(),v1.end());     //assign
    printVector(v3);

    vector<int> v4;         //n 个 elem元素
    v4.assign(10,100);
    printVector(v4);
    
}

//vector 容量大小
void test03(){
    vector<int> v1;
    for (int i = 0; i < 10; i++)
        v1.push_back(i+1);
    printVector(v1);

    if (v1.empty())
    {
        cout<<"Vector is empty!"<<endl;
    }
    else
    {
        cout<<"Vector's Data is Exist!"<<endl;
        cout<<"V1's Capacity : "<<v1.capacity()<<endl;  //动态扩展
        cout<<"V1's Size : "<<v1.size()<<endl;          //当前大小
    }

    v1.resize(18);
    printVector(v1);
    v1.resize(15,100);      //重载 指定默认填充值
    printVector(v1);

    v1.resize(5);
    printVector(v1);
}

//vector 插入删除
void test04(){
    vector<int> v1;
    for (int i = 0; i < 10; i++)
        v1.push_back(i+1);
    printVector(v1);


    v1.pop_back();
    printVector(v1);        //尾删法

    v1.insert(v1.begin(),100);
    printVector(v1);

    v1.insert(v1.begin(),2,101);
    printVector(v1);


    v1.erase(v1.begin());
    printVector(v1);

    v1.erase(v1.begin(),v1.end());
    printVector(v1);


    for (int i = 0; i < 10; i++)
        v1.push_back(i+1);
    v1.clear();
    printVector(v1);
}

//vector 数据 存取
void test05(){
    vector<int> v1;
    for (int i = 0; i < 10; i++)
        v1.push_back(i+1);
    

    for (int i = 0; i < v1.size(); i++)
        cout<<v1[i]<<" ; ";
    cout<<endl;


    for (int i = 0; i < v1.size(); i++)
        cout<<v1.at(i)<<" ; ";
    cout<<endl;

    cout<<"First Elem : "<<v1.front()<<endl;

}

//vector 互换容器
void test06(){
    vector<int> v1;
    for (int i = 0; i < 10; i++)
        v1.push_back(i+1);
    printVector(v1);

    vector<int> v2;
    for (int i = 10; i >0 ; i--)
        v2.push_back(i);
    printVector(v2);

    cout<<"Swap Now:"<<endl;
    v1.swap(v2);
    printVector(v1);
    printVector(v2);

}

//实际用途 swap -- 收缩内存空间
void test07(){
    vector<int> v;
    for (int i = 0; i < 100000; i++)
        v.push_back(i+1);

    cout<<"V's Capacity : "<<v.capacity()<<endl;
    cout<<"V's Size     : "<<v.size()<<endl;

    v.resize(3);
    cout<<"V_reSize's Capacity : "<<v.capacity()<<endl;
    cout<<"V_reSize's Size     : "<<v.size()<<endl;

    vector<int>(v).swap(v);       //收缩空间
    cout<<"V_resetSize's Capacity : "<<v.capacity()<<endl;
    cout<<"V_resetSize's Size     : "<<v.size()<<endl;
    
}

//vector 预留空间  reserve()
void test08(){
    vector<int> v;
    int num = 0;
    int *p = NULL;

    for (int i = 0; i < 100000; i++){
        v.push_back(i+1);
        if (p != &v[0]){
            p = &v[0];
            num++;
        }
    }
    cout<<"Explore Times are : "<<num<<endl;

    vector<int> v2;
    num = 0;
    v2.reserve(10000);
    for (int i = 0; i < 100000; i++){
        v2.push_back(i+1);
        if (p != &v[0]){
            p = &v[0];
            num++;
        }
    }
    cout<<"Reset Explore Times are : "<<num<<endl;

}

int main(){
    //test01();
    //test02();
    //test03();
    //test04();
    //test05();
    //test06();
    //test07();
    test08();
}
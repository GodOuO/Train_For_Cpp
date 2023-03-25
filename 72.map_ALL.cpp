#include<iostream>
#include<string>
#include<map>
using namespace std;

class mCompare      //仿函数 降序
{
public:
    bool operator()(int a,int b) const{
        return a>b;
    }
};

void printMap(const map<int,int> &m){
    for (map<int,int>::const_iterator it = m.begin(); it != m.end(); it++)
        cout<<"Key : "<<it->first<<"\tValue : "<<it->second<<endl;
    cout<<endl;    
}

void printreMap(const map<int,int,mCompare> &m){
    for (map<int,int,mCompare>::const_iterator it = m.begin(); it != m.end(); it++)
        cout<<"Key : "<<it->first<<"\tValue : "<<it->second<<endl;
    cout<<endl;     
}

//map 构造 赋值
void test01(){
    map<int,int> m;

    m.insert(pair<int,int>(1,10));  //pair 匿名对组，成为m中的第一对元素，1为索引，10为实值
    m.insert(pair<int,int>(2,10));
    m.insert(pair<int,int>(6,100));
    m.insert(pair<int,int>(3,999));

    printMap(m);

    map<int,int> m2(m);
    printMap(m2);

    map<int,int> m3;
    m3 = m2;
    printMap(m3);



}

//map 大小 交换
void test02(){
    map<int,int> m;
    m.insert(pair<int,int>(1,10)); 
    m.insert(pair<int,int>(2,10));
    m.insert(pair<int,int>(6,100));
    m.insert(pair<int,int>(3,999));

    if (m.empty())
    {
        cout<<"Map is Empty!"<<endl;
    }
    else{
        cout<<"Map is Exist!!!"<<endl;
        cout<<"Map's Size : "<<m.size()<<endl;
        printMap(m);
    }

    map<int,int> m2;
    m2.insert(pair<int,int>(1,10)); 
    m2.insert(pair<int,int>(58,10));
    m2.insert(pair<int,int>(304,100));
    m2.insert(pair<int,int>(51,999));
    printMap(m2);

    m.swap(m2);
    cout<<"Exchange:"<<endl;
    printMap(m);
    printMap(m2);

}

//map 插入和删除
void test03(){
    map<int,int> m1;
    m1.insert(pair<int,int>(1,10));

    m1.insert(make_pair(2,20));     //make_pair() 制造对组，无需定义模版数据类型

    m1.insert(map<int,int>::value_type(3,300)); //value_type 值类型

    m1[4] = 40;     //不建议插入，但是可以利用[key] 访问value

    cout<<m1[5]<<endl;      //未定义 自动创建并 初始化 value为0

    printMap(m1);

    cout<<"Map's Key 4th 's Value : "<<m1[4]<<endl;

    map<int,int>::iterator it = m1.begin();
    ++it;
    (++it)++;
    ++it;

    m1.erase(it);
    printMap(m1);

    m1.erase(4);        //按照 key 删除
    printMap(m1);

}

//map 容器中 查找和统计
void test04(){
    map<int,int> m;
    m.insert(make_pair(2,304));
    m.insert(make_pair(7,51));
    m.insert(make_pair(4,126));
    m.insert(make_pair(3,51));
    m.insert(make_pair(3,51));

    map<int,int>::iterator pos = m.find(4);
    if (pos != m.end())
    {
        cout<<"Get Elem , Key : "<<pos->first<<"\tValue : "<<pos->second<<endl;
    }
    else
    {
        cout<<"Elem isn't Exist!"<<endl;
    }
    
    printMap(m);
    int count = m.count(3);
    cout<<"Key 3's time is : "<<count<<endl;

}

//map 排序
void test05(){
    map<int,int> m;
    m.insert(make_pair(2,304));
    m.insert(make_pair(7,51));
    m.insert(make_pair(4,126));
    m.insert(make_pair(3,58));
    m.insert(make_pair(1,51));

    printMap(m);

    map<int,int,mCompare> m2;
    m2.insert(make_pair(2,304));
    m2.insert(make_pair(7,51));
    m2.insert(make_pair(4,126));
    m2.insert(make_pair(3,58));
    m2.insert(make_pair(1,51));

    printreMap(m2);

}

int main(){
    //test01();
    //test02();
    //test03();
    //test04();
    test05();
}
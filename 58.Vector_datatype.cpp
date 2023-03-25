#include<iostream>
#include<string>
#include<vector>
#include<algorithm> //标准算法头文件    for_each()库函数
using namespace std;
//vector 容器存放内置数据类型

void mPrint(int val){
    cout<<val<<" ; ";
}

void test01(){
    vector<int> v;      //创建vector容器， 可看成数组

    //向容器中 插入数据
    v.push_back(10);        //尾插数据
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);

    //通过迭代器 访问数据
    
    //1.while 循环访问
    vector<int>::iterator itBegin = v.begin(); 
                                    //begin()   起始迭代器，指向容器中第一个元素loc
    vector<int>::iterator itEnd = v.end();
                                  //end()   结束迭代器，指向容器中末尾元素下一个loc
    while (itBegin != itEnd)
        cout<< *itBegin++ <<" ; ";
    
    cout<<endl;

    //2.for 整合循环访问（常用）
    for (vector<int>::iterator i = v.begin(); i != v.end(); i++){
        //初始状态                            退出条件        递增趋势
        cout<<*i<<" ; ";
    }
    cout<<endl;

    //3.利用STL便利算法 进行访问
    for_each(v.begin(),v.end(),mPrint);
            //起始      结束    函数名
                            //利用回调技术，在一开始不调用，遍历期间调用函数
/* 
for_each 声明：
    _Function for_each(_InputIterator __first,
                   _InputIterator __last,
                   _Function __f)
        for (; __first != __last; ++__first)
             __f(*__first);
        return __f;
 */
    

}
int main(){
    test01();
}
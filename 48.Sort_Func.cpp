#include<iostream>
#include<string>
using namespace std;
/* 
    实现通用 对数组排序函数
        1.从大到小 (降序)
        2.选择排序
        3.测试，char[] int[]
 */

template <class T>
void Swap(T &a,T &b){
    T temp = a;
    a = b;
    b = temp;
}

template <class T>
void selectSort(T arr[],int len){
    for (int i = 0; i < len; i++){
        int Max = i;    //认定最大值下标
        for (int j = i+1 ; j < len; j++){
            if (arr[Max] < arr[j]) //认定的最大值 比 便利数据小，说明j下标数据为Max
                Max = j;           //更新Max下标
        }
        if (Max != i){             //交换 Max 和 i 下标的元素 
            Swap(arr[Max],arr[i]);
        }
    }
}

template<class T>
void printArr(T arr[],int len){
    for (int i = 0; i < len; i++)
        cout<<arr[i]<<" ; ";
    cout<<endl;
}
//普通函数
int Add_N(int a,int b){
    return a+b;
}

//函数模版
template <class T>
T Add_abN(T a,T b){
    return a+b;
}

void Print(int a,int b)
{
    cout<<"Normal Print Func()"<<endl;
}

template<class T>
void Print(T a,T b){
    cout<<"Template Print Func()"<<endl;
}

template<class T>
void Print(T a,T b,T c){
    cout<<"Template Reload Print Func()"<<endl;
}



void test01(){
    char charArr[] = "badcfea";
    int len = sizeof(charArr)/sizeof(char);
    selectSort(charArr,len);
    printArr(charArr,len);
}
void test02(){
    int intArr[] = {1,4,4,4,4,3,2,2,2,3,4,5,7,65,412,0};
    int len = sizeof(intArr)/sizeof(int);
    selectSort(intArr,len);
    printArr(intArr,len);
}
void test03(){  
    int a = 10;
    int b = 20;
    char c = 'c';
    cout<<Add_N(a,b)<<endl;
    cout<<Add_abN(a,b)<<endl;
    cout<<Add_N(a,c)<<endl;     //不做 &的深拷贝, 将a强ascii转97
    //cout<<Add_abN(a,c);       //自动类型推导，无法统一类型
    cout<<Add_abN<int>(a,c)<<endl;  //指定类型推导，隐式类型推导
}


void test04(){      //调用规则测试
    int a = 10;
    int b = 20;
    char c1 = 'a';
    char c2 = 'b';
    Print(a,b);     //都可以调用，优先调用普通函数
                    //如果普通函数没有实现，直接报错不可调用
    Print<>(a,b);                //  需要通过空模版参数列表， 只强制调用函数模版
    Print(a,b,100);
    Print(c1,c2);   //优先调用 适用的函数模版

}

int main(){
    //test01();
    //test02();
    //test03();
    test04();
}
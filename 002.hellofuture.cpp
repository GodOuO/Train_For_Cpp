#include<iostream>
#include<string>
#include<ctime>
using namespace std;
int g_a = 10;
int g_b = 10;
const int c_g_a = 10;
/* int* func(int b ){
    b = 10;
    return &b;
} */
/* int& funerr(){
    int a = 10; //局部变量存入栈区
    return a;
} */
int& funerr_cor(){
    static int a = 10;  //全局区存放，系统结束后释放内存
    return a;
}

int* fucNew(){
    int *p = new int(10);
    return p;
}

int* func(){
    int *p = new int (10);
    delete p;
    return p;
}

void test01(){
    int *p = func();
    for(int i =0;i<5;i++)
        cout<<"Func() "<<*p<<endl;
}
void test02(){
    int *arr = new int[10];
    for(int i = 0;i<10;i++){
        arr[i] = rand()%100;
        cout<<arr[i]<<";";
        delete []arr;
    }
}

void showValue(const int &val){
    // val = 1000;  //无法修改
    cout<<"Value : "<<val<<endl;
}

int funadd(const int a,int b = 10,int c = 20){
    return a+b+c;
}

// int funerr(int a = 10,int b = 10);   //声明已定义参数！
// int funerr(int a = 10,int b = 10){   //重定义了默认参数！二义性！
//     return a+b;
// }

void funcin(int a,int){ //占位参数
    cout<<"FuncIn(int,int)"<<endl;
}
void funcin(){  //函数重载
    cout<<"FuncIn()"<<endl;
}

void test03(int &a){        //int &a = 10;      不合法
    cout<<"Test03 Using"<<endl;
}
void test03(const int &a){  //const in &a = 19; 合法
    cout<<"Test03 const Using"<<endl;
}
/* void test04(int a){
    cout<<"Test 04"<<endl;
}
void test04(int a,int b = 10){
    cout<<"Test 04"<<endl;
} */

class Person{
public:
    string Name;
protected:
    string Car;
private:
    string password;
public:
    void func(){
        Name = "GodOuO";
        Car = "Tesla";
        password = "Sean2021";
    }
};

class Person_real{
public:
void setName(string name){
    p_name = name;
}
void setAge(int age){
    if(age>0 && age<150)
        p_age = age;
    else{
        cout<<"Wrong Age!"<<endl;
        p_age = 0;
        return;
    }
}
string getName(){
    return p_name;
}
int getAge(){
    return p_age;
}
void setLover(string lover){
    p_lover = lover;
}

private:
    string p_name;    //可读可写
    int p_age;        //只读
    string p_lover;   //只写
};

class test01_01
{
public:
    test01_01(){
        cout<<"Person_默认构造函数"<<endl;
    }
    test01_01(int a){               //有参构造
        age = a;
        cout<<"Person_有参构造函数"<<endl;
    }
    ~test01_01(){
        cout<<"Person_析构函数"<<endl;
    }
    test01_01(const test01_01 &t){  //拷贝构造
        age = t.age;    //将传入的人所有属性，传入到t身上
        cout<<"Person_拷贝构造函数"<<endl;
    } 
    int age;
};
void test01_01_1(){
    test01_01 t1;           //括号法，默认构造函数调用，推荐使用！！！
    test01_01 t2(10);       //有参构造函数
    test01_01 t3(t2);       //拷贝构造函数
    //cout<<"T2's Age: "<<t2.age<<endl;
    //cout<<"T3's Age: "<<t3.age<<endl;

    test01_01 t4 = test01_01(10);   //有参构造函数
    test01_01 t5 = test01_01(t2);   //拷贝构造
    test01_01(10);      //匿名对象
    //test01_01(t2);    //等价于 tets01_01 t2,属于重定义
    test01_01 t6 = 10;  
    test01_01 t7 = t2;  //拷贝构造
}

void test01_02(){
    test01_01 t1(20);
    test01_01 t2(t1);
    cout<<t2.age<<endl;
}

void doWork(test01_01 p){
}
test01_01 doWork02(){
    test01_01 p1;
    return p1;
}
void test01_03(){
    test01_01 p;        //默认构造
    doWork(p);      //实参传型参，调用拷贝构造函数，上方数据不影响本行数据
}
void test01_04(){
    test01_01 p3 = doWork02();
}

void test01_05(){
    test01_01 t1;
    t1.age = 18;
    test01_01 t2(t1);       //拷贝构造
    cout<<"P2 age:"<<t2.age<<endl;
}

int main(){

    srand((unsigned int)time(NULL));
    int a = 15;         // c_const ; g_global ; l_local 
    int b = 0;
    static int s_a = 10;
    const int c_l_a = 10;
    const int c_l_b = 10;

    test01_05();

    //test01_04();
    //test01_03();
    //test01_02();
    //test01_01_1();

    //test04();
    //test01_01 t1;

   /*  Person_real p1;
    p1.setName("GodOuO");
    p1.setLover("Wendy");
    cout<<"Input Age:"<<endl;
    int age;
    cin>>age;
    p1.setAge(age);
    cout<<"Name:\t"<<p1.getName()<<endl;
    cout<<"Age:\t"<<p1.getAge()<<endl; */

    // Person p1;
    // p1.Name = "Wendy";  //类外只能修改public

    //test04(10,10);

    // test03(a);
    // test03(10);

    // funcin(10,10);
    // funcin();
    //cout<<funerr(a,b)<<endl;

    // cout<<funadd(a)<<endl;
    // cout<<funadd(10,22)<<endl;

    // showValue(a);
    // cout<<"a : "<<a<<endl;

/*     int &ref = funerr();
    cout<<"ref: "<<ref<<endl; */
    
/*     int &ref = funerr_cor();    //引用定义后不可修改
    cout<<"ref_cor"<<ref<<endl;
    funerr_cor() = 1000;        //调用可作为左值进行复制
    cout<<"ref_cor"<<ref<<endl; */
    

/*     int &c = a;
    c = b;  //赋值操作，b给引用c，c和a是一个地址数据； 故a=0,c=0,b=0; */
    
    //test01();
    //test02();

/*     cout<<"全局变量a\t"<<(long)&g_a<<endl;
    cout<<"全局变量b\t"<<(long)&g_b<<endl;
    cout<<"静态变量a\t"<<(long)&s_a<<endl;
    cout<<"字符串常量a\t"<<(long)&"Hellofuture"<<endl;
    cout<<"const全局常量a\t"<<(long)&c_g_a<<endl;
    cout<<endl;
    cout<<"const局部常量a\t"<<(long)&c_l_a<<endl;
    cout<<"const局部常量b\t"<<(long)&c_l_b<<endl;
    cout<<"局部变量a\t"<<(long)&a<<endl;
    cout<<"局部变量b\t"<<(long)&b<<endl; */

/*     int *p = func(a);
    cout<<*p<<endl<<*p<<endl; */
    /* int *p = fucNew();
    cout<<*p<<endl<<*p<<endl; */

}
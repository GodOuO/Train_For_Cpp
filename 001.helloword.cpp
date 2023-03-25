#include<iostream>
#include<string>
using namespace std;
void swap(int a,int b){
    int temp = a;
    a=b;
    b=temp; 
    cout<<"After:\t"<<a<<";"<<b<<endl;
    return;//返回值不需要
}
int Max(int a,int b){
    return (a>=b?a:b);
}
struct Student{
    string name;
    int age;
    int score;
}s3;
struct Teacher
{
    int id;
    string name;
    int age;
    struct Student stu;
};
void PrintS_01(struct Student s){//值传递
    cout<<"S_01 Name:"<<s.name<<"\tAge:"<<s.age<<"\tScore:"<<s.score<<endl;
}
void PrintS_02(struct Student *p){//地址传递
    cout<<"S_02 Name:"<<p->name<<"\tAge:"<<p->age<<"\tScore:"<<p->score<<endl;
}
void PrintConstS_01(const struct Student *s){//Const 禁止修改
    cout<<"ConstS_01 Name:"<<s->name<<"\tAge:"<<s->age<<"\tScore:"<<s->score<<endl;
}
int main(){
    

    /* Student s1 = {"Zhang3",23,51};
    PrintConstS_01(&s1); */

    /* s3.age=23;
    s3.name="Li4";
    s3.score=51;
    PrintS_01(s3);
    PrintS_02(&s3); */

    /*Teacher t1 = {181203616,"GodOuO",23,s3};
    Teacher *l = &t1;
    cout<<l->id<<" "<<l->age<<" "<<l->name<<" "<<endl;
    cout<<l->stu.age<<" "<<l->stu.name<<" "<<l->stu.score<<endl; */

    /*Student *q = &s3;
    cout<<q->age<<"\t"<<q->name<<"\t"<<q->score<<endl; */
    /* struct Student stuArr[3] = {
        {"Zhang3",18,100},{"Li4",28,99},{"Wang5",38,66}
    };
    stuArr[2].age=80;
    for(int i= 0;i<3;i++){
        cout<<stuArr[i].name<<"\t"<<stuArr[i].age<<"\t"<<stuArr[i].score<<endl;
    } */

    /* struct Student s1;
    s1.name = "Zhang3";
    s1.age = 23;
    s1.score = 304;
    s3.name="Wang5";
    s3.age=23;
    s3.score=126;
    struct Student s2 = {"Li4",23,51};
    cout<<s1.age<<"\t"<<s1.name<<"\t"<<s1.score<<endl;
    cout<<s2.age<<"\t"<<s2.name<<"\t"<<s2.score<<endl;
    cout<<s3.age<<"\t"<<s3.name<<"\t"<<s3.score<<endl; */
    
    short num = 10;
    //cout<<"bool占用空间:"<<sizeof(bool)<<endl;
    float f1 = 3.14f;
    float f2 = 3e-2;
    char ch = 'a';
    //cout<<(int)ch<<endl;
    //cout<<"f2:"<<f2<<endl;
    //cout<<'\a'<<endl;
    //cout<<"aa\thelloworld"<<endl;
    //cout<<"aaaaa\thelloworld"<<endl;
    //cout<<"aaa\thelloworld"<<endl;
    char str[] = "hello world";
    string str2 = "hello world";
    //cout<<str<<endl;
    //cout<<str2<<endl;
    int a = 0;
    int b = 10;
    /* cout<<"please input a:"<<endl;
    cin>>a;
    cout<<"now a:"<<a<<endl; */
    /* cout<<"exchange str2"<<endl;
    cin>>str2;
    cout<<"Now str2:"<<str2<<endl; */ 
    
    /* cout<<"a:\t"<<a<<endl;
    cout<<"a++:\t"<<a++<<endl;
    cout<<"++b\t"<<++b<<endl; */

    /*     cout<<(a!=b)<<endl; */
    
/*     cout<<"please input your score:"<<endl;
    cin>>a;
    
    if(a>=600){
        cout<<"congratulation,your score is "<<a<<endl;
        cout<<"ON top 1 University and ";
        if(a>=700)
            cout<<"You are in BeiJing University"<<endl;
        else if(a>650&&a<700)
            cout<<"You are in TingHua University"<<endl;
        else
            cout<<"You are in People's University"<<endl;
    }
    else if(a>=0&&a<600){
        cout<<"congratulation,your score is "<<a<<endl;
        cout<<"OUT OF top 1 University"<<endl;
        
    }
    else{
        cout<<"score is ERROR!"<<endl;
    } */
    
/*     do
    {
        cout<<a++<<endl;
    } while (a<0); */
/*     for(;a<10;a++){
        cout<<a<<endl;
    } */
    
    /* for(;a<=100;a++){
        if(0==a%2)
            continue;
        cout<<a<<";";
    } */
/*     int arr[5]={1,2,3,4,5};
    cout<<sizeof(arr)<<endl;
    cout<<"head is \t:"<<arr<<endl;
    cout<<"arr[0]'s loc\t:"<<&arr[0]<<endl; */
    /* int arr[2][3]={{1,2,3},{4,5,6}};
    //cout<<sizeof(arr);
    cout<<sizeof(arr[0]); */
    /* cout<<"Before:\t"<<a<<";"<<b<<endl;
    swap(a,b);
    cout<<a<<" "<<b<<endl; */
    //cout<<Max(a,b)<<endl;
    
     int *p = &a;
    /* cout<<"A's loc :"<<p<<endl;
    cout<<"A :"<<*p<<";"<<a<<endl; */ 
    // cout<<sizeof(int *);
    int arr[10]={0,1,2,3,4,5,6,7,8,9};
    
    /* int *q =arr;
    for(int i=0;i<10;i++)
        cout<<"The top\t"<<i+1<<" Num :\t"<<*(q++)<<endl;
 */
    

}

#include<iostream>
#include<string>
#include<stack>
using namespace std;
//stack 容器

void test01(){
    stack<int> s;
    for (int i = 0; i < 5; i++)
        s.push(i+1);
    cout<<"Stack 's Size : "<<s.size()<<endl;

    while (!s.empty()){
        cout<<"Stack Top elem : "<<s.top()<<endl;
        s.pop();
    }
    cout<<"Pop_Stack 's Size : "<<s.size()<<endl;
    
}
int main(){
    test01();
}
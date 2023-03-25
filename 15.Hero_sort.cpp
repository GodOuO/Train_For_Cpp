#include<iostream>
#include<string>
using namespace std;
/* 英雄结构体：姓名，年龄，性别
    数组形式，5位英雄
    冒泡排序年龄升序，打印结果
 */
struct Hero{
    string name;
    int age;
    string sex;
};
void printInfo(struct Hero heroArr[],int len){
    for(int i =0;i<len;i++){
        cout<<"Name: "<<heroArr[i].name
            <<"\tAge: "<<heroArr[i].age
            <<"\tSex: "<<heroArr[i].sex<<endl;
    }
}
void bubbleSort(struct Hero heroArr[],int len){
    for(int i = 0;i<len-1;i++){
        for(int j = 0;j<len-1-i;j++){
            if(heroArr[j].age>heroArr[j+1].age){
                Hero temp = heroArr[j];
                heroArr[j]=heroArr[j+1];
                heroArr[j+1]=temp;
            }
        }
    }
}
int main(){
    Hero heroArr[5]={{"LuB",23,"Male"},
                     {"GuanY",22,"Male"},
                     {"ZhangF",20,"Male"},
                     {"ZhaoY",21,"Male"},
                     {"DiaoC",19,"Female"}};
    
    printInfo(heroArr,sizeof(heroArr)/sizeof(heroArr[0])); 
}
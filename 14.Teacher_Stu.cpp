#include<iostream>
#include<string>
#include<ctime>
using namespace std;
/*  五个学生，三个老师 
    老师结构体：姓名，数组（5学生）
    学生结构体：姓名，分数
    数组存放三个老师
    函数给老师带的学生赋值
    打印老师和学生数据
*/
struct Student{
    string sName;
    int score;
};
struct Teacher{
    string tName;
    struct Student sArr[5];
};
void allocateSpace(struct Teacher tArr[],int len){
    int sNum = 5;
    string nameSeed [5]= {"Zhang3","Li4","Wang5","Songmq","GodOuO"};
    for(int i = 0;i<len;i++){
        tArr[i].tName="Teacher_";
        tArr[i].tName+=nameSeed[i];
        for(int j =0;j<sNum;j++){
            tArr[i].sArr[j].sName="Student_";
            tArr[i].sArr[j].sName+=nameSeed[j];
            tArr[i].sArr[j].score = (rand()%100);   //0-99
        }
    }
}
void printInfo(struct Teacher tArr[],int len){
    int sNum = 5;
    for(int i =0;i<len;i++){
        cout<<endl<<"Teacher's Name: "<<tArr[i].tName<<"\t"<<endl;
        for(int j = 0;j<sNum;j++){
            cout<<"Student's Name: "<<tArr[i].sArr[j].sName<<"\t"
                <<"Score: "<<tArr[i].sArr[j].score<<endl;
        }
    }
}
int main(){
    srand((unsigned int)time(NULL));        //每次随机生成，随机数种子
    Teacher tArr[3];
    allocateSpace(tArr,sizeof(tArr)/sizeof(tArr[0]));
    printInfo(tArr,3);
}
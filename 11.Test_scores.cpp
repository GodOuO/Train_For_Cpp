#include<iostream>
using namespace std;
int main(){
    int scores[3][5];
    string name[3] = {"Zhang3","Li4","Wang5"};
    for(int m = 0;m<3;m++){
        scores[m][4]=0;                         //初始化成绩总和存储空间！
        for(int n =0;n<4;n++){
            cout<<"Please Input "<<name[m]<<" Score"<<n+1<<":"<<endl;
            cin>>scores[m][n];
        } 
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            scores[i][4]+=scores[i][j];
        }
    }
    for(int i=0;i<3;i++){
        cout<<name[i]<<"\t's Score :\t";
        for(int j=0;j<5;j++){
            cout<<scores[i][j]<<"\t";
        }
        cout<<endl;
    }
    
}
#include<iostream>
using namespace std;
int main(){
    int val=-1;
    cout<<"Please input the Start Num(1-100):"<<endl;
    cin>>val;
    do
    {
        if(val<1||val>100){
            cout<<"Wrong Num! Game Over!"<<endl;
            break;
        }
        else if(val%10==7||(val/10)==7||(val%7)==0){
            cout<<endl<<"Knock Desk!!!";
        }
        else
            cout<<val<<";";
            val++;
    } while (val<=100);
    
}
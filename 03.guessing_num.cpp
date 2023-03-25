#include<iostream>
#include<ctime>
using namespace std;
int main(){
    srand((unsigned)time(NULL));
    int num = rand()%100+1;
    int ans =304;
    int low =1;
    int high=100;
while(1){
    int val=0;
    cout<<"Please input your guessing Num("<<low<<"-"<<high<<"):"<<endl;
    cin>>val;
    (val<=0||val>100||val>high||val<low)?(ans=3):((val>num)? ans=2 : ans=(val==num));
    if(2==ans){
        cout<<"Your Num "<<val<<" is Higher!"<<endl;
        if(high>val)
            high = val;
    }
    else if(0==ans){
        cout<<"Your Num "<<val<<" is Lower!"<<endl;
        if(low<val)
            low = val;
    }
    else if(1==ans){
        cout<<"Correct!"<<endl;
        break;
    }
    else if(3==ans){
        cout<<"Wring Num\t";
    }
    else
        cout<<"Sys is ERROR!"<<endl;
    }
    system("pause");
    return 0;
    
}
#include<iostream>
using namespace std;
int main(){
    int arr[5];
    int max = 0;
    int pig = 0;
    string name = "ABCDE";
    for(int i=0;i<5;){
        cout<<"Please input Pig"<<name[i]<<"'s weights:"<<endl;
        cin>>arr[i];
        if(arr[i]>0){
            cout<<"Pig"<<name[i]<<"'s weight is:"<<arr[i]<<endl;
            if(arr[i]>max){
                max=arr[i];
                pig = i;
            }
            i++;
            }
            else
                cout<<"Wrong Weight! Input Again Pig"<<name[i]<<"'s weight!"<<endl;
    }
    for(int j =0;j<5;j++){
        cout<<"Pig"<<name[j]<<"\t"<<arr[j]<<";";
    }
    cout<<endl<<"The Heaviset pig is:"<<"Pig"<<name[pig]<<",weight is:"<<arr[pig]<<endl;


}
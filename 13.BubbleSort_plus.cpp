#include<iostream>
#include"12.swap.h"
using namespace std;
void BubbleSort(int * arr,int len){
    for(int i =0;i<len-1;i++){
        for(int j =0;j<len-1-i;j++){
            if(arr[j]>arr[j+1])
                swap_02(&arr[j],&arr[j+1]);
        }
    }
    cout<<"Now: "<<endl;
    PrintArr(arr,len);
}
int main(){
    cout<<"Please input 10 num"<<endl;
    int arr[10];
    int *p = arr;
    int len = sizeof(arr)/sizeof(arr[0]);
    for(int m =0;m<10;m++){
        cout<<"Input Num "<<m+1<<":"<<endl;
        cin>>arr[m];
    }
    cout<<"Formal num :"<<endl;
    PrintArr(arr,len);
    cout<<endl;
    BubbleSort(arr,len);
}

#include<iostream>
using namespace std;
int main(){
    cout<<"Please input 10 num"<<endl;
    int arr[10];
    string name="abcdefghij ";
    for(int m =0;m<10;m++){
        cout<<"Input num "<<name[m]<<":"<<endl;
        cin>>arr[m];
    }
    cout<<"Formal num :"<<endl;
    for(int k =0;k<10;k++){
        cout<<arr[k]<<";";
    }
//核心算法
    for(int i =0;i<10-1;i++){       //总循环次数 = 元素个数 - 1
        for(int j=0;j<10-i-1;j++){  //内循环次数 = 元素个数 - 1 - 当前轮数 
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    cout<<endl<<"BubbleSort num :"<<endl;
    for(int k =0;k<10;k++){
        cout<<arr[k]<<";";
    }
}
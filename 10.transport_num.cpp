#include<iostream>
using namespace std;
int main(){
    cout<<"Please input 5 num"<<endl;
    int arr[5];
    string name="abcde";
    for(int i =0;i<5;i++){
        cout<<"Input num "<<name[i]<<":"<<endl;
        cin>>arr[i];
    }
    cout<<"Formal num :"<<endl;
    for(int k =0;k<5;k++){
        cout<<arr[k]<<";";
    }
    int start = 0;
    int end = sizeof(arr)/sizeof(arr[0])-1;
    while (start<end){
        int temp = arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
        start++;
        end--;
    }
    cout<<endl<<"Transport num :"<<endl;
    for(int j =0;j<5;j++){
        cout<<arr[j]<<";";
    }
    
    

}

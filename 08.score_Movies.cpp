#include<iostream>
#include<string>
using namespace std;
int main(){
    int s=0;
    cout<<"Please input score for the Movies:"<<endl;
    cin>>s;
    cout<<"your score is "<<s<<endl; 
    switch (s)
    {
    case 10:
        cout<<"Best Movie for you"<<endl;
        break;
    case 9:
        cout<<"Great Movie for you"<<endl;
        break;
    case 8:
        cout<<"All Right for you"<<endl;
        break;
    case 7:
        cout<<"Not Bad"<<endl;
        break;
    case 6:
        cout<<"Don't suggest to watch"<<endl;
        break;
    case 5:
        cout<<"Bad Movie"<<endl;
    default:
        cout<<"Never watch"<<endl;
        break;
    }
}
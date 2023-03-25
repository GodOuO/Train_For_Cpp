#include<iostream>
using namespace std;
int main(){
    int a=0,b=0,c=0;
    cout<<"Please input the weight of pigA:"<<endl;
    cin>>a;
    cout<<"Please input the weight of pigB:"<<endl;
    cin>>b;
    cout<<"Please input the weight of pigC:"<<endl;
    cin>>c;
    if(a<=0||b<=0||c<=0)
        cout<<"ERROR!"<<endl;
    else if((a>b&&c>a)||(b>a&&c>b))
        cout<<"pigC is the heaviest!"<<endl;
    else if((a>c&&b>a)||(c>a&&b>c))
        cout<<"pigB is the heaviest!"<<endl;
    else if((b>c&&a>b)||(c>b&&a>c))
        cout<<"pigA is the heaviest!"<<endl;
    else if(a==b&&a>c)
        cout<<"pigA and pigB are the heaviest!"<<endl;
    else if(a==b&&a<c)
            cout<<"pigC is the heaviest!"<<endl;
    
    else if(b==c&&b>a)
        cout<<"pigB and pigC are the heaviest!"<<endl;
    else if(b==c&&b<a)
            cout<<"pigA is the heaviest!"<<endl;
    
        
    else if(a==c&&a>b)
        cout<<"pigA and pigC are the heaviest!"<<endl;
    else if(a==c&&b>a)
            cout<<"pigB is the heaviest!"<<endl;
    
        
    else if(a==b&&b==c&&a==c)
        cout<<"They have the same weight!"<<endl;
}
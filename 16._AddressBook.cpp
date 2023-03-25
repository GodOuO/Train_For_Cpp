#include<iostream>
#include<string>
#include<cstdio>
#include<unistd.h>
#define MAX 1000
using namespace std;
/*  添加联系人：姓名，性别，年龄，联系电话，家庭住址（上限1K）
    显示
    删除（按照姓名
    查找（按照姓名
    修改（按照姓名
    清空全部
    退出sys
 */
struct Person{
    string mName;
    int mSex;   //1 male ; 2 female
    int mAge;
    char mPhone[50];
    char mAddr[100];
};
struct AddressBook{
    Person PersonArr[MAX];
    int mNum;
};
bool phoneNumTrue (char num[50]){
    int i,j,tag=0,len;
    len=strlen(num);
    for(i=0;i<len;i++){
        if(!(num[i]>='0' && num[i]<='9')){
            tag=1;
            break;
        }
    }
    if(11==len && num[0]=='1' && tag==0)
        return 1;
    else 
        return 0;
}

bool ageTrue(int age){
    return ((age>0 && age<151) ? 1 : 0 );
}

void showPerson_2(AddressBook const *abs);

int isExist(AddressBook const *abs,string *name){
    for(int i = 0;i<abs->mNum;i++){
        if(*name == abs->PersonArr[i].mName){
            cout<<"\033c"<<"Find it:"<<endl;
            name = NULL;
            return i;
        }     
    }
    name = NULL;
    cout<<"\033c"<<"People is't Exist!"<<endl;
    return -1;      //不存在
}

void inputData(AddressBook *abs,int *loc){
    cout<<"\033c";
    if(abs->mNum >MAX){
        cout<<"AddressBook FULL!!!"<<endl;
        return;
    }
    else{
        cout<<"Input Name:"<<endl;
        cin>>abs->PersonArr[*loc].mName;
        cout<<"\033c";
        int sex = 0;
        int age = -1;
        while (1){
            cout<<"Input Sex(1 for Male ; 2 for Female):"<<endl;
            cin>>sex;
            if(1==sex || 2==sex){
                abs->PersonArr[*loc].mSex = sex;
                break;
            }
            else
                cout<<"Please input 1 or 2!"<<endl;
        }
        cout<<"\033c";
        while (1){
            cout<<"Input Age:"<<endl;
            cin>>age;
            if(ageTrue(age)){
                abs->PersonArr[*loc].mAge = age;
                break;
            }
            else
                cout<<"Please input Right Age!"<<endl;
        }
        cout<<"\033c";
        while (1){
            cout<<"Input PhoneNum:"<<endl;
            char Num[50];
            cin>>Num;
            if(phoneNumTrue(Num)){
                strcpy(abs->PersonArr[*loc].mPhone, Num);
                break;
            }
            else
                cout<<"Please input Right PhoneNum!"<<endl;
        }
        cout<<"\033c"<<"Input Address:"<<endl;
        cin>>abs->PersonArr[*loc].mAddr;
        cout<<"\033c"<<"Done!"<<endl;
    }
}

void ShowData(AddressBook const *abs,int *loc){
    cout<<abs->PersonArr[*loc].mName<<"\t";
            if(1 == abs->PersonArr[*loc].mSex)
                cout<<"Male\t";
            else
                cout<<"Female\t";
            cout<<abs->PersonArr[*loc].mAge<<"\t"
                <<abs->PersonArr[*loc].mPhone<<"\t"
                <<abs->PersonArr[*loc].mAddr<<endl;
}

void addPerson_1(AddressBook *abs,int *loc){
    inputData(abs,loc);
    ++abs->mNum;
}

void showPerson_2(AddressBook const *abs){
    cout<<"\033c";
    if(0 == abs->mNum)
        cout<<"Data is Empty!"<<endl;
    else{
        cout<<"AddressBook By GodOuO"<<endl
            <<"Name\tSex\tAge\tPhoneNum\tLoc"<<endl;
        for(int i = 0;i<abs->mNum;i++){
            ShowData(abs,&i);
        }
    }
}

void searchPerson_3(AddressBook const *abs,string *name){
    int e = isExist(abs,name);
    if(-1 != e){
        cout<<"Name\tSex\tAge\tPhoneNum\tLoc"<<endl;
        ShowData(abs,&e);
    }
}

void delPerson_4(AddressBook *abs,string *name){
    int loc = isExist(abs,name);
    if(-1!=loc){
        ShowData(abs,&loc);
        for(int i = loc;i<abs->mNum;i++){
            abs->PersonArr[i] = abs->PersonArr[i+1];    //前移数据
        }
        abs->mNum--;
        cout<<"Done!"<<endl;
    }
}

void modifyPerson_5(AddressBook *abs,string *name){
    int loc = isExist(abs,name);
    if(-1!=loc){
        inputData(abs,&loc);
    }
}

void cleanPerson_6(AddressBook *abs){
    if(abs->mNum != 0){
        for(int i = abs->mNum ; i >= 0; i--)
            abs->PersonArr[abs->mNum--].mName = "";
    }
    abs->mNum = 0;
    cout<<"\033c"<<"AddressBook Empty!!!"<<endl;
}

void Select(int select,AddressBook *abs,string *name){
    switch (select){
    case 0:
        cout<<"\033c"<<"Bye Bye!"<<endl;
        //pause();    //system("pause");For Linux 系统挂起
        exit(0);        //终止进程
        break;
    case 1:
        addPerson_1(abs,&abs->mNum);
        break;
    case 2:
        showPerson_2(abs);
        break;
    case 3:
        searchPerson_3(abs,name);
        break;
    case 4:
        delPerson_4(abs,name);
        break;
    case 5:
        modifyPerson_5(abs,name);
        break;
    case 6:
        cleanPerson_6(abs);
        break;
    default:
        cout<<"Wrong Choice!"<<endl;
        break;
    }
}

void showMenu(){
    for (int i = 0; i < 9; i++){
        if(0==i||8==i)
            cout<<"**********************"<<endl;
        else if(i<7&&i>0){
            cout<<"******"<<i;
            if(1==i)cout<<"-Add\t";
            if(2==i)cout<<"-Show\t";
            if(3==i)cout<<"-Search\t";
            if(4==i)cout<<"-Del\t";
            if(5==i)cout<<"-Modify\t";
            if(6==i)cout<<"-Clean\t";
            cout<<"******"<<endl;}
        else
            cout<<"******"<<i-7<<"-Quit\t"<<"******"<<endl;
    }
    cout<<"Please Input Your Choice:"<<endl;
}

int main(){
    AddressBook abs;
    abs.mNum = 0;
    while (1){
        int select = -1;
        string name;
        showMenu();
        cin>>select;
        if(2 < select && 6 >select){
            cout<<"\033c"<<"Input The Name:"<<endl;
            cin>>name;
        }
        Select(select,&abs,&name);
    }
}
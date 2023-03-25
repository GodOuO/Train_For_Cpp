#include<iostream>
using namespace std;
void Del_Repete(int array[],int &len){
	for (int i = 0; i < len; i++) {                     //每次循环判断m_Array[i]的值是否重复
		for (int j = i + 1; j < len;) {                 //暂时不给出循环条件，若出现重复数据，
			if (array[i] == array[j]) {            //判断某一个数据和后面的数据是否相同
				for (int m = j; m < len - 1; m++) {     //若相同，将后面的数据向前移动，覆盖前面的数据，则数组长度减小，即长度变为len - 1
					array[m] = array[m + 1];
				}
				len--;                                  //循环条件，数据长度减一
			}
			else {                                      //如果某一个数据与后面的数据不同，则这个数据与后面数据的后面一个数据比较是否相同
				j++;
			}
		}
	}
	cout<<len<<endl;
}
int main(){
    int m_EmpArray [] = {1,1,1,1,1,2,3,4,5,5};

    int m_EmpNum = sizeof(m_EmpArray)/sizeof(m_EmpArray[0]);
	cout<<m_EmpNum<<endl;
    
	Del_Repete(m_EmpArray,m_EmpNum);
    for (int i = 0; i < m_EmpNum; i++)
    {
        cout<<m_EmpArray[i]<<";";
    }
	cout<<endl<<m_EmpNum<<endl;
    
}
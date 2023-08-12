#include <iostream>
#include<functional>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

/*
 *
 * 普通函数适配
 * ptr_fun  把普通函数转函数对象
 * 再加适配
 *
 * 类中成员函数适配
 * 当容器中存储的是对象，则用 mem_fun_ref 来适配其成员函数
 * 当容器中存储的是对象指针，则用 mem_fun 来适配其成员函数
 *
 * */

class C1{
public:
    C1(int id,string name){
        this->id=id;
        this->name=name;
    }

    void printC1(){
        cout<<this->name<<"--"<< this->id<<endl;
    }

    int id;
    string name;

    ~C1(){}
};

void printC1(const C1 &c){
    cout<<c.name<<"--"<<c.id<<endl;
}



void func2(){

    vector<C1>v1{C1(123,"tom"),C1(456,"jerry")};

    //普通函数调用
    for_each(v1.begin(),v1.end(), printC1);
    cout<<endl;

    //当容器中存储的是对象，则用 mem_fun_ref 来适配其成员函数
    for_each(v1.begin(),v1.end(), mem_fun_ref(&C1::printC1));
    cout<<endl;

    //当容器中存储的是对象指针，则用 mem_fun 来适配其成员函数
    vector<C1 *>v2{new C1(123,"tom"),new C1(456,"jerry")};
    for_each(v2.begin(),v2.end(), mem_fun(&C1::printC1));
    cout<<endl;
}



void myPrint(int a){
    cout<<a<<"--";
}

void myPrint2(int a,int b){
    cout<<a*b<<"--";
}

void func1(){
    vector<int>v1{1,2,3,4};

    //普通函数
    for_each(v1.begin(),v1.end(), myPrint);

    cout<<endl;

    //普通函数 转 函数对象
    for_each(v1.begin(),v1.end(), ptr_fun(myPrint));

    cout<<endl;

    //普通函数 转 函数对象  再加适配器
    for_each(v1.begin(),v1.end(), bind2nd(ptr_fun(myPrint2),10));


}


int main(){
    //func1();
    func2();
    return 0;
}
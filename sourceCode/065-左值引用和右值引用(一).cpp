#include <iostream>
#include<string>
using namespace std;

/*
 *
 * 左值引用-绑定左值
 * const 左值引用，可以绑定左值和右值
 *
 * 右值引用-绑定右值-c++11引入
 * const 右值引用，只能绑定右值，不能绑定左值
 *
 * 引用类型的变量，在定义时就要初始化,且不能用NULL来赋值
 *
 * */


//左值引用-
void func1(){

    int a=123;
    int &b=a;
    b=456;
    cout<<a<<" "<<b<<endl;


    //int &c=123;//左值引用不能绑定右值
    //string &d=string{"abc"};//左值引用不能绑定临时对象，因为临时对象也是右值


    const int &e=a;
    //e=789;

    const int &f=123;   //const 左值引用可以绑定右值

    cout<<f<<endl;

    const string &g=string{"abc"};
    cout<<g<<endl;

    //int &h=a+1; //a(取123)+1  反回右值 无法用在左值引用绑定

    const int &i=a+1;//


}

//右值引用
void func2(){

    int a=123;

    //int &&b=a;//右值引用不能绑定左值

    int &&c=123;
    c=456;
    cout<<c<<endl;

    string &&d=string{"abc"};//时对象也是右值
    d="xyz";
    cout<<d<<endl;

    const int &&e=123;
    //e=456;

    const string &&f=string{"abc"};

    //const int &&g=a;//const 右值引用不能绑定左值

    int &&h=a+1;
    cout<<h<<endl;

    const int &&i=a+1;


}


//引用的一些标准
void func3(){

    int a;
    a=123;

    //int &b;
    //b=a;

    //int &&c;
    //c=456;

    int *p= nullptr;
    //int &d=NULL;
    int &&e=NULL;
    cout<<e<<endl;

    string &&f=NULL;
    cout<<f<<"--"<<endl;

}

int main(){
    func3();
    return 0;
}
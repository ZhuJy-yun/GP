#include <iostream>
#include<string>
using namespace std;


template<class T>
struct S1{
    //using type = T;
    typedef T type;
};


/*
 *
 * enable_if
 * 结构体(类)模板
 *
 * enable_if 中的条件特化可以看成一个条件分支语句，在编译期就能决定走哪个分支，条件是否成立
 *
 * 但是，代码中的条件分支语句，必须得执行的时候才知道条件是否成立，走哪个分支
 *
 *
 * 函数模板可以有条件分支
 *
 * 使用场景一般作为函数模板的返回值类型
 *
 * */


template<class T1>
//typename std::enable_if<(sizeof(T1) > 2),T1>::type func1(T1 a){
std::enable_if_t<(sizeof(T1) > 2),T1> func1(T1 a){
    return a;
}



int main(){


    int a =func1(1);
    cout<<a<<endl;

    double b=123;
    double c= func1(b);
    cout<<c<<endl;
    //func1<int>();
    //func1<char>();//给char 发好人卡了，我们不合适


    //enable_if<true>::type *p1= nullptr;   //void *p1=nullptr;
    //enable_if<true,int>::type a= 123;       //int a=123;


    //enable_if<(1<2)>::type

    //const int a=1;
    //const int b=2;
    //enable_if<(a<b)>::type *p2= nullptr;    // void *p2=nullptr;

    //enable_if<(1<2)>::type


    /*
    S1<int>::type a=123;    //int a=123;
    cout<<a<<endl;

    S1<string>::type b="abc";//string b="abc";
    cout<<b<<endl;
    */
    return 0;
}
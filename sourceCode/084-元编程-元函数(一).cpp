#include <iostream>
#include<string>
using namespace std;

/*
 *
 * 元编程 - 模板元编程
 * 与萃取类似，是一种编程方式或思想，而不是某种具体的技术或方法，或某种具体的类库
 * 这种编程方式，能让代码在编译期间就执行并返回结果，以达到提升程序执行效率的作用
 *
 * 相当于执行前置
 *
 * 元函数
 * 用元编程的思想写的函数，可在编译期被执行的函数
 * 元函数包括模板
 *
 *
 * constexpr 关键子，在C++11中开始引入，标识变量或函数在编译期执行
 *
 *
 * objdump -DC a.out>bz.txt
 *
 * */


int func1(int a,int b){
    return a+b;
}

constexpr int func2(int a,int b){
    return a+b;
}

template<class T1>
constexpr T1 func3(T1 a,T1 b){
    return a+b;
}

int main(){

    int a= func1(1111,2222);
    //int b= func2(11111,22222);//不会编译期执行
    constexpr int b= func2(11111,22222);//编译期执行

    constexpr int c= func3(111,222);//编译期执行

    cout<<a<<"--"<<b<<endl;


    return 0;
}

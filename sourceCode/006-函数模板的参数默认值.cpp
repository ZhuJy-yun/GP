#include <iostream>
#include<cxxabi.h>
using namespace std;

/*
 * 函数模板类型参数类型默认值
 *
 * 函数模板类型参数默认值
 * */

//指定类型和值
template<class T1,class T2=int>//这里表示的是类型参数的默认值
void funcT1(T1 a,T2 b=123){//这里表示的是函数中T2类型的参数的默认值
    cout<<a<<"--"<<abi::__cxa_demangle(typeid(a).name(),0,0,0)<<endl;
    cout<<b<<"--"<<abi::__cxa_demangle(typeid(b).name(),0,0,0)<<endl;
}


//指定类型
template<class T1=int,class T2>
void funcT2(T2 b){
    T1 a=b;
    cout<<b<<"--"<<a<<endl;
}

//指定值
//只有一部份类型的数据支持这种写法，整型，枚举，指针
template<class T1,int T2=12> //这种写法，int 不能改了，只参在函数里面传值
void funcT3(T1 a){
    cout<<a<<"--"<<T2<<endl;
}


int main(){

    int a=1;
    int b=2;
    double c=1.1;
    double d=2.2;
    //funcT1(a);
    //funcT2(c);//这里有个强转，类型参数T1用的是默认值int
    //funcT2<double>(c);//这里是显式指定类型参数T1的值


    funcT3(a);


    //这种写法，不支持变量,只能用常量，因为这个值要在编译的时候就确定，而不是运行的时候确定
    int const x=789;
    //funcT3<int,x>(a);//x 是常量，可以




    return 0;
}
#include <iostream>
#include<string>
#include<cxxabi.h>
using namespace std;


/*
 *
 * 退化
 * std::decay<T1>;
 * 丢弃掉const修饰符，左右引用修饰符，数组转成指针，函数名转成函数指针，
 * 这种，称为类型退化
 *
 *
 * is_same<T1,T2>;
 * 判断T1，T2 是否是同一类型
 *
 *
 * 我们要自己用固定萃取的思路实现类似于 decay 的功能
 *
 *
 *
 * 去掉const
 * 去掉引用
 * 去掉数组的[]，转成指针
 * 将函数名转成函数指针
 *
 *
 * 参数
 * 传统变量  const,引用 ------- 去掉
 * 数组    [int],[], const --- 转成指针
 * 函数    ------------------- 转成指针
 *
 *
 * */


//去掉const 修饰符
template <class T1>
struct clearConst{
    using type = T1;
};

template <class T1>
struct clearConst<const T1>{
    using type = T1;
};


//去掉引用
template <class T1>
struct clearReference{
    using type = T1;
};

template <class T1>
struct clearReference<T1&>{
    using type = T1;
};

template <class T1>
struct clearReference<T1&&>{
    using type = T1;
};


template <class T1>
struct myDecay:clearReference<clearConst<T1>>::type {

};


//数组转指针
template <class T1,size_t size>
struct myDecay<T1[size]>{
    using type = T1*;
};

template <class T1>
struct myDecay<T1[]>{
    using type = T1*;
};

//函数转指针
template <class T1,class...args>
struct myDecay<T1(args...)>{
    using type = T1(*)(args...);
};



int func1(int a,char b){
    cout<<"func1--"<<a<<"---"<<b<<endl;
}

int main(){

    int a=123;
    const int b=456;
    int &c=a;
    int &&d=789;
    const int &&e=123;

    int f[4]{};
    const int g[5]{};

    cout<< abi::__cxa_demangle(typeid(decltype(d)).name(),0,0,0)<<endl;
    cout<< abi::__cxa_demangle(typeid(decay<decltype(d)>::type).name(),0,0,0)<<endl;
    cout<< abi::__cxa_demangle(typeid(myDecay<decltype(d)>::type).name(),0,0,0)<<endl;

    cout<<"----------------"<<endl;

    cout<< abi::__cxa_demangle(typeid(decltype(e)).name(),0,0,0)<<endl;
    cout<< abi::__cxa_demangle(typeid(decay<decltype(e)>::type).name(),0,0,0)<<endl;
    cout<< abi::__cxa_demangle(typeid(myDecay<decltype(e)>::type).name(),0,0,0)<<endl;

    cout<<"----------------"<<endl;
    cout<< abi::__cxa_demangle(typeid(decltype(g)).name(),0,0,0)<<endl;
    cout<< abi::__cxa_demangle(typeid(decay<decltype(g)>::type).name(),0,0,0)<<endl;
    cout<< abi::__cxa_demangle(typeid(myDecay<decltype(g)>::type).name(),0,0,0)<<endl;
    cout<<"----------------"<<endl;


    cout<< abi::__cxa_demangle(typeid(decltype(func1)).name(),0,0,0)<<endl;
    cout<< abi::__cxa_demangle(typeid(decay<decltype(func1)>::type).name(),0,0,0)<<endl;
    cout<< abi::__cxa_demangle(typeid(myDecay<decltype(func1)>::type).name(),0,0,0)<<endl;


    /*
    int (*pf)(int,char)= nullptr;
    pf=func1;
    pf(1,'1');
    */
    /*
    //去掉const
    cout<<is_same<clearConst<decltype(b)>::type,int>::value<<endl;

    //去掉引用
    cout<<is_same<clearReference<decltype(c)>::type,int>::value<<endl;
    cout<<is_same<clearReference<decltype(d)>::type,int>::value<<endl;

    cout<<endl;

    //组合--得先去掉引用，再去掉const
    cout<<is_same<clearConst<clearReference<decltype(e)>::type>::type ,int>::value<<endl;

    //cout<<is_same<clearReference<clearConst<decltype(e)>::type>::type ,int>::value<<endl;
    */



    /*
    int a=123;
    const int b=456;
    int &c=a;
    int &&d=789;
    const int &e=321;
    const int &&f=321;

    std::decay<decltype(b)>::type t1;

    //decay 去掉了const int 中的 const 修饰符
    cout<<is_same<decay<const int&&>::type ,int>::value<<endl;
    */


    return 0;
}
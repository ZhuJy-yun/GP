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



int main(){

    int a=123;
    const int b=456;
    int &c=a;
    int &&d=789;
    const int &e=b;


    //去掉const
    cout<<is_same<clearConst<decltype(b)>::type,int>::value<<endl;

    //去掉引用
    cout<<is_same<clearReference<decltype(c)>::type,int>::value<<endl;
    cout<<is_same<clearReference<decltype(d)>::type,int>::value<<endl;

    cout<<endl;

    //组合--得先去掉引用，再去掉const
    cout<<is_same<clearConst<clearReference<decltype(e)>::type>::type ,int>::value<<endl;

    //cout<<is_same<clearReference<clearConst<decltype(e)>::type>::type ,int>::value<<endl;




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
#include <iostream>
#include<string>
using namespace std;

/*
 *
 * 类型萃取
 *
 * https://en.cppreference.com/w/cpp/types#Type_traits
 *
 * 自c++11开始，引入了很多萃取接口，我们把这些接口称为类型萃取接口，基本上都是用结构体(类)模板实现的
 *
 * 就是一堆接口，官方文档里面称为 type traits ，所以我们可以称这一些萃取接口为类型萃取
 *
 *
 * */


template<class T1,class T2>
struct myIsSame{
    using type = bool;
    static const type value=false;
};

template<class T1>
struct myIsSame<T1,T1>{
    using type = bool;
    static const type value=true;
};


int main(){

    int a=123;
    int b=456;
    double c=7.89;

    const int e=789;

    cout<<is_same<decltype(a), decltype(b)>::value<<endl;
    cout<<is_same<decltype(a), decltype(c)>::value<<endl;
    cout<<endl;

    cout<<myIsSame<decltype(a), decltype(b)>::value<<endl;
    cout<<myIsSame<decltype(a), decltype(c)>::value<<endl;
    /*
    cout<<is_const<decltype(a)>::value<<endl;
    cout<<is_const<decltype(e)>::value<<endl;
    */

    return 0;
}
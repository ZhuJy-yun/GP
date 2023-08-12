#include <iostream>
#include<string>
#include<cxxabi.h>

using namespace std;

/*
//泛化版
template <bool _Bp, class _If, class _Then>
struct conditional {
    typedef _If type;
};

//特化版
template <class _If, class _Then>
struct conditional<false, _If, _Then> {
    typedef _Then type;
};
*/

/*
 * std::conditional<bool,T1,T2>
 * 结构体模板
 *
 * 模板中编译期间条件预判断
 *
 *
 * 有点类似于三目运算
 *
 * */

int main(){

    conditional<true,int,char>::type t1;  //int
    conditional<false,int,char>::type t2; //string

    cout<< abi::__cxa_demangle(typeid(t1).name(),0,0,0)<<endl;
    cout<< abi::__cxa_demangle(typeid(t2).name(),0,0,0)<<endl;


    constexpr int a=23;

    conditional<
                (a>100),
                conditional<(a>150),int,char>::type,
                conditional<(a>50),bool,double>::type
            >::type t3;

    cout<< abi::__cxa_demangle(typeid(t3).name(),0,0,0)<<endl;

    return 0;
}
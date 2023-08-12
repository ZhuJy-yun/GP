#include <iostream>
#include<string>
#include<cxxabi.h>
using namespace std;

/*
template <class _Tp, _Tp __v>
struct _LIBCPP_TEMPLATE_VIS integral_constant
{
    static _LIBCPP_CONSTEXPR const _Tp      value = __v;
    typedef _Tp               value_type;
    typedef integral_constant type;
    _LIBCPP_INLINE_VISIBILITY
    _LIBCPP_CONSTEXPR operator value_type() const _NOEXCEPT {return value;}
#if _LIBCPP_STD_VER > 11
    _LIBCPP_INLINE_VISIBILITY
    constexpr value_type operator ()() const _NOEXCEPT {return value;}
#endif
};
*/

class C1{};
union C2{};
int main(){

    //判断是否是结构体或类
    cout<<is_union<C1>::value<<endl;
    cout<<is_union<C2>::value<<endl;
    cout<<endl;
    cout<<is_class<C1>::value<<endl;
    cout<<is_class<C2>::value<<endl;

    /*
    //是一个特化版结构体模板的别名
    // 本质是一种数据类型，可作变量类型或返回值类型，里面有成员属性和方法

    //integral_constant<bool,true>

    std::true_type t1;
    cout<<t1.value<<endl;

    //integral_constant<bool,false>
    std::false_type t2;
    cout<<t2.value<<endl;



    bool abc;
    int xyz;
    true_type def;

    cout<< abi::__cxa_demangle(typeid(true_type::value_type).name(),0,0,0)<<endl;
    cout<< abi::__cxa_demangle(typeid(true_type ::value_type).name(),0,0,0)<<endl;

    */

    return 0;
}
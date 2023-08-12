#include <iostream>
#include<string>
#include<cxxabi.h>
#include<vector>
using namespace std;


/*
 * std::remove_all_extents<T>::type t1;
 *
 * c++11中开始引入
 * 获取数组元素的具体数据类型
 * 通过递归的方式实现
 *
 * */


template <class _Tp>
struct remove_all_extents_x{
    typedef _Tp type;
};

template <class _Tp>
struct remove_all_extents_x<_Tp[]>{
    typedef typename remove_all_extents_x<_Tp>::type type;
};

template <class _Tp, size_t _Np>
struct remove_all_extents_x<_Tp[_Np]>{
    typedef typename remove_all_extents_x<_Tp>::type type;
};

/*
 * remove_all_extents_x<int[2][3][4]>::type t1;
 *    typedef typename remove_all_extents_x<int[3][4]>::type type;
 *          typedef typename remove_all_extents_x<int[4]>::type type;
 *              typedef typename remove_all_extents_x<int>::type type;
 *
 * */

int main(){

    int a[2][3][4]{};

    //remove_all_extents_x<decltype(a)>::type t1;
    remove_all_extents_x<int[2][3][4]>::type t1;

    extern int b[];//无边界数组


    cout<< abi::__cxa_demangle(typeid(t1).name(),0,0,0)<<endl;




    /*
    int a[2]{};
    int b[2][3]{};
    int c[2][3][4]{};

    char d[2][3]{};
    int *e[2][3]{};
    vector<int>f[2]{};


    std::remove_all_extents<decltype(d)>::type t1;
    std::remove_all_extents<decltype(e)>::type t2;
    std::remove_all_extents<decltype(f)>::type t3;

    cout<< abi::__cxa_demangle(typeid(t1).name(),0,0,0)<<endl;
    cout<< abi::__cxa_demangle(typeid(t2).name(),0,0,0)<<endl;
    cout<< abi::__cxa_demangle(typeid(t3).name(),0,0,0)<<endl;
    //cout<< abi::__cxa_demangle(typeid(t2).name(),0,0,0)<<endl;
*/

    return 0;
}
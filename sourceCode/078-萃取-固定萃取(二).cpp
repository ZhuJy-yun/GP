#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <array>
#include <cxxabi.h>
using namespace std;

template <class T1>
struct getType
{
    using type = typename T1::value_type;
};

/*
template<class T1>
struct getType<vector<T1>>{
    using type = T1;
};

template<class T1>
struct getType<list<T1>>{
    using type = T1;
};
*/
template <class T1, size_t size>
struct getType<array<T1, size>>
{
    using type = T1;
};

// 别名
template <class T1>
using TYPE = typename getType<T1>::type;

template <class T1>
void func1(const T1 &a)
{
    cout << abi::__cxa_demangle(typeid(TYPE<T1>).name(), 0, 0, 0) << endl;
}

int main()
{

    vector<int> a{};
    list<double> b{};
    array<char, 10> c{};

    func1(a);
    func1(b);
    func1(c);

    // getType<decltype(a)>::type t1;
    // getType<decltype(b)>::type t2;
    // getType<decltype(c)>::type t3;

    /*
    TYPE<decltype(a)> t1;
    TYPE<decltype(b)> t2;
    TYPE<decltype(c)> t3;

    cout<< abi::__cxa_demangle(typeid(t1).name(),0,0,0)<<endl;
    cout<< abi::__cxa_demangle(typeid(t2).name(),0,0,0)<<endl;
    cout<< abi::__cxa_demangle(typeid(t3).name(),0,0,0)<<endl;
    */

    /*
    int a[2]{};
    vector<int>b{};
    remove_all_extents<decltype(a)>::type t1;
    remove_all_extents<decltype(b)>::type t2;
    cout<< abi::__cxa_demangle(typeid(t1).name(),0,0,0)<<endl;
    cout<< abi::__cxa_demangle(typeid(t2).name(),0,0,0)<<endl;
    */
    return 0;
}

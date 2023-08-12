#include <iostream>
#include<cxxabi.h>

using namespace std;

template<class ...T1>
class C1{
    public:
        C1(){
            printf("C1--T1\n");
        }
};

template<class T2,class ...T3>
class C1<T2,T3...>:private C1<T3...>{
    public:
        C1(){
            printf("C1--T2--T3--%s--%d\n", abi::__cxa_demangle(typeid(T2).name(),0,0,0),sizeof...(T3));
        }
};

/*
 *
 * 递归继承解包的过程
 *
 * class C1<int,double,float>:private C1<double,float>{}
 *
 *      class C1<double,float>:private C1<float>{}
 *
 *          class C1<float>:private C1<>{}
 *
 *              class C1{}
 *
 *
 * 递归    先递   再归
 *
 *
 * */


int main(){

    C1<int,double,float>c1;

    return 0;
}
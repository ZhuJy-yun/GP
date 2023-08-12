#include <iostream>
#include<string>
using namespace std;

//这种 constexpr 递归的写法，要求编译器支持编译期递归

//阶乘 - n*(n-1) 5*4*3*2...

template<int a>
constexpr int func1(){
    return a* func1<a-1>();
}

template<>
constexpr int func1<0>(){
    return 1;
}



//连续自然数求和 - 可变参函数模板  递归拆包
template<int ...a>
constexpr int func2=0;

template<int first,int ...a>
constexpr int func2<first,a...> = first+func2<a...>;




int main(){

    constexpr int a= func1<10>();
    //cout<<a<<endl;

    constexpr int b=func2<1,2,3,4,5,6,7,8,9,10>;
    //cout<<b<<endl;

    static_assert(b==55,"b error");    //静态断言，编译器间进行判断


    return 0;
}
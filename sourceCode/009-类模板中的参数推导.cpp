#include <iostream>
#include<string>
using namespace std;

template<class T1,class T2>
class C1{
public:
    C1(T1 id,T2 name){
        this->id=id;
        this->name=name;
    }
    T1 id;
    T2 name;
};

/*
 * 从c++17开始，支持类模板的自动推导
 *
 * */

//有参构造自动推导
template<class T1,class T2>
class C2{
public:
    C2(T1 id,T2 name){
        this->id=id;
        this->name=name;
    }
    T1 id;
    T2 name;
};

//没有构造函数自动推导
template<class T1,class T2>
class C3{
public:
    T1 id;
    T2 name;
};

//自定义推导规则
template<class T1,class T2>
class C4{
public:
    T1 id;
    T2 name;
};
template<class T1,class T2>
C4(T1,T2)->C4<T1,T2>;

//结构体也支持自定义推导
template<class T1,class T2>
struct S1{
    T1 id;
    T2 name;
};
template<class T1,class T2>
S1(T1,T2)->S1<T1,T2>;


int main(){

    //C1<int,string> c1(123,"tom");
    //cout<<c1.id<<"--"<<c1.name<<endl;

    //C2 c2(123,"tom");
    //cout<<c2.id<<"--"<<c2.name<<endl;

    //无构造函数，要显式指定
    C3<int,string>c3;
    c3.id=123;
    c3.name="tom";
    cout<<c3.id<<"--"<<c3.name<<endl;

    //加自定义推导规则
    C4 c4{123,"tom"};
    cout<<c4.id<<"--"<<c4.name<<endl;

    S1 s1{"tom","tom"};
    cout<<s1.id<<"--"<<s1.name<<endl;

    return 0;
}
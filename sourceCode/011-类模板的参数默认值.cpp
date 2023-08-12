#include <iostream>
#include<string>
using namespace std;

//template<class T1,class T2>//没有默认值
//template<class T1=int,class T2=string>//全部默认值

//部份参数默认值的情况下，第一个有默认值的参数后面的所有参数，都要有值
//template<class T1=int,class T2>//部份默认值 错误
template<class T1,class T2=string>//部份默认值
class C1{
public:
    C1(T1 id,T2 name){
        this->id=id;
        this->name=name;
    }
    T1 id;
    T2 name;
};


//局部特化--类型参数不能加默认值
template<class T1>
class C1<T1,string>{
public:
    C1(T1 id,string name){
        this->id=id;
        this->name=name;
        cout<<"这里是局部特化"<<endl;
    }
    T1 id;
    string name;
};



//默认值引用，后面的变量从前面变量中取值
template<class T1,class T2=T1 *>
class C2{
public:
    C2(T1 id,T2 name){
        this->id=id;
        this->name=name;
    }
    T1 id;
    T2 name;
};


//类模板在时候声明的时候给类型默认值
template<class T1=int,class T2=int>
class C3{
public:
    C3(T1,T2);
    T1 id;
    T2 name;
};

template<class T1,class T2>
C3<T1,T2>::C3(T1 id, T2 name) {
    this->id=id;
    this->name=name;
}


template<class T1,class T2,class T3=int>
struct S1;

template<class T1,class T2=int,class T3>
struct S1;

template<class T1,class T2,class T3>
struct S1{
    T1 id;
    T2 name;
    T3 sex;
};

int main(){

    //C1<int,string>c1(123,"tom");//没有默认值，显示指定类型

    //C1<>c1(123,"tom");//全部参数默认值

    //C1<int>c1(123,"tom");//部份参数默认值

    //C1<int>c1(123,"tom");

    //cout<<c1.id<<"--"<<c1.name<<endl;

    //int a=123;
    //C2<int>c2(a,&a);
    //cout<<c2.id<<"--"<<c2.name<<endl;

    //类模板在声明的时候给类型参数默认值
    C3<>c3(1.1,2.2);
    cout<<c3.id<<"--"<<c3.name<<endl;

    S1<int>s1;
    s1.id=1;
    s1.name=2;
    s1.sex=3;
    cout<<s1.id<<"--"<<s1.name<<"--"<<s1.sex<<endl;

    return 0;
}
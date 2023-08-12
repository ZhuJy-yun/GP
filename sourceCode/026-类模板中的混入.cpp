#include <iostream>
using namespace std;

class A{
    public:
        A(){
            cout<<"a"<<endl;
        }
        int a;
};

class B{
    public:
        B(){
            cout<<"b"<<endl;
        }
        int b;
};

class C:public A{

};

class D:public A,public B{

};

//把传过来的类变量当作父类来继承，这种称为混入
template<class ...T1>
class E:public T1...{

public:
    E(){cout<<"e"<<endl;}
};

template<class ...T2>
class F:public E<T2...>{

};

using EA=E<A>;
using FEAB=F<A,B>;  //f->e->a,b


int main(){
/*
    EA ea;
    ea.a=123;
    cout<<ea.a<<endl;
*/

    FEAB feab;
    feab.a=123;
    feab.b=456;
    cout<<feab.a<<"--"<<feab.b<<endl;


    //E<A>e1;
    //e1.a=123;
    //cout<<e1.a<<endl;

    /*
    E<A,B>e2;
    e2.a=123;
    e2.b=456;
    cout<<e2.a<<"--"<<e2.b<<endl;
    */

    /*
    F<A>f1;
    f1.a=123;
    cout<<f1.a<<endl;
    */

    /*

     //传统继承

    C c1;
    c1.a=123;
    cout<<c1.a<<endl;

    D d1;
    d1.a=123;
    d1.b=456;
    cout<<d1.a<<"--"<<d1.b<<endl;
    */

    return 0;
}
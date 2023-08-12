#include <iostream>
#include<string>
using namespace std;


//泛化
template<class T1,class T2>
class C1{
public:
    C1(){
        cout<<"这里是C1-构造"<<endl;
    }
    void func1(){
        cout<<"这里是C1-func1"<<endl;
    }

    static int flag;

};
template<class T1,class T2>
int C1<T1,T2>::flag=123;



//成员函数特化
template<>//全特化
void C1<int,int>::func1() {
    cout<<"这里是C1-func1-全特化-int-int"<<endl;
}

//成员变量全特化
template<>
int C1<double,double>::flag=456;

//成员变量也不支持独立半特化
/*
template<class T1>
int C1<T1,double>::flag=789;
*/

//成员函数不支持独立半特化
/*
template<class T1>//半特化
void C1<T1,int>::func1() {
    cout<<"这里是C1-func1-半特化-T1-int"<<endl;
}
 */

//如果用相同的条件对成员函数或成员变量进行了特化，则无法再用此次条对类模板进行全特化


//整个类模板全特化--这里相对于泛化版来讲，完全是两个独立的类，除了名字一样，其它都是不一样的，
//可以有自己的在员方法和变量
template<>
class C1<int,string>{
public:
    C1(){
        cout<<"这里是C1-全特化-构造"<<endl;
    }
    void func1(){
        cout<<"这里是C1-全特化-func1"<<endl;
    }
    void func2(){
        cout<<"这里是C1-全特化-func2"<<endl;
    }
};


//半特化-参数个数半特化
template<class T1>
class C1<T1,string>{
public:
    C1(){
        cout<<"这里是C1-半特化-T1-string-构造"<<endl;
    }
    void func1(){
        cout<<"这里是C1-半特化-T1-string-func1"<<endl;
    }

    void func2(){
        cout<<"这里是C1-半特化-T1-string-func2"<<endl;
    }
};

//参数范围特化
template<class T1,class T2>
class C1<const T1,T2 *>{
public:
    C1(){
        cout<<"这里是C1-参数范围特化-const T1-T2 *-构造"<<endl;
    }
    /*
    void func1(){
        cout<<"这里是C1-半特化-T1-string-func1"<<endl;
    }

    void func2(){
        cout<<"这里是C1-半特化-T1-string-func2"<<endl;
    }
     */
};


int main(){

    /*
    C1<int,string>c1;
    c1.func1();
    cout<<c1.flag<<endl;//123
    cout<<endl;
    C1<int,int>c11;
    c11.func1();

    C1<double,double>c111;
    cout<<c111.flag<<endl;//456
    */


    C1<int,double>c1;//泛化
    c1.func1();


    C1<int,string>c11;//全特化
    c11.func1();
    c11.func2();

    C1<string ,string>c111;//半特化
    c111.func1();
    c111.func2();


    C1<const int,int *>c1111;


    //C1<string,int>c111;
    //c111.func1();


    return 0;

}
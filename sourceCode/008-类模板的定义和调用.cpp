#include <iostream>
#include<string>
using namespace std;

//非模板类
class C1{
public:
    C1(int id,string name){
        this->id=id;
        this->name=name;
    }
    ~C1(){}
    void show(){
        cout<<id<<"--"<<name<<endl;
    }
    static void func1(){
        cout<<"这里是 c1-func1"<<endl;
    }
    int id;
    string name;

};


//类模板
template<class T1,class T2>
class C2{
public:
    C2(T1 id,T2 name){
        this->id=id;
        this->name=name;
    }
    ~C2(){}
    void show(){
        cout<<id<<"--"<<name<<endl;
    }
    static void func1(){
        cout<<"这里是 c2-func1"<<endl;
    }
    T1 id;
    T2 name;
};


//类模板默认值
//默认值要放在最后面
//template<class T1=int,class T2> //报错
template<class T1=int,class T2=string>
//template<class T1,class T2=string>
class C3{
public:
    C3(T1 id=456,T2 name="jerry"){
        this->id=id;
        this->name=name;
    }
    ~C3(){}
    void show(){
        cout<<id<<"--"<<name<<endl;
    }
    static void func1(){
        cout<<"这里是 c2-func1"<<endl;
    }
    T1 id;
    T2 name;
};


int main(){

    /*
    C1 c1(123,"tom");
    c1.show();
    c1.func1();
    C1::func1();
    */

    //类模板中无法根据参数值来推导类型变量，要显示指定
    //实例化方式和成员方法调用跟非类模板中一样，只是要指定类型参数的值
    /*
    C2<int,string>c2(123,"tom");
    c2.show();
    c2.func1();
    C2<int,int>::func1();
    */

    //C3<int,int>c3(123,456);
    //c3.show();

    C3<string,string>c3("tom","tom");
    c3.show();

    C3<>::func1();

    return 0;
}
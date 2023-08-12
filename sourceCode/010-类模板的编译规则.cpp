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

    void func1(){
        cout<<"func1"<<endl;
    }
    static void func2(){
        cout<<"static func2"<<endl;
    }

    T1 id;
    T2 name;
};


/*
 * 如果没有实例化，则不会编译类模板，被编译器优化掉了，认为是无效代码
 * 如果有实例化，只会编译出对应的参数类型的代码，相央类型参数的，只会编译一份
 * 如果成员函数没有被调用，则也不会编译出来
 *
 * 本质上来讲，跟普通类编译的规则是一致的，只不过会有多份代码，每种有使用的类型都会编译一份
 *
 * win dumpbin
 * */

int main(){

    C1<int,int>c1(123,456);
    c1.func1();
    C1<double,double> c11(1.1,1.1);
    c11.func2();

    return 0;
}
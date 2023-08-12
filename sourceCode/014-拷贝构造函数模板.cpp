#include <iostream>
using namespace std;


class C1{
public:
    C1(){
        cout<<"这里是构造"<<endl;
    }

    //自定义的拷贝构造怎么实现，不放这里
    C1(const C1 &c2){
        cout<<"这里是拷贝构造"<<endl;
    }

    C1 & operator=(const C1 &c2){
        cout<<"这里是拷贝符值运算符重载"<<endl;
        return *this;
    }

};

template<class T1>
class C2{
public:
    C2(){
        cout<<"这里是构造"<<endl;
    }

    //拷贝构造 函数板
    template<class T2>
    C2(const C2<T2> &c2){
        cout<<"这里是拷贝构造"<<endl;
    }

    //也是可以特化的
    C2(const C2<float> &c2){
        cout<<"这里是拷贝构造-特化-float"<<endl;
    }


    template<class T3>
    C2<T1> & operator=(const C2<T3> &c2){
        cout<<"这里是拷贝符值运算符重载"<<endl;
        return *this;
    }

    int id;

};



int main(){

    //特化
    C2<float>c2F;
    C2<int>c2Int(c2F);


    //C2<int>c2;
    //c2.id=123;

    //C2<int>c22(c2);//这里并没有调用拷贝构造，因为c22和c2 的T1 是一样的，在一样的情况下，会去调用系统提供的默认拷贝构造函数(按值拷贝)，而不会调用拷贝构造函数模板
    //cout<<c22.id<<endl;//123

    //C2<double>c222(c2);//这里才会调用拷贝构造函数模板,因为c222和c2 的T1 是不一样的
    //cout<<c222.id<<endl;

    //类型一样，调用的是默认的赋值方法
    //C2<int>c2222;
    //c2222=c2;
    //cout<<c2222.id<<endl;//123

    //类型不一样，才会调用模板
    //C2<double>c22222;
    //c22222=c2;


    /*
    C1 c1;
    C1 c11(c1);
    C1 c111;
    c111=c1;
    */
    return 0;
}
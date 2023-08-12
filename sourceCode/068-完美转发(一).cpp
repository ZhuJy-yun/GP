#include <iostream>
#include<string>
using namespace std;


void func2(int &a,int &&b){
    cout<<a<<"--"<<b<<endl;
}


//万能引用-能绑定左值引用，也能绑定右值引用
template<class T1,class T2>
void func1(T1 &&a,T2 &&b){

    //转发-通过中间函数间接调用目标函数，如果目标函数有参数，则参数也要通过中间函数传递，此处的func2 相当于跳板函数,起到一个转发的作用
    //func2(a,b);

    //完美转发-在转发的过程中，实参属性完全保留，通过跳板函数完全传递给目标函数
    //在万能引用中--用 std::forward<>() 配合实现完美转发
    func2(
            std::forward<T1>(a),
            std::forward<T2>(b)
            );
}


void func3(int &a){
    cout<<"左值引用"<<endl;
}
void func3(const int &a){
    cout<<"const 左值引用"<<endl;
}
void func3(int &&a){
    cout<<"右值引用"<<endl;
}
/*
void func3(const int &&a){
    cout<<"const 右值引用"<<endl;
}
*/

template<class T3>
void func4(T3 && a){
    func3(
            std::forward<T3>(a)
    );
}


int main(){

    //int a=1;
    //func1(a,123);

    //int &&b=123;//int &&b 是右值引用，没错,但是 变量b 本身是左值
    //int &c=b;//所以此处，可以用左值引用绑定

    //int &&d=a;//左值不能用右值引用绑定


    int i=1;
    const int j=2;

    int &k=i;
    int &&l=3;

    const int &m=i;
    const int &&n=3;

    func4(i);//左值引用
    func4(123);//右值引用
    func4(std::move(i));//右值引用
    func4(int(123));//右值引用--临时对象
    func4(j);//const 左值引用

    func4(k);//左值引用
    func4(l);//左值引用
    func4(m);//const 左值引用
    func4(n);//const 左值引用


    return 0;
}
#include <iostream>
#include<string>
using namespace std;

/*
 *
 * 左值引用绑左值
 * 右值引用绑右值
 * std::move() 左值转右值
 *
 * const 左值引用可以绑右值
 * const 右值引用不能绑左值
 *
 * 万能引用(universal reference) 也称转发引用(forwarding reference)，未定义引用
 *
 *
 * 前提
 * 1 一定是在函数模板中
 * 2 一定发生了类型推导
 *
 *
 * 格式
 * template<class T>
 * func(T &&a){}    T1&&a    T1 &&a    T1&& a    T1 && a
 *
 *
 *
 *
 *
 * //这里是右值引用
 * template<class T>
 * func(vector<T> &&a){}
 *
 * //右值引用
 * func(int &&a){}
 *
 *
 *
 * 这种也是万能引用
 * auto &&x=123;
 * auto &&y=x;
 *
 *
 * */



//左值引用
template<class T1>
void func1(T1 &a){
    cout<<a<<endl;
}

//右值引用 -- 实际上是万能引用 -- 能绑定左值，又能绑定右值
template<class T2>
void func2(T2 &&a){
    cout<<a<<endl;
    a=456;
}

template<class T3>
class C1{
    public:
        //这里不是万能引用，这里是右值引用，因为在实例化C1的时候，必须显式指定T3,而不是自动推导出其数据类型
        void func1(T3 &&a){
            cout<<a<<endl;
        }

        //这种写法就是类成员函数的万能引用
        //这里是万能引用--因为此处是函数模板，并且发生了类型推导
        template<class T4>
        void func2(T4 &&a){
            cout<<a<<endl;
        }

};



//参数加const 修饰之后，由万能引用变回右值引用了
template<class T5>
void func3(const T5 &&a){
    cout<<a<<endl;

}

int main(){
    int a=123;
    //func1(a);


    //func2(a);//万能引用-绑定左值
    //func2(123);//万能引用绑定右值

    //cout<<a<<endl;

   // C1<int>c1;

    //c1.func1(a);//不去持
    //c1.func1(123);//右值引用

    //c1.func2(a);
    //c1.func2(a);


    //func3(a);
    func3(123);

    auto &&x=123;
    auto &&y=x;

    return 0;

}


/*
//左值引用
void func1(int &a){
    cout<<a<<endl;
}

//右值引用
void func2(int &&a){
    cout<<a<<endl;
}

int main(){
    int a=123;
    func1(a);
    //func2(a);//右值引用不能绑定左值
    func2(123);
    return 0;
}
*/


#include <iostream>
#include<string>
using namespace std;


int func2(int &a,int &&b){
    cout<<"func2--"<<a<<"--"<<b<<endl;
    return a+b;
}

string func3(int &a,int &&b,string c){
    cout<<"func3--"<<a<<"--"<<b<<"--"<<c<<endl;
    return c;
}

//可变参的函数模板的完美转发
template<class F,class ...T>
//auto func1(F f,T && ...a){
decltype(auto) func1(F f,T && ...a){
    return f(
            std::forward<T>(a)...
    );
}


int main(){

    int a=123;
    int rs1 = func1(func2,a,123);//其实这里是函数指针
    string rs2 = func1(func3,a,123,"abc");//其实这里是函数指针

    cout<<endl<<endl;
    cout<<rs1<<"--"<<rs2<<endl;


    return 0;
}
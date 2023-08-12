#include <iostream>
using namespace std;

double func1(double a,double b){
    return a+b;
}

template<class T>
T funcT1(T a,T b){
    return a+b;
}

template<class T>
void funcT2(){
    cout<<"funcT2"<<endl;
}

template<class T1,class T2,class T3>
T3 funcT3(T1 a,T2 b){
    return a+b;
}

template<class T3,class T1,class T2>
T3 funcT4(T1 a,T2 b){
    return a+b;
}

/*
 * 函数模板的调用方式
 * funcT1(a,b)  这种是编译器根据参数推导类型
 * funcT1<>(a,b)  <>为空此种情况下，也是编译器根据参数推导类型，<>此处无用，但是<>有其它的用处
 *
 *
 *
 * */

int main(){

    int a=1;
    int b=2;
    double c=1.1;
    double d=2.2;
    char e='e';
    string f="f";

    cout<<funcT1(a,b)<<endl;
    cout<<funcT1<>(a,b)<<endl;
    //cout<<funcT1(a,c)<<endl;//这种写法，传了两个不同类型的参数，编译器无法推导用哪种类型，在函数模板里面，无法进行隐式类型转换
    cout<<funcT1<int>(a,c)<<endl;//但是可以显式指定类型
    cout<<funcT1<double>(a,c)<<endl;//要么告诉编译器是什么类型，要么让其自动推导，但是要保证同一个类型参数的数据类型必须一样

    //funcT2();//虽然在函数中没有使用到类型参数，但是也必须得告诉编译器，这里要调用的是函数模板
    funcT2<int>();//因为没有参数，所以编译器就没办法根据参数推导出类型，所以必须得强制指定

    //cout<<funcT3(a,b)<<endl;//这种写法，有三个类型参数，但是只传了两个值，所以编译器无法推导出最后一个类型
    cout<<funcT3<int,int,int>(a,b)<<endl;

    cout<<funcT4<int>(a,b)<<endl;//此处，第一个类型参数要指定，第二个，第三个，可以由编译器自动推导

    //cout<<func1(a,e)<<endl;//普通函数可以进行隐式类型转换


    return 0;
}
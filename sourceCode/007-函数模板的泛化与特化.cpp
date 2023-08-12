#include <iostream>
using namespace std;


template<class T1,class T2>
void funcT1(T1 a,T2 b){
    cout<<"这里是函数模板funcT1"<<endl;
}

//函数模板特化--这里是所有类型参数都特化，称之为全局特化
template<>
void funcT1<int,double>(int a,double b){
    cout<<"这里是函数模板特化-int--double--funcT1"<<endl;
}

//函数模板不支持局部特化,在类模板中还是支持的，后面讲
//如果非要达到这种效果，可以用重载或者是类型参数默认值
/*
template<class T1=int,class T2>
void funcT1(int a,T2 b){
    cout<<"这里是函数局部模板特化-int--double--funcT1"<<endl;
}
 */

/*
void funcT1(int a,double b){
    cout<<"这里是函数重载-int--double--funcT1"<<endl;
}
 */

//泛化特化的概念是相对的，默认的函数模板(没有默认值的情况下)都是泛化
//优先级  1 普通函数；   2 特化版函数模板；   3 泛化版函数模板


int main(){
    int a=1;
    int b=2;
    double c=1.1;
    double d=2.2;
    funcT1(a,b);//int,int
    funcT1(c,d);//double,double
    funcT1(a,c);//int,double-------特化
    funcT1(c,a);//double,int


    return 0;
}
#include <iostream>
#include<functional>
#include<algorithm>
#include<vector>
using namespace std;

/*
 *
 * 函数对象 - 仿函数
 * 重载函数调用操作符的类，其对象称为函数对象，
 * 就是行为类似函数的对象，也叫仿函数，其实就是重载()操作符，使类对象可以像函数一样调用
 *
 * 函数对象是一个类，不是一个函数
 * 函数对象重载了 () 操作符，使得其可以像函数一样调用
 *
 * 当类重载的 ()运算符中要传一个参数，则称其为 一元仿函数
 * 当类重载的 ()运算符中要传两个参数，则称其为 二元仿函数
 *
 *
 * 作用：配合算法一起使用
 *
 * 函数对象有自己的状态，有自己类型
 *
 * 成员函数会处理成内联，效率可能会更高
 *
 * 谓词
 * 指普通函数或重载的operator()返回值是 bool 类型的函数对象
 * 可以作为判断式
 * 一元谓词
 * 二元谓词
 *
 *
 * template<class T>T plus<T>       加法
 * template<class T>T minus<T>      减法
 * template<class T>T multiplies<T> 乘法
 * template<class T>T divides<T>    除法
 * template<class T>T modulus<T>    取模
 * template<class T>T negate<T>     取反
 *
 * template<class T>bool equal_to<T>       等于
 * template<class T>bool not_equal_to<T>   不等于
 * template<class T>bool greater<T>        大于
 * template<class T>bool greater_equal<T>  大于等于
 * template<class T>bool less<T>           小于
 * template<class T>bool less_equal<T>     小于等于
 *
 * template<class T>bool logic_and<T>      逻辑与
 * template<class T>bool logic_or<T>       逻辑或
 * template<class T>bool logic_not<T>      逻辑非
 *
 *
 * */
template<class T>
typedef struct mySort{

    bool operator()(const T &a,const T &b){
        return a>b;
    }
};

typedef struct myComp{

    bool operator()(const int &a){
        return a<-111;
    }
};


void func1(){

    vector<int>v1{1,11,111,2,22,222,2222,3,33};
    for(auto start = v1.begin();start != v1.end();start++){
        cout<<*start<<"--";
    }
    cout<<endl;

    sort(v1.begin(),v1.end());
    for(auto start = v1.begin();start != v1.end();start++){
        cout<<*start<<"--";
    }
    cout<<endl;

    //sort(v1.begin(),v1.end(),greater<int>());// sort 算法    greater<int>()  函数对象
    sort(v1.begin(),v1.end(),mySort<int>());// sort 算法    greater<int>()  函数对象
    for(auto start = v1.begin();start != v1.end();start++){
        cout<<*start<<"--";
    }
    cout<<endl;


    vector<int>::iterator iter = find_if(v1.begin(),v1.end(),myComp());
    if(iter == v1.end()){
        cout<<"没有"<<endl;
    }else{
        cout<<*iter<<endl;
    }



}

int main(){
    func1();
    return 0;
}
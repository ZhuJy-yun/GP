#include <iostream>
#include<string>
#include<vector>
using namespace std;

/*
 *
 * SFINAE(Substitution failure is not an error) - 替换失败不是错误
 *
 * 此处只针对函数(类)模板而言
 *
 * 当用一个具体的类型去替换函数模板中的类型参数时，在编译器器认为该类型无法匹配模板时，
 * 会略过此处，进而去寻找其它更适合的函数
 *
 * 如果没找到 会给出类似于 "note: candidate template ignored: substitution failure"(注意：已忽略候选模板：替换失败)
 * 的提示
 *
 * 继而报错 "error: no matching function for call to"
 *
 * */

template<class T>
typename T::size_type func1(T a){
    return 123;
}

/*
int func1(int a){
    return 456;
}
 */


int main(){
    int a=1;
    cout<<func1(a)<<endl;//是被发好人卡了，你很好，但我们不合适

    cout<<func1(vector<int>{a})<<endl;

    //vector<int>::size_type ;

    return 0;
}
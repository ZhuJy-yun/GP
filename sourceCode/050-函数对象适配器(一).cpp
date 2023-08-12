#include <iostream>
#include<functional>
#include<algorithm>
#include<vector>
using namespace std;

/*
 * 函数对象适配
 *
 * 当函数对象的参数不够用，可以用适配器来配置函数对象
 *
 * bind1st,bind2nd  将二元函数对象配置成一元函数对象
 * 两者区别是参数占位表示的意义不一样
 *
 * */

typedef struct {
    void operator()(int a){
        cout<<a<<"--";
    }
}myPrint;



//binary_function<参数1,参数2,返回类型>
//将二元函数对象变一元
typedef struct myPrint2:public binary_function<int,int,void>{
    void operator()(int a,int b) const{
        cout<<a<<"--"<<b<<"--"<<a*b<<"   ";
    }
};

void func1(){

    vector<int>v1{1,2,3,4};
    for (auto start = v1.begin(); start != v1.end() ; start++) {
        cout<<*start*10<<"--";
    }
    cout<<endl;

    for_each(v1.begin(),v1.end(),myPrint());

    cout<<endl;
    for_each(v1.begin(),v1.end(), bind2nd(myPrint2(),10));

    cout<<endl;
    for_each(v1.begin(),v1.end(), bind1st(myPrint2(),10));

}


int main(){
    func1();
    return 0;
}
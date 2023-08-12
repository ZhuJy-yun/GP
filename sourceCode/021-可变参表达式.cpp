#include <iostream>
using namespace std;

//函数模板嵌套
template<class ...T2>
void func2(T2 ...a){
    cout<<(... + a)<<endl;
}

template<class ...T1>
void func1(T1 ...a){
    //cout<<(... + a)<<endl;   //10

    func2(2*a...); //2,4,6,8    20 这种写法就是可变参表达式   逐项运算，再当参数包传给func2
    //func2(a... * 2);
    //func2(a... * a...);

    func2(1+a...); //2,3,4,5    14

}

int main(){

    func1(1,2,3,4);//每个参数*2 再求和

    return 0;
}
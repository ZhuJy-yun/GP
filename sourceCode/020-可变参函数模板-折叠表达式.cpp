#include <iostream>
using namespace std;

/*
template<class ...T1>
void func1(T1 ...a){
    int sum=0;
    for(auto val :{a...}){
        //cout<<val<<endl;
        sum+= val;
    }
    cout<<sum<<endl;
}

int sum2=0;

template<class T2, class ...T3>
void func3(T2 a, T3 ...b){

    sum2+=a;
    if constexpr(sizeof...(b) > 0){ //c++17后引入的内容，表示如果还有参数，就继续调用，这种写法可以省掉递归出口函数
        func3(b...);
    }else{
        cout<<sum2<<endl;
    }
}
 */

/*
 * 折叠表达式
 *
 * 一元折叠表达式-左折
 * (... 运算符 变量名)
 * a,b,c,d    (((a-b)-c)-d)   从左边开始运算
 *
 * 一元折叠表达式-右折
 * (变量名  运算符 ...)
 *a,b,c,d    (a-(b-(c-d)))   从右边开始运算
 *
 *
 * 二元折叠表达式-左折
 * (初始值 运算符 ... 运算符 变量名)
 * default,a,b,c,d    ((((default-a)-b)-c)-d)   从左边开始运算，初始值在最左边
 *
 * 二元折叠表达式-左折
 * (变量名 运算符 ... 运算符 初始值)
 * a,b,c,d,default    (a-(b-(c-(d-default))))   从右边开始运算，初始值在最右边
 *
 * */

template<class ...T4>
void func4(T4 ...a){
    //cout<<(... - a)<<endl;   //(1,2,3,4)    (((1-2)-3)-4)   -8
    //cout<<(a - ...)<<endl;     //（1,2,3,4)   (1-(2-(3-4)))   -2

    //(cout << ...<< a);
}

template<class ...T5>
void func5(T5 ... a){
    //cout<<(10 - ... - a)<<endl;  //(10,1,2,3,4)     ((((10-1)-2)-3)-4)      0
    cout<<(a - ... - 10)<<endl;    //(1,2,3,4,10)     (1-(2-(3-(4-10))))      8
}


int main(){

    //func4(1,2,3,4);

    func5(1,2,3,4);

    //func1(1,2,3,4);
    //func3(1,2,3,4);

    return 0;
}

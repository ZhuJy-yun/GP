#include <iostream>
using namespace std;

//函数模板
template<class T1,class T2>
void func1(T1 a,T2 b){
    cout<<a<<"--"<<b<<endl;
}

/*
//递归出口函数
void func3(){
    cout<<"这里结束递归"<<endl;
}
 */

//可变参函数模板
template<class T33,class ... T3>   //T3是类弄参数变量名 ... 修饰符,  有点类似于指针变量  *p   中的 *
void func3(T33 b ,T3 ...a){     //T3 表示类型  a 表示变量名   int *p ，只不过是，a 里面是多个值，这个就是可变的意思

    //参数个数
    //cout<<sizeof...(T3)<<"--"<<sizeof...(a)<<endl;  //sizeof... 是固定写法，专门用在可变参里面，c++11 开始引入

    /* 循环取值
    //取出所有参数值--只能用在相同类型的参里面
    int sum=0;
    for(auto val :{a...}){
        cout<<val<<endl;
        sum+= val;
    }
    cout<<sum<<endl;
     */


    //买一个三只松鼠零食包，里面有瓜子，核桃，饼干...
    //参数包，里面有int,double,float,string,指针...
    //取值 --解包
    //递归取值(解包)

    //递归是啥 ？
    cout<<b<<endl;
    if constexpr(sizeof...(a) > 0){ //c++17后引入的内容，表示如果还有参数，就继续调用，这种写法可以省掉递归出口函数
        func3(a...);
    }

}

/*
 *
 * 在编译的时候就编译出了所有的函数,
 * 这里的递归跟我们平时所说的递归是不一样的，实际上是编译了多个函数，而不是在执行的时候去反复自己调用自己
 *
 * 这种递归解包取参的方式，很难做复杂运算，这是由递归本身决定的，因为递归就是自己调用自己，一直做同一件事情，直到有出口，然后就结束
 *
 * 这里如果要求和，得每次把前面一次计算的结果都带着，或者用全局变量保存计算结果
 *
 * 后面会去讲把这些参数解出来之后怎么使用，  折叠表达式，元组编程
 *
 *
 * func3(1,2,3,4);------------------------------- <void func3<int, int, int, int>(int, int, int, int)>:
 *      func3(2,3,4);---------------------------- <void func3<int, int, int>(int, int, int)>:
 *          func3(3,4);-------------------------- <void func3<int, int>(int, int)>:
 *              func3(4);------------------------ <void func3<int>(int)>:
                    func3(); ---- 这里结束递归 ---- <func3()>:
 *
 * */





int main(){

    func1(1,2);

    func3(1,2,3,4);//参数类型相同

    /*
    func3();
    func3(1);
    func3(1,2);
    func3(1,2.2,"3.3");
    func3(1,2.2,"3.3", nullptr);
    */

    return 0;
}
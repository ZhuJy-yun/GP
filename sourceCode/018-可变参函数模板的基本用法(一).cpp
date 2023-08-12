#include <iostream>
using namespace std;

//函数模板
template<class T1,class T2>
void func1(T1 a,T2 b){
    cout<<a<<"--"<<b<<endl;
}


//递归出口函数
void func3(){
    cout<<"这里结束递归"<<endl;
}

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
    func3(a...);

}

/*
 * func3(1,2,3,4);
 *      func3(2,3,4);
 *          func3(3,4);
 *              func3(4);
                    func3(); ---- 这里结束递归
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
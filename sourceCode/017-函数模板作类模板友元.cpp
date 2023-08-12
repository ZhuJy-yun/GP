#include <iostream>
using namespace std;

//template<class T1,class T2> void func1();
//template<class T3,class T4> void func2(T3,T4);

template<class CT>
class C1{

    //friend void func1<int,double>();//特化版无参func1 作 类模板C1的 friend
    template<class T1,class T2> friend void func1();//泛化版无参 func1 作 类模板C1的 friend


    //friend void func2<int,int>(int,int);//特化版有参func2 作 类模板C1的 friend
    template<class T3,class T4> friend void func2(T3,T4);//泛化版有参 func2 作 类模板C1的 friend


    //其实编译后是个全局函数，与C1的作用域无关
    friend void func3(C1<CT> &c1){
        c1.id=789;
        cout<<c1.id<<endl;
    }

    private:
        int id;
};

template<class T1,class T2>
void func1(){
    C1<int>c1;
    c1.id=123;
    cout<<c1.id<<endl;
}

template<class T3,class T4>
void func2(T3 a,T4 b){
    C1<int>c1;
    c1.id=456;
    cout<<c1.id<<endl;
}


int main(){
    func1<int,double>();
    func1<int,int>();

    func2(1,2);// func2<int,int>(1,2);
    func2(1,2.2);

    cout<<endl;

    //如果func3 没有被调用，则编译的时候，C1类里面，不会有这个func3
    C1<int>c1;
    func3(c1);

    C1<double>c11;
    func3(c11);//这里与上面的func3 会编译出两份代码，因为参数和不一样

    return 0;
}
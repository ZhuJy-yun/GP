#include <iostream>
using namespace std;

template<class T2> class C2;
template<class T1>
class C1{
    friend C2<int>;//特化版C2作类模板C1的类友元

    template<class T3> friend class C3;//泛化版的C3作类模板C1的类友元

    friend T1;//类型参数作类模板C1的类友元

    friend class C4;//普通类作类模板C1的类友元

    private:
        int id;
};

template<class T2>
class C2{
    public:
        void func1(){
            C1<double>c1;
            c1.id=123;
            cout<<c1.id<<endl;
        }
};

template<class T3>
class C3{
public:
    void func1(){
        C1<double>c1;
        c1.id=456;
        cout<<c1.id<<endl;
    }
};

class C4{
    public:
        void func1(){
            C1<C4>c1;
            c1.id=789;
            cout<<c1.id<<endl;
        }

    void func2(){
        C1<int>c1;
        c1.id=321;
        cout<<c1.id<<endl;
    }
};

/*
 * 1 特化版的类模板作另一个类模板的类友元
 * 2 泛化版的类模板作另一个类模板的类友元
 * 3 类型参数作类模板的类友元
 * 4 普通类作模板的类友元
 * */

int main(){

    C2<int>c2;//这里必须与C1中指定的frined 类型参数一致
    c2.func1();

    C3<int>c3Int;
    c3Int.func1();
    C3<double>c3Double;
    c3Double.func1();

    C4 c4;
    c4.func1();
    c4.func2();

    return 0;
}
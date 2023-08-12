#include <iostream>
using namespace std;

template<class T1>
class C1{
public:
    C1(){
        cout<<"构造"<<endl;
    }

    //函数模板成员方法-泛化
    template<class T2>
    void func2(T2 id){
        cout<<"func2-类内实现-泛化-T2-id-"<<id<<endl;
    }

    //函数模板成员方法声明-泛化
    template<class T3>
    void func3(T3 name);

    //在类内声明一个特化版-int
    void func3(int name);

    //在类内实现一个特化版-string
    void func3(string name){
        cout<<"func3-类内实现-特化-string-name-"<<name<<endl;
    }

    //在类内实现一个特化版-共用类模板的参数T1
    void func3(T1 name){
        cout<<"func3-类内实现-特化-T1-name-"<<name<<endl;
    }

    //类中的虚函数不能用类型参数模板 ?? 为什么不能用，后面再讲
    //template<class T4>
    //virtual void func4(T4 age){}

    //正确
    virtual void func4(int age){}
    virtual void func5(T1 age){} //?这里为什么可以?  因为在实例化这个类的时候，己经指定了T1的值，编译的时候就己经有值了，而不是调用的时候

};

//函数模板成员方法-类外实现-泛化
template<class T1>
template<class T3>
void C1<T1>::func3(T3 name) {
    cout<<"func3-类外实现-泛化-T3-name-"<<name<<endl;
};

//在类外实现一个特化版-int
template<class T1>
void C1<T1>::func3(int name) {
    cout<<"func3-类外实现-特化-int-name-"<<name<<endl;
};

int main(){

    C1<double>c1;
    c1.func2(123);
    c1.func3(1.23);
    c1.func3("123");//这里的 参数并没有被自动推导为string 类型，所以没调用string 特化版，被推导成了什么类型,请大家自己用 objdump -DC>a.txt 命令反查

    string str="str";
    c1.func3(str);


    return 0;
}
#include <iostream>
using namespace std;

template<class T1>
class Father{
    public:
        void sonSay(){
            T1 &son=static_cast<T1 &>(*this); //把父类强转成子类对象
            son.say();
        }
};

class Son1:public Father<Son1>{
    public:
        void say(){
            cout<<"son1"<<endl;
        }
};


template<class T2>
class Son2:public Father<Son2<T2>>{
public:
    void say(){
        cout<<"son2"<<endl;
    }
};


/*
 * 派生类当基类的类型参数
 *
 * 子类到父类，父类再调子类
 *
 * 只是一个技巧，如果遇到或者看到，要知道是什么意思
 *
 * */


int main(){

    Son1 son1;
    son1.sonSay();

    Son2<int> son2;
    son2.sonSay();

    return 0;
}
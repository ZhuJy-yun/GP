#include <iostream>
using namespace std;

class Father{
    public:
        virtual void say(){}

        virtual ~Father(){}

};

class Son1:public Father{
    public:
        virtual void say(){
            cout<<"son1"<<endl;
        }
};

class Son2:public Father{
    public:
        virtual void say(){
            cout<<"son2"<<endl;
        }
};



class Son3{
    public:
        void say(){
            cout<<"son3"<<endl;
        }
};

class Son4{
    public:
        void say(){
            cout<<"son4"<<endl;
        }
};


template<class T1>
void func1(T1 &son){
    son.say();
}


/*
 *
 * 模板里面的多态，并不需要继承，也没有虚函数，自然也没有重载，就是类和方法
 * 但是，模板里面的多态，是在编译期间就确定了具体要调用的代码，不需要在执行的时候去处理，性能会更好,这种又称为静态多态
 *
 * 传统多态，都是父类对象指向(引用)子类，调用子类里面重载的方法，是用虚函数来完成的，要用到虚函数表，
 * 并且是在执行的时候处理，所以性能没有静态多态好，这种又称为动态多态
 *
 *
 * */

int main(){

    //父类指针指向子类对象,
    /*
    Son1 son1;
    Father *fa1=&son1;
    Father *fa2=new Son2;
    fa1->say();
    fa2->say();
    */

    /*
    //父类引用指向子类对象
    Son1 son1;
    Son2 son2;
    Father &fa1=son1;
    Father &fa2=son2;
    fa1.say();
    fa2.say();
    */

    //模板函数中的多态
    Son3 son3;
    Son4 son4;
    func1(son3);
    func1(son4);


    return 0;
}
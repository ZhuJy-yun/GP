#include <iostream>
#include<string>
using namespace std;

class C1{
public:
    C1(int a,int b){
        this->a=a;
        this->b=b;
    }
    int a;
    int b;

    C1 & operator+=(const C1 &c1){
        this->a+=c1.a;
        this->b+=c1.b;
        return *this;
    }

    C1 & operator-=(const C1 &c1){
        this->a-=c1.a;
        this->b-=c1.b;
        return *this;
    }

};


template<class T1>
struct sumType{};

template<>
struct sumType<char>{
    using type=int;
    static type initSum(){
        return 0;
    }
};

template<>
struct sumType<int>{
    using type=int64_t;
    static type initSum(){
        return 0;
    }
};

template<>
struct sumType<C1>{
    using type=C1;
    static type initSum(){
        return C1(0,0);
    }
};

/*
 *
 * 策略 - 某种算法，或实现方式，或某种规则
 *
 * 策略萃取 - 给定一个类型，萃取出一种算法或实现方式
 *
 * 其实就是用模板的方式实现一些算法，再根据类型参数调用
 *
 *
 * 软件工程
 * 类似于乐高积木，
 *
 * */


struct myAdd{

    template<class T1,class T2>
    static void algorithm(T1 &sum,const T2 &val){
         sum+=val;
     }
};

struct mySub{
    template<class T1,class T2>
    static void algorithm(T1 &sum,const T2 &val){
        sum-=val;
    }
};



template<class T1,class T2=myAdd>
auto func2(const T1 *start,const T1 *end){
    using sumT = typename sumType<T1>::type;
    sumT sum = sumType<T1>::initSum();

    for(;;){
        T2::algorithm(sum,*start);

        if(start == end){
            break;
        }
        start++;

    }
    return sum;
}



int main(){

    int a[]={1,2,3};
    int b[]={1000000000,2000000000,2000000000};
    char c[]="abc";//97，98，99
    C1 d[]{C1(1,11),C1(2,22),C1(3,33)};


    cout<<func2<int,mySub>(&a[0],&a[2])<<endl;
    //cout<<func2(&b[0],&b[2])<<endl;
    //cout<<func2(&c[0],&c[2])<<endl;


    C1 rs = func2<C1,mySub>(&d[0],&d[2]);

    cout<<rs.a<<"==="<<rs.b<<endl;
    return 0;
}
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

};


template<class T1>
struct sumType{};

template<>
struct sumType<char>{
    using type=int;
    //static const type sum=0;
    static type initSum(){
        return 0;
    }
};

template<>
struct sumType<int>{
    using type=int64_t;
    //static const type sum=0;
    static type initSum(){
        return 0;
    }
};

template<>
struct sumType<C1>{
    using type=C1;
    //static const type sum=C1(0,0);
    static type initSum(){
        return C1(0,0);
    }

};


template<class T1>
auto func2(const T1 *start,const T1 *end){
    using sumT = typename sumType<T1>::type;
    sumT sum = sumType<T1>::initSum();
    //sumT sum{};
    for(;;){
        sum +=(*start);
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


    cout<<func2(&a[0],&a[2])<<endl;
    cout<<func2(&b[0],&b[2])<<endl;
    cout<<func2(&c[0],&c[2])<<endl;

    C1 rs = func2(&d[0],&d[2]);

    cout<<rs.a<<"--"<<rs.b<<endl;

    return 0;
}
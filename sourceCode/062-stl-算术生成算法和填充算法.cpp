#include <iostream>
#include<vector>
#include<functional>
#include<algorithm>
#include<numeric>
#include<string>

using namespace std;

/*
 *
 * 算术生成算法
 * #include<numeric>
 * T accumulate(begin,end,val,func);
 *
 *
 * template<class T>T plus<T>       加法
 * template<class T>T minus<T>      减法
 * template<class T>T multiplies<T> 乘法
 * template<class T>T divides<T>    除法
 * template<class T>T modulus<T>    取模
 * template<class T>T negate<T>     取反
 *
 *
 *
 * 填充算法，容器使用前得先分配空间
 * void fill(begin,end,value);
 *
 *
 *
 * */



class C1{
public:
    C1(int id,string name){
        this->id=id;
        this->name=name;
    }
    C1(){}

    bool operator==(const C1 &a){
        return (a.id == this->id && a.name == this->name);
    }

    int id;
    string name;
};


typedef struct myPlus{

    int operator()(int a,const C1 &b){
        return a+b.id;
    }

};


void func2(){
    vector<int>v1;
    v1.resize(3);
    fill(v1.begin(),v1.end(),100);

    for(auto start = v1.begin();start != v1.end();start++){
        cout<<*start<<" ";
    }
    cout<<endl;


    vector<C1>v2;
    v2.resize(3);
    fill(v2.begin(),v2.end(),C1(100,"100"));

    for(auto start = v2.begin();start != v2.end();start++){
        cout<<(*start).id<<" "<<(*start).name<<"   ";
    }


}

void func1(){
    vector<int>v1{1,2,3};

    auto rs1= accumulate(v1.begin(),v1.end(),10); //10+1+2+3

    cout<<rs1<<endl;

    vector<C1>v2{
            C1(1,"1"),
            C1(2,"2"),
            C1(3,"2"),
    };

    auto rs2= accumulate(v2.begin(),v2.end(),0,myPlus()); //10+1+2+3
    cout<<rs2<<endl;
}


int main(){
    func2();
    return 0;
}
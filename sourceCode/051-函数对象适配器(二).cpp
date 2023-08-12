#include <iostream>
#include<functional>
#include<algorithm>
#include<vector>
using namespace std;

/*
 *
 * 谓词 bool 类型的函数对象
 *
 * not1 是构造一个与谓词结果相反的一元函数对象
 * not2 是构造一个与谓词结果相反的二元函数对象
 *
 * */

//一元谓词
typedef struct myFind:public unary_function<int,bool>{
    bool operator()(int a) const{
        return a>100;
    }
};

typedef struct mySort:public binary_function<int,int,bool>{
    bool operator()(int a,int b) const{
        return a<b;
    }
};


void func2(){
    vector<int>v1{1,11,111,2,22,222,2222,3,33,333,4,44};


    //sort(v1.begin(),v1.end(),less<int>());

    sort(v1.begin(),v1.end(),mySort());

    for(auto start = v1.begin();start != v1.end();start++){
        cout<<*start<<"--";
    }

    cout<<endl;

    //二元谓词取反
    //sort(v1.begin(),v1.end(), not2(less<int>()));
    sort(v1.begin(),v1.end(), not2(mySort()));
    for(auto start = v1.begin();start != v1.end();start++){
        cout<<*start<<"--";
    }

}

void func1(){

    vector<int>v1{1,11,111,2,22,222,2222,3,33,333,4,44};

    auto rs1 = find_if(v1.begin(),v1.end(),myFind());

    if(rs1 == v1.end()){
        cout<<"no"<<endl;
    }else{
        cout<<*rs1<<endl;
    }


    //一元谓词 取反
    auto rs2 = find_if(v1.begin(),v1.end(), not1(myFind()));

    if(rs2 == v1.end()){
        cout<<"no"<<endl;
    }else{
        cout<<*rs2<<endl;
    }



}


int main(){

    func2();

    return 0;
}
#include <iostream>
#include<functional>
#include<algorithm>
#include<numbers>
#include<vector>
using namespace std;

/*
 *
 * #include<functional>  函数对象
 * #include<algorithm>  算法
 * #include<numbers> 算法补充
 *
 * 通过迭代器来操作容器中的元素
 *
 *
 * for_each(); 遍历容器，将迭代器当参数来调用函数或函数对象，结束后返回函数对象
 * callback for_each(begin,end,callback);
 *
 *
 * transform 将指定容器区间元素搬运到另一容器中
 * 不会给目标容器分配内存，要手动预先分配好内存
 *
 *
 * operator2 transform(begin1,end1,begin2,callback);
 *
 * begin1 源容器开始迭代器
 * end1 源容器开始迭代器
 * begin2 目标容器开始迭代器
 * end2 目标容器结束迭代器
 * operator2 目标容器特定位置迭代器
 *
 *
 *
 *
 * operator3 transform(begin1,end1,begin2,begin3,callback);
 *
 * begin1 源容器开始迭代器
 * end1 源容器开始迭代器
 * bgin2 源容器开始迭代器
 * begin3 目标容器开始迭代器
 * end3 目标容器结束迭代器
 * operator3 目标容器特定位置迭代器
 *
 *
 * */

typedef struct myFunc2{
    int operator()(int a,int b){
        return a+b;
    }
};

void func3(){
    vector<int>v1{1,2,3,4,5};
    vector<int>v2{10,20,30,40,50};
    vector<int>v3;
    v3.resize(5);

    auto rs = transform(v1.begin(),v1.end(),v2.begin(),v3.begin(),myFunc2());

    for(auto start = v3.begin();start != v3.end();start++){
        cout<<*start<<"--";
    }
    cout<<endl;

    cout<<(rs == v3.end())<<endl;

}


typedef struct myFunc{
    int operator()(int a){
        return a;
    }
};

void func2(){
    vector<int>v1{1,2,3,4,5};
    vector<int>v2;
    v2.resize(v1.size());
    for(auto start = v2.begin();start != v2.end();start++){
        cout<<*start<<"--";
    }
    cout<<endl;

    auto rs = transform(v1.begin(),v1.end(),v2.begin(),myFunc());

    for(auto start = v2.begin();start != v2.end();start++){
        cout<<*start<<"--";
    }
    cout<<endl;
    //cout<<(rs == v2.end()-2)<<endl;
    /*
    for(auto start = v1.begin();start != v1.end();start++){
        cout<<*start<<"--";
    }
    cout<<endl;
    */
}


typedef struct myPrint1{
    void operator()(int a){
        cout<<a<<"--";
        sum+=a;
    }

    int sum=0;
};

void func1(){
    vector<int>v1{1,2,3,4,5};
    myPrint1 rs;
    rs = for_each(v1.begin(),v1.end(),myPrint1());

    cout<<endl<<rs.sum<<endl;
}

int main(){
    func3();
    return 0;
}
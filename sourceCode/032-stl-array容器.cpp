#include <iostream>
#include<string>
#include<array>
using namespace std;

/*
 *
 * 构造和赋值
 *
 * array<T,int n>;
 * array<T,int n>arr4(const array &arr);
 * array<T,int n>arr4({val...});
 *
 * array<T,int n>{};    c++11开始引入，给一个空值或0值，memset
 * array<T,int n>={};
 * array<T,int n>{val...};
 * array<T,int n>={const array &arr};
 * array<T,int>arr2; arr2=arr;
 * array.fill(val);
 * get<n>(&arr)=val;
 *
 * 是否为空 bool empty();   size()==0    begin() == end()
 * 元素个数 int size();
 * 最大元素个数 int max_size();
 * 返回下标处元素引用 at(n);          自动检查 n 是否在有效范围内,不是抛出 out_of_range 异常
 * 返回下标处元素引用 get<n>(&arr);   自动检查 n 是否在有效范围内,越界编译不通过
 * 返回下标处元素引用 &operator[n];   不检查越界没有异常
 * 返回首元素引用 front();
 * 返回最后一个元素引用 back();
 * 返回首元素指针 data();
 * 交换元素 swap(array &arr);
 * 比较是否相等 operator==; 必须是类型和元素个数相同的两个容器，否则编译不通过
 *
 *
 * 迭代器 - 是一种数据类型
 * begin()/end();
 * cbegin()/cend();   cbegin中的c表示const，即返回const_iterator，不允许通过迭代器修改元素。
 * rbegin()/rend();   逆向迭代器
 * crbegin()/crend(); 逆向 const 迭代器
 *
 * */

class abc{
public:
    int a=123;
};


void func3(){
    array<int,3>arr1{1,2,3};

    array<int,3>::iterator start;
    start = arr1.begin();

    array<int,3>::iterator end=arr1.end();

    while (start != end){
        cout<<start<<"--"<<*start<<endl;
        *start+=10;
        start++;
    }
    cout<<endl;
    for(auto start=arr1.cbegin();start != arr1.cend();start++){
        cout<<start<<"--"<<*start<<endl;
    }



}

void func2(){

    array<int,3>arr1{1,2,3};
    array<int,0>arr2{};
    array<int,3>arr3{1,2,3};

    //cout<<arr1.front()<<"--"<<arr1.back()<<endl;
    //cout<<*(arr1.data()+1)<<endl;

    //cout<<arr1[0]<<"--"<<arr3[0]<<endl;
    //arr1.swap(arr3);
    //cout<<arr1[0]<<"--"<<arr3[0]<<endl;

    //cout<<(arr1 == arr3)<<endl;

    //cout<<arr1.at(0)<<"--"<<get<0>(arr1)<<"--"<<arr1[10]<<endl;
    //cout<<arr1.empty()<<"--"<<arr1.size()<<"--"<<arr1.max_size()<<endl;
    //cout<<arr2.empty()<<"--"<<arr2.size()<<"--"<<arr2.max_size()<<endl;

}

void func1(){

    array<int,3>arr1;
    array<int,3>arr2{};
    array<int,3>arr3={};

    array<int,3>arr4{1,2,3};

    array<int,3>arr5(arr4);
    array<int,3>arr6({1,2,3});
    array<int,3>arr7={arr5};

    arr1 = arr4;

    arr2.fill(123);
    get<0>(arr2)=456;

    cout<<arr2[0]<<"--"<<arr2[1]<<"--"<<arr2[2]<<endl;


}



int main(){
    func3();

    return 0;
}
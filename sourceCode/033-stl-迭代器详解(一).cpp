#include <iostream>
#include<array>
#include<vector>
using namespace std;

/*
 *
 * 迭代器 - 是一种数据类型  array<int,3>::iterator iter1;  vector<int>::iterator iter2;
 * 定义一个迭代器类型的变量，用来指向容器中某个位置的元素，用此迭代器来操作容器中的元素，类似于指针
 * 用迭代器的时候，一定要保证是有效的
 * 在stl中，尽量用迭代器来操作元素，更安全，功能更强大，更方便
 *
 *
 *
 *
 * 成对出现，一个首，一个尾，在首尾间移动，来操作容器中的元素
 * begin()是指向容器首元素的迭代器
 * end()是指向容器尾元素的下一个位置，其指向的并不是一个有效元素，而是一个标志位，或者是哨兵位，无法解引用，不能读写，只能用来判断
 * 当迭代器指向end的时候，表示容器遍历完成
 *
 *
 * begin()/end();
 * cbegin()/cend();   cbegin中的c表示const，即返回const_iterator，不允许通过迭代器修改元素。
 * rbegin()/rend();   逆向迭代器
 * crbegin()/crend(); 逆向 const 迭代器
 *
 * */

void func2(){
    vector<int>v1{1,2,3};

    vector<int>::iterator start=v1.begin();
    vector<int>::iterator end=v1.end();

    while (start!=end){
        cout<<*start<<endl;
        start++;
    }

    //不管编译能不能通过，这种写法都是错误的，有点类似于野指针
    //cout<<*end<<endl;
    //*end=123;
    //cout<<*end<<endl;

}

void func1(){

    array<int,3>arr1{1,2,3};
    vector<int>v1{1,2,3};

    array<int,3>arr2;

    array<int,3>::iterator iter1;
    vector<int>::iterator iter2=v1.begin();

    iter1 = arr1.begin();
    iter1 = arr2.begin();

}


int main(){
    func2();
    return 0;
}
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
 * 迭代器与指针
 * 迭代器是仿指针的类模板，封装了原生指针，是指针概念的一种提升，提供了比指针更高级的行为
 * 迭代器很大程度上隔离了容器的底层实现，我们不需要考虑容器底层到底是啥，只需要通过迭代器提供的相对统一的接口和方法，就能操作不同类型的迭代器
 *
 * 指针可以指向函数，迭代器只能用在容器里面
 *
 *
 * 成对出现，一个首，一个尾，在首尾间移动，来操作容器中的元素
 * begin()是指向容器首元素的迭代器
 * end()是指向容器尾元素的下一个位置，其指向的并不是一个有效元素，而是一个标志位，或者是哨兵位，无法解引用，不能读写，只能用来判断
 * 当迭代器指向end的时候，表示容器遍历完成
 *
 *
 * begin()/end();
 * cbegin()/cend();   cbegin中的c表示const，即返回const_iterator，不允许通过迭代器修改元素。 用 const 修饰的容器，必须得用const 迭代器来操作
 * rbegin()/rend();   逆向迭代器
 * crbegin()/crend(); 逆向 const 迭代器
 *
 * */

class C1{
public:
    int id=123;
};

void func2(){
    vector<int>v1{1,2,3};
    vector<int>::reverse_iterator rstart=v1.rbegin();
    vector<int>::reverse_iterator rend=v1.rend();
    while (rstart!=rend){
        cout<<*rstart<<endl;
        rstart++;
    }

    C1 a;
    C1 b;
    C1 c;
    vector<C1>v2{a,b,c};
    for (vector<C1>::iterator start=v2.begin();start!=v2.end();start++) {
        cout<<(*start).id<<"--"<<start->id<<endl;

        //auto tmp = *start;
        //cout<<tmp.id<<endl;

    }



    //vector<int>::iterator start=v1.begin();
    //vector<int>::iterator end=v1.end();

    /*
    vector<int>::const_iterator cstart=v1.cbegin();
    vector<int>::const_iterator cend=v1.cend();

    while (cstart != cend){
        cout<<*cstart<<endl;
        //*cstart+=10;
        cstart++;
    }
    */
/*
    cout<<*start<<endl;//1
    start+=2;//类似于指针里面的步长
    cout<<*start<<endl;//3
    start-=2;

    while (start!=end){
        cout<<*start<<"--";
        *start +=10;
        start++;
    }

    cout<<endl;
    for (vector<int>::iterator start=v1.begin();start!=v1.end();start++) {
        cout<<*start<<"--";
    }
    */


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
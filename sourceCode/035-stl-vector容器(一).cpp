#include <iostream>
#include<array>
#include<vector>
using namespace std;

/*
 *
 * vector 是个不定长的容器，其空间大小可以动态改变，其元素的空间地址都是连续的，可以看成是一个动态数组
 * vector 每次增加元素，都要看原来的空间够不够大，如果不够，就需要进行扩容
 * 扩容规则，开辟新的空间，将原来的数据拷贝过来，并追加新元素，再将原来的空间销毁
 * 所有的连续空间的动态扩容规则，都是这样，
 *
 * */


void func1(){
    vector<int>v1{1,2,3};

    for(auto start = v1.begin();start != v1.end();start++){
        printf("%p\n",start);
    }
    v1.push_back(4);

    cout<<endl;
    for(auto start = v1.begin();start != v1.end();start++){
        printf("%p\n",start);
    }

    v1.push_back(5);
    v1.push_back(6);
    v1.push_back(7);
    v1.push_back(4);

    cout<<endl;
    for(auto start = v1.begin();start != v1.end();start++){
        printf("%p\n",start);
    }

    /*
    for(int i=1;i<11;i++){
        cout<<v1.size()<<"--"<<v1.capacity()<<endl;
        v1.push_back(i);
    }*/



    /*
    array<int,3>arr1;
    vector<int>v1{1,2,3};
    v1.push_back(4);
    v1.push_back(5);
    v1.push_back(6);


    v1.push_back(8);
    v1.push_back(8);



    arr1[0]=1;
    arr1[1]=2;
    arr1[2]=3;
    arr1[3]=4;
    */

    /*
    for (auto start = v1.begin();start!= v1.end();start++){
        cout<<*start<<endl;
    }*/




}

int main(){
    func1();
    return 0;
}
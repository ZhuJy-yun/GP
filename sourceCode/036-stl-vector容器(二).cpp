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
 * 当从中间位置删除元素时，容器会将后面的元素前移，保持内存空间的连续性，但并不会减小空间
 * 当从中间位置插入元素时，容器会将此处开始的元素后移，并将此处给到新元素，如果插入的元素数量超过容器中未使用空间，则需要开辟新空间，拇行扩容操作
 *
 * 这种扩容和删除元素的过程特别消耗资源，效率低，
 * 可以事先指定vector 的空间大小，当超过时，让其自行扩容
 *
 *
 *
 *
 * */


void func2(){

    array<int,10>arr1;

    vector<int>v2;
    cout<<v2.size()<<"--"<<v2.capacity()<<endl;
    v2.reserve(10);
    cout<<v2.size()<<"--"<<v2.capacity()<<endl;
    return;


    vector<int>v1{1,2,3,4,5,6};

    cout<<v1.size()<<"--"<<v1.capacity()<<endl;
    for(auto start = v1.begin();start != v1.end();start++){
        printf("%d--%p\n",*start,start);
    }
    cout<<endl;

    v1.erase(v1.begin()+2,v1.begin()+4);
    cout<<v1.size()<<"--"<<v1.capacity()<<endl;
    for(auto start = v1.begin();start != v1.end();start++){
        printf("%d--%p\n",*start,start);
    }

    cout<<endl;
    v1.insert(v1.begin()+2,1,111);
    cout<<v1.size()<<"--"<<v1.capacity()<<endl;
    for(auto start = v1.begin();start != v1.end();start++){
        printf("%d--%p\n",*start,start);
    }


}

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
    func2();
    return 0;
}
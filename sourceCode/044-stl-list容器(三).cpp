#include <iostream>
#include<list>
using namespace std;

/*
 *
 * 双向循环链表
 * 顺序容器（线性容器）
 * 使用者感知是顺序容器，实际上底层是链表，用迭代器来维护前进后退这种顺序
 * 双向开口,每次插入一个元素，就分配一个元素的空间，每删除一个元素，就释放该元素的内存空间
 *
 * list<T>;
 * list(begin,end);
 * list(n,elem);
 * list(const list &l);
 *
 * list<T>{}
 * list<T>={}
 * list<T>={val...}
 * list<T>={const list &l}
 *
 * size();元素个数
 * empty();是否为空
 * resize(n,elem);重置list长度--长变短就删除元素--短变长就拿新值填充
 *
 * front();返回首元素，只读取，不删除除
 * back();返回尾元素，只读取，不删除
 * push_back(elem); 在list尾部加入新节点
 * pop_back();删除最后一个元素
 * push_front(elem);在list头部加入新节点
 * pop_front();删除第一个元素
 * insert(pos,n,elem);在pos 处插入n个elem 元素，无返回值
 * insert(pos,elem);在pos 处插入elem元素，返回插入元素的位置
 * emplace(pos,elem);
 * emplace_back(elem);
 * emplace_front(elem);
 *
 *
 *
 * clear();删除所有元素
 * erase(begin,end);删除begin,end区间内的元素，返回下一个元素位置
 * erase(pos);删除pos处的元素，返回下一个数据位置
 * remove(elem);删除所有与elem相同的元素(其实就是遍历，然后拿到数据对比，如果是相等的，删除节点)
 *
 * assign(begin,end);
 * assign(n,elem);
 * list &operator=(const list &l);
 * swap(list &l);
 *
 * reverse();反转链表
 * sort();排序
 *
 *
 * 迭代器
 * begin()/end();
 * cbegin()/cend();   cbegin中的c表示const，即返回const_iterator，不允许通过迭代器修改元素。
 * rbegin()/rend();   逆向迭代器
 * crbegin()/crend(); 逆向 const 迭代器
 *
 * */


bool mySort(int a,int b){
    return a>b;
}



class C1{
public:
    C1(int id,int age){
        this->id=id;
        this->age=age;
    }
    int id;
    int age;
};

bool mySortById(C1 c1,C1 c2){
    return c1.id<c2.id;
}
bool mySortByAge(C1 c1,C1 c2){
    return c1.age<c2.age;
}

void func3(){
/*
    list<int>l1{1,2,3,4,5,6};
    l1.erase(++l1.begin());
    for(auto start = l1.begin();start != l1.end();start++){
        cout<<*start<<"--";
    }
    cout<<endl;
    l1.erase(++l1.begin(),--(l1.end()));
    for(auto start = l1.begin();start != l1.end();start++){
        cout<<*start<<"--";
    }
    cout<<endl;
    l1.clear();
    cout<<l1.size()<<endl;
    */

/*
    list<int>l2{1,2,2,3,3,3,4,4,4,4};
    l2.remove(3);
    l2.remove(4);
    for(auto start = l2.begin();start != l2.end();start++){
        cout<<*start<<"--";
    }
    cout<<endl;

    list<int>l3;
    l3.assign(l2.begin(),l2.end());
    list<int>l4;
    l4.assign(4,2);
    list<int>l5;
    l5=l4;

    for(auto start = l5.begin();start != l5.end();start++){
        cout<<*start<<"--";
    }
    */

/*
    list<int>l6{1,2,3};
    list<int>l7{111,2222,3333,444};
    for(auto start = l6.begin();start != l6.end();start++){
        cout<<*start<<"--";
    }
    l6.swap(l7);
    cout<<endl;
    for(auto start = l6.begin();start != l6.end();start++){
        cout<<*start<<"--";
    }
*/
/*
    list<int>l8{99,36,72,1024,512,7};
    l8.reverse();//链表反转，面试高频      动态数组，栈，队列，链表，树，图，堆
    for(auto start = l8.begin();start != l8.end();start++){
        cout<<*start<<"--";
    }
    cout<<endl;
    l8.sort(mySort);
    for(auto start = l8.begin();start != l8.end();start++){
        cout<<*start<<"--";
    }
    */

    list<C1>l9{C1(11,33),C1(9,76),C1(7,1024)};
    l9.sort(mySortById);
    for(auto start = l9.begin();start != l9.end();start++){
        cout<<(*start).id<<"--";
    }
    cout<<endl;
    l9.sort(mySortByAge);
    for(auto start = l9.begin();start != l9.end();start++){
        cout<<(*start).id<<"--";
    }


}


void func2(){

    list<int>l1;
    list<int>l2{1,2,3,4,5};
    //cout<<l1.size()<<"--"<<l1.empty()<<"--"<<l1.max_size()<<endl;
    //cout<<l2.size()<<"--"<<l2.empty()<<"--"<<l2.max_size()<<endl;

    /*
    for(auto start = l2.begin();start != l2.end();start++){
        cout<<*start<<"--";
    }
    l2.resize(3);
    cout<<endl;
    for(auto start = l2.begin();start != l2.end();start++){
        cout<<*start<<"--";
    }
    l2.resize(6,100);
    cout<<endl;
    for(auto start = l2.begin();start != l2.end();start++){
        cout<<*start<<"--";
    }
    */

    /*
    cout<<l2.front()<<"--"<<l2.back()<<endl;//1--5

    l2.push_front(111);
    l2.push_back(666);
    cout<<l2.front()<<"--"<<l2.back()<<endl;//111--666

    l2.pop_front();
    l2.pop_back();
    cout<<l2.front()<<"--"<<l2.back()<<endl;//1--5
    */

    for(auto start = l2.begin();start != l2.end();start++){
        cout<<*start<<"--";
    }
    cout<<endl;
    l2.insert(++l2.begin(),222);

    for(auto start = l2.begin();start != l2.end();start++){
        cout<<*start<<"--";
    }
    cout<<endl;
    l2.insert(++(++l2.begin()),2,666);
    for(auto start = l2.begin();start != l2.end();start++){
        cout<<*start<<"--";
    }

}

void func1(){

    list<int>l1;
    list<int>l2(4,2);
    list<int>l3(l2.begin(),l2.end());
    list<int>l4(l3);

    list<int>l5{};
    list<int>l6={};
    list<int>l7={1,2,3,4,5};
    list<int>l8{l7};


    for(auto start = l4.begin();start != l4.end();start++){
        cout<<*start<<"--";
    }
    cout<<endl;
    for(auto start = l8.begin();start != l8.end();start++){
        cout<<*start<<"--";
    }

}


int main(){
    func3();
    return 0;
}
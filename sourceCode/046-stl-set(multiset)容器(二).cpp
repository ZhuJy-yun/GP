#include <iostream>
#include<set>
using namespace std;

/*
 *
 * set 是关联容器，其通过键值进行排序
 * set 和 multiset 的区别是 multiset 可以有重复的键值
 * 双向迭代器
 *
 *
 * 底层是红黑树(平衡二叉树的一种)
 * 平衡二叉树(avl-tree,rb-tree,aa-tree)
 *
 * set<T>;
 * set(const set &s);
 *
 * set<T>{}
 * set<T>={}
 * set<T>={val...}
 * set<T>={const list &l}
 *
 * set &operator=(const set &s);
 * swap(set &s);
 *
 * size();元素个数
 * empty();是否为空
 *
 * insert(elem);
 * clear();
 * erase(pos);删除pos迭代器处元素，返回下一个元素迭代器
 * erase(begin,end);删除begin,end区间元素，返回下一个迭代器位置
 * erase(elem);删除容器中值为elem的元素
 *
 * find(key);查找key是否存在，存在就返回迭代器，不存在就返回end迭代器
 * int count(key);查找key的个数
 * lower_bound(elem);返回第一个大于或等于elem的元素迭代器，不存在就返回end迭代器
 * upper_bound(elem);返回第一个大于elem的元素迭代器，不存在就返回end迭代器
 * equal_range(elem);返回两个大于或等于elem元素的迭代器，用对组接收 pair<set<T>::iterator,set<T>::iterator>
 *
 *
 * */

class C1{
public:
    C1(int id,int age){
        this->id=id;
        this->age=age;
    }
    int id;
    int age;
};

typedef struct {
    bool operator()(const C1 &a,const C1 &b){
        return a.id>b.id;
    }
}sortById;

void func3(){

    set<C1,sortById>s1{C1(3,333),C1(1,11),C1(2,2),C1(44,4)};
    for(auto start = s1.begin();start != s1.end();start++){
       cout<<(*start).id<<endl;
    }
    //s1.find()

}

void func2(){

    set<int>s1{1,11,111,1111,2,22,222,3,33};
    s1.insert(4);
    s1.insert(4);//在插入之前会调用 find 查找一下，如果己存在，直接return，不会报错
    for(auto start = s1.begin();start != s1.end();start++){
        cout<<*start<<"--";
    }
    cout<<endl;
/*
    auto iter = s1.upper_bound(4);
    if(iter == s1.end()){
        cout<<"no"<<endl;
    }else{
        cout<<*iter<<endl;
    }
*/
    pair<set<int>::iterator,set<int>::iterator>rs = s1.equal_range(1112);

    auto rs1 = rs.first;
    auto rs2 = rs.second;

    if(rs1 == s1.end()){
        cout<<"no"<<endl;
    }else{
        cout<<*rs1<<endl;
    }

    if(rs2 == s1.end()){
        cout<<"no"<<endl;
    }else{
        cout<<*rs2<<endl;
    }


    /*
    auto iter = s1.find(111);
    if(iter == s1.end()){
        cout<<"没找到"<<endl;
    }else{
        cout<<*iter<<endl;
    }*/
    //cout<<s1.count(1024)<<"--"<<s1.count(111)<<endl;

    //s1.erase(3);
    //for(auto start = s1.begin();start != s1.end();start++){
    //    cout<<*start<<"--";
    //}

    /*
    cout<<endl;
    multiset<int>ms1{1,1,1};
    ms1.insert(1);
    ms1.insert(1);
    for(auto start = ms1.begin();start != ms1.end();start++){
        cout<<*start<<"--";
    }
     */


  /*


            * lower_bound(elem);返回第一个大于或等于elem的元素迭代器，不存在就返回end迭代器
            * upper_bound(elem);返回第一个大于elem的元素迭代器，不存在就返回end迭代器
            * equal_range(elem);返回两个大于或等于elem元素的迭代器，用对组接收 pair<set<T>::iterator,set<T>::iterator>
    */
}


void func1(){
    set<int>s1;
    set<int>s2{1,11,111,2,22,222};
    set<int>s3{};
    set<int>s4(s2);
    set<int>s5={s4};

    set<int>s6;
    s6=s5;

    set<int>s7{777,77};

    for(auto start = s5.begin();start != s5.end();start++){
        cout<<*start<<"--";
    }
    s5.swap(s7);
    cout<<endl;

    for(auto start = s5.begin();start != s5.end();start++){
        cout<<*start<<"--";
    }
}

int main(){

    func3();

    return 0;
}
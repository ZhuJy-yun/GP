#include <iostream>
#include<map>
using namespace std;

/*
 *
 *
 * map 是关联容器，其通过键值进行排序
 * map 和 multimap 的区别是 multimap 可以有重复的键值
 * 双向迭代器，只能自增自减
 *
 * 底层是红黑树(平衡二叉树的一种)
 *
 *
 * 所有元素都是pair(对组)，first 作为键值，second 作为实值
 * 不能通过迭代器修改map的键值，但可以修改实值
 *
 * map<T1,T2>;
 * map(const map &m);
 *
 * map<T1,T2>{}
 * map<T1,T2>={}
 * map<T1,T2>={val...}
 * map<T1,T2>={const map &m}
 *
 * map &operator=(const map &m);
 * swap(map &m);
 *
 * size();元素个数
 * empty();是否为空
 *
 *
 * insert(elem);插入元素，返回pair<iterator,bool>
 *  map<int,string>m1;
 *  m1.insert(pair<int,string>(1,"aaa"));
 *  m1.insert(map<int,string>::value_type(2,"bbb"));
 *  m1.insert(make_pair(3,"ccc"));
 *  m1[4]="ddd";
 *  pair<int,string>p1(5,"eee");
 *  m1.insert(p1);
 *
 *
 * clear();
 * erase(pos);删除pos迭代器处元素，返回下一个元素迭代器
 * erase(begin,end);删除begin,end区间元素，返回下一个迭代器位置
 * erase(elem);删除容器中key为elem的元素
 *
 * find(key);查找key是否存在，存在就返回迭代器，不存在就返回end迭代器
 * int count(key);查找key的个数
 * lower_bound(elem);返回第一个key大于或等于elem的元素迭代器，不存在就返回end迭代器
 * upper_bound(elem);返回第一个key大于elem的元素迭代器，不存在就返回end迭代器
 * equal_range(elem);返回两个key大于或等于elem元素的迭代器，用对组接收 pair<map<T1,T2>::iterator,map<T1,T2>::iterator>
 *
 *
 * 迭代器
* begin()/end();
* cbegin()/cend();   cbegin中的c表示const，即返回const_iterator，不允许通过迭代器修改元素。
* rbegin()/rend();   逆向迭代器
* crbegin()/crend(); 逆向 const 迭代器
 *
 * */

typedef struct {

    bool operator()(const int &a,const int &b) const{
        return a>b;
    }
}mySort;

class C1{
public:
    C1(int id,int age){
        this->id=id;
        this->age=age;
    }
    int id;
    int age;
};

void func3(){

    map<int,C1>m1{pair<int,C1>(222,C1(11,222))};

}

void func2(){



    map<int,string,mySort>m1;

    m1.insert(pair<int,string>(11,"aaa"));

    m1.insert(map<int,string>::value_type(2,"bbb"));

    m1.insert(make_pair(333,"ccc"));

    //pair<int,string>p1= make_pair(3,"ccc");

    m1[444]="ddd";

    pair<int,string>p1(55,"eee");
    m1.insert(p1);

    /*
    pair<map<int,string>::iterator ,bool>rs = m1.insert(pair<int,string>(555,"fff"));

    map<int,string>::iterator first = rs.first;

    cout<<rs.second<<endl;
    if(rs.second != true){
        cout<<"插入失败"<<endl;
    }else{
        cout<<first->first<<"--"<<(*first).second<<endl;
    }
    */

/*
    pair<map<int,string>::iterator,map<int,string>::iterator> rs = m1.equal_range(50);

    map<int,string>::iterator it1 = rs.first;
    map<int,string>::iterator it2 = rs.second;

    if(it1 == m1.end()){
        cout<<"no-1"<<endl;
    }else{
        cout<<it1->first<<"--"<<it1->second<<endl;
    }

    if(it2 == m1.end()){
        cout<<"no-2"<<endl;
    }else{
        cout<<it2->first<<"--"<<it2->second<<endl;
    }
*/
    //cout<<it1->first<<"--"<<it1->second<<endl;
    //cout<<it2->first<<"--"<<it2->second<<endl;
    //return;
    //for(auto start =m1.begin();start != m1.end();start++){
    for(map<int,string>::iterator start = m1.begin();start != m1.end();start++){
        //pair<int,string>tmp = *start;
        //cout<<tmp.first<<"--"<<tmp.second<<endl;

        //start->first += 10;
        //start->second="abcd";
        cout<<start->first<<"--"<<(*start).second<<endl;

    }


}

void func1(){
    map<int,string>m1;
    map<int,string>m2{pair<int,string>(1,"aa"),pair<int,string>(2,"bb")};
    map<int,string>m3(m2);
    map<int,string>m4={m2};
    m1=m4;

    for(auto start =m4.begin();start != m4.end();start++){}

}


int main(){
    //func1();
    func2();
    return 0;
}
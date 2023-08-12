#include <iostream>
#include<vector>
#include<functional>
#include<algorithm>
#include<numeric>
#include<string>

using namespace std;

/*
 *
 * #include<algorithm>
 *
 * begin1 源容器1 开始迭代器
 * end1 源容器1 结束迭代器
 * begin2 源容器2 开始迭代器
 * end2 源容器2 结束迭代器
 * begin3 目标容器开如迭代器
 * func 比较规则 默认 less
 *
 *
 *
 * 交集 源容器元素都必须是有序的，且排序规则要保持一致，目标容器使用前要分配空间
 * iterator set_intersection(begin1,end1,begin2,end2,begin3,func);
 *
 *
 * 并集 源容器元素都必须是有序的，且排序规则要保持一致，目标容器使用前要分配空间
 * iterator set_union(begin1,end1,begin2,end2,begin3,func);
 *
 *
 * 差集 源容器元素都必须是有序的，且排序规则要保持一致，目标容器使用前要分配空间
 * iterator set_difference(begin1,end1,begin2,end2,begin3,func);
 *
 *
 * */

class C1{
public:
    C1(int id,string name){
        this->id=id;
        this->name=name;
    }
    C1(){}

    int id;
    string name;
};


typedef struct myComp1:public binary_function<C1,C1,bool>{
    bool operator()(const C1 &a,const C1 &b) const{
        return a.id<b.id;
    }
};

typedef struct myComp2{
    bool operator()(const C1 &a,const C1 &b){
        return a.id>b.id;
    }
};



void func2(){
    vector<C1>v1{C1(1,"1"),C1(22,"22"),C1(33,"33"),C1(444,"444"),C1(555,"555"),C1(999,"999")};
    vector<C1>v2{C1(4,"4"),C1(33,"33"),C1(44,"44"),C1(555,"555"),C1(8888,"888")};
    vector<C1>v3;
    v3.resize(min(v1.size(),v2.size()));

    sort(v1.begin(),v1.end(), not2(myComp1()));
    sort(v2.begin(),v2.end(), not2(myComp1()));

    for(auto start = v1.begin();start != v1.end();start++){
        cout<<(*start).id<<" "<<(*start).name<<"   ";
    }
    cout<<endl;

    for(auto start = v2.begin();start != v2.end();start++){
        cout<<(*start).id<<" "<<(*start).name<<"   ";
    }
    cout<<endl<<endl;

    set_intersection(v1.begin(),v1.end(),v2.begin(),v2.end(),v3.begin(),myComp2());
    for(auto start = v3.begin();start != v3.end();start++){
        cout<<(*start).id<<" "<<(*start).name<<"   ";
    }


}

void func1(){
    vector<int>v1{1,4,2,5,3};
    vector<int>v2{9,4,7,8,6,5};
    vector<int>v3;
    v3.resize(min(v1.size(),v2.size()));

    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());

    set_intersection(v1.begin(),v1.end(),v2.begin(),v2.end(),v3.begin());
    for(auto start = v3.begin();start != v3.end();start++){
        cout<<*start<<" ";
    }



}

int main(){
    func2();
    return 0;
}
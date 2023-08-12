#include <iostream>
#include<functional>
#include<algorithm>
#include<numbers>
#include<vector>
#include<string>
using namespace std;

/*
 *
 * iterator merge(begin1,end1,begin2,end2,begin3,func);
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

typedef struct myComp1{

    bool operator()(const C1 &a,const C1 &b){
        return a.id<b.id;
    }
};


void func2(){
    vector<C1>v1{C1(1,"tom-1"),C1(2,"tom-2"),C1(3,"tom-3"),C1(4,"tom-4")};
    vector<C1>v2{C1(3,"jerry-3"),C1(4,"jerry-4"),C1(5,"jerry-5"),C1(6,"jerry-6")};
    vector<C1>v3;
    v3.resize(v1.size()+v2.size());

    merge(v1.begin(),v1.end(),v2.begin(),v2.end(),v3.begin(),myComp1());

    for(auto start = v3.begin();start != v3.end();start++){
        cout<<(*start).id<<" "<<(*start).name<<"   ";
    }

}

void func1(){

    vector<int>v1{7,3,22,50};
    vector<int>v2{4,6,17,12,44};
    vector<int>v3;
    v3.resize(v1.size()+v2.size());

    //merge(v1.begin(),v1.end(),v2.begin(),v2.end(),v3.begin());
    merge(v1.begin(),v1.end(),v2.begin(),v2.end(),v3.begin(),greater<int>());

    for(auto start = v3.begin();start != v3.end();start++){
        cout<<*start<<" ";
    }


}



int main(){
    func1();
    cout<<endl<<endl;
    //func2();
    return 0;
}
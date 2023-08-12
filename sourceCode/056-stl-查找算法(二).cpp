#include <iostream>
#include<functional>
#include<algorithm>
#include<numbers>
#include<vector>
#include<string>
using namespace std;

/*
 *
 * 查找相邻的重复元素
 * iterator adjacent_find(begin,end);
 *
 * iterator adjacent_find(begin,end,func);
 *
 *
 * 二分查找 - 此算法在无序列容器中无法使用(就是说要先sort一下)
 * bool binary_search(begin,end,val,less<T>())
 *
 *
 * */


class C1{
public:
    C1(int id,string name){
        this->id=id;
        this->name=name;
    }

    bool operator<(const C1 &a) const{

        cout<<this->id<<" "<<a.id<<endl;

        return this->id<a.id;
    }


    int id;
    string name;
};



void func2(){

    /*
    vector<int>v1{2,4,8,16,32,64,128,256,512,1024,2048};

    bool rs1 =  binary_search(v1.begin(),v1.end(),4);
    if(rs1 == true){
        cout<<"yes"<<endl;
    }else{
        cout<<"no"<<endl;
    }

    sort(v1.begin(),v1.end(),greater<int>());
    for(auto start = v1.begin();start != v1.end();start++){
        cout<<*start<<" ";
    }
    cout<<endl;
    bool rs11 =  binary_search(v1.begin(),v1.end(),4,greater<int>());
    if(rs11 == true){
        cout<<"yes"<<endl;
    }else{
        cout<<"no"<<endl;
    }
*/

    vector<C1>v2{
                C1(2,"tom-2"),
                C1(4,"tom-4"),
                C1(8,"tom-8"),
                C1(16,"tom-16"),
                C1(32,"tom-32"),
                C1(64,"tom-64"),
                C1(128,"tom-128"),
                C1(256,"tom-256"),
                C1(512,"tom-512"),
                C1(1024,"tom-1024"),
                C1(2048,"tom-2048"),
            };


    bool rs2 =  binary_search(v2.begin(),v2.end(),C1(4,"tom-4"));
    if(rs2 == true){
        cout<<"yes"<<endl;
    }else{
        cout<<"no"<<endl;
    }


}


typedef struct myFind1{

    bool operator()(const C1 &a,const C1 &b){
        return (a.id == b.id && a.name == b.name);
    }

};

void func1(){

    vector<int>v1{1,11,111,2,22,22,3,3,33,333};

    auto rs1 = adjacent_find(v1.begin(),v1.end());

    if(rs1 == v1.end()){
        cout<<"no"<<endl;
    }else{
        cout<<*rs1<<endl;
    }

    vector<C1>v2{C1(123,"tom"),C1(456,"jerry"),C1(456,"jerry")};
    auto rs2 = adjacent_find(v2.begin(),v2.end(),myFind1());

    if(rs2 == v2.end()){
        cout<<"no"<<endl;
    }else{
        cout<<(*rs2).id<<"--"<<(*rs2).name<<endl;
    }


}


int main(){
    func2();
    return 0;
}
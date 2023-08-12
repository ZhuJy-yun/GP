#include <iostream>
#include<functional>
#include<algorithm>
#include<numbers>
#include<vector>
#include<string>
using namespace std;

/*
 *
 * iterator find(begin,end,val);
 *
 *
 *
 * iterator find_if(begin,end,func);
 *
 * begin 被查找的容器的开始迭代器
 * end 被查找的容器的结束迭代器
 * func 查找条件的函数或函数对象(谓词)
 *
 * */

class C1{
public:
    C1(int id,string name){
        this->id=id;
        this->name=name;
    }

    bool operator==(const C1 &c){
        return (c.id == this->id && c.name == this->name);
    }

    int id;
    string name;

};


typedef struct myFind1{
    bool operator()(int a){
        return a == 333;
    }
};

typedef struct myFind2:public binary_function<int,int,bool>{
    bool operator()(int a,int b) const{
        return a == b;
    }
};

typedef struct myFind3{
    bool operator()(const C1 &c){
        return (c.id == 456 && c.name=="jerry");
    }
};


typedef struct myFind4:public binary_function<C1,C1,bool>{
    bool operator()(const C1 &c1,const C1 &c2) const {
        return (c1.id == c2.id && c1.name== c2.name);
    }
};


void func2(){
    vector<int>v1{11,22,33,44,55};
    //auto rs1 = find_if(v1.begin(),v1.end(),myFind1());
    auto rs1 = find_if(v1.begin(),v1.end(), bind2nd(myFind2(),333));
    if(rs1 == v1.end()){
        cout<<"no"<<endl;
    }else{
        cout<<*rs1<<endl;
    }

    vector<C1>v2{C1(123,"tom"),C1(456,"jerry")};
    //auto rs2 = find_if(v2.begin(),v2.end(),myFind3());
    auto rs2 = find_if(v2.begin(),v2.end(), bind2nd(myFind4(),C1(456,"jerry")));
    if(rs2 == v2.end()){
        cout<<"no"<<endl;
    }else{
        cout<<(*rs2).id<<"--"<<(*rs2).name<<endl;
    }

}


void func1(){

    vector<int>v1{11,22,33,44,55};
    auto rs1 = find(v1.begin(),v1.end(),333);
    if(rs1 == v1.end()){
        cout<<"no"<<endl;
    }else{
        cout<<*rs1<<endl;
    }

    vector<C1>v2{C1(123,"tom"),C1(456,"jerry")};
    auto rs2 = find(v2.begin(),v2.end(),C1(456,"jerry"));
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
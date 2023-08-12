#include <iostream>
#include<functional>
#include<algorithm>
#include<numbers>
#include<vector>
#include<string>
using namespace std;

/*
 *
 * int count(begin,end,val);
 *
 * int count_if(begin,end,func);
 *
 * */

class C1{
public:
    C1(int id,string name){
        this->id=id;
        this->name=name;
    }

    bool operator==(const C1 &a){
        return (this->id == a.id && this->name == a.name);
    }

    int id;
    string name;
};


typedef struct myFind1:public unary_function<int,bool>{

    bool operator()(int a) const{
        return a==22;
    }
};

typedef struct myFind2:public binary_function<C1,C1,bool>{
    bool operator()(const C1 &a,const C1 &b) const{
        return (a.id == b.id && a.name == b.name);
    }

};



void func2(){
    vector<int>v1{1,11,111,2,22,222,111,11,1,22,22};
    int rs1 = count_if(v1.begin(),v1.end(),myFind1());
    cout<<rs1<<endl;

    int rs11 = count_if(v1.begin(),v1.end(), not1(myFind1()));
    cout<<rs11<<endl;

    vector<C1>v2{C1(123,"tom"),C1(456,"jerry"),C1(456,"jerry"),C1(456,"jerry")};
    int rs2 = count_if(v2.begin(),v2.end(), bind2nd(myFind2(),C1(456,"jerry")));
    cout<<rs2<<endl;


}


void func1(){
    vector<int>v1{1,11,111,2,22,222,111,11,1};
    int rs1 = count(v1.begin(),v1.end(),22);
    cout<<rs1<<endl;

    vector<C1>v2{C1(123,"tom"),C1(456,"jerry"),C1(456,"jerry"),C1(456,"jerry")};
    int rs2 = count(v2.begin(),v2.end(),C1(456,"jerry"));
    cout<<rs2<<endl;
}


int main(){
    func2();
    return 0;
}
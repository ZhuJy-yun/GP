#include <iostream>
#include<vector>
#include<functional>
#include<algorithm>
#include<string>
#include<random>
using namespace std;

/*
 *
 * 洗牌算法
 *
 * void random_shuffle(begin,end);
 *
 * void shuffle(begin,end,func);
 *
 *
 * */

typedef struct  myRand{
    int operator ()(int i){
        return rand()%i;
    }
};

class C1{
public:
    C1(int id,string name){
        this->id=id;
        this->name=name;
    }

    int id;
    string name;
};

void func2(){
    vector<int>v1{1,2,3,4,5};
    random_device rd;
    shuffle(v1.begin(),v1.end(),std::default_random_engine(rd()));
    for(auto start = v1.begin();start != v1.end();start++){
        cout<<*start<<" ";
    }

    cout<<endl;
    vector<C1>v2{C1(1,"11"),C1(2,"22"),C1(3,"33"),C1(4,"44"),C1(5,"55")};

    shuffle(v2.begin(),v2.end(),default_random_engine(rd()));
    for(auto start = v2.begin();start != v2.end();start++){
        cout<<(*start).id<<" "<<(*start).name<<"   ";
    }

}


void func1(){

    srand((unsigned int)time(NULL));//随机数种子

    vector<int>v1{1,2,3,4,5};
    random_shuffle(v1.begin(),v1.end(),myRand());

    for(auto start = v1.begin();start != v1.end();start++){
        cout<<*start<<" ";
    }

    cout<<endl;
    vector<C1>v2{C1(1,"11"),C1(2,"22"),C1(3,"33"),C1(4,"44"),C1(5,"55")};

    random_shuffle(v2.begin(),v2.end(),myRand());

    for(auto start = v2.begin();start != v2.end();start++){
        cout<<(*start).id<<" "<<(*start).name<<"   ";
    }


}


int main(){
    func2();
    return 0;
}
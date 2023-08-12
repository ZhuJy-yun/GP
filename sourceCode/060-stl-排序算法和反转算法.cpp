#include <iostream>
#include<vector>
#include<functional>
#include<algorithm>
#include<string>

using namespace std;

/*
 *
 * void sort(begin,end,func);
 *
 * void reverse(begin,end);
 *
 *
 * */



class C1{
public:
    C1(int id,string name){
        this->id=id;
        this->name=name;
    }
    int id;
    string name;
};


//二元谓词
typedef struct mySort1:public binary_function<C1,C1,bool>{
    bool operator()(const C1 &a,const C1 &b)const{
        return a.id<b.id;
    }
};

void func2(){

    vector<int>v1{1,11,111,2,22,222};
    reverse(v1.begin(),v1.end());
    for(auto start = v1.begin();start != v1.end();start++){
        cout<<*start<<" ";
    }

    cout<<endl;


    vector<C1>v2{
            C1(1,"1"),
            C1(11,"11"),
            C1(111,"111"),
            C1(2,"22"),
            C1(22,"22"),
            C1(222,"222")
    };

    reverse(v2.begin(),v2.end());

    //sort(v2.begin(),v2.end(), not2(mySort1()));
    for(auto start = v2.begin();start != v2.end();start++){
        cout<<(*start).id<<" "<<(*start).name<<"   ";
    }

}


void func1(){

    vector<int>v1{1,11,111,2,22,222};
    sort(v1.begin(),v1.end(),greater<int>());
    for(auto start = v1.begin();start != v1.end();start++){
        cout<<*start<<" ";
    }

    cout<<endl;


    vector<C1>v2{
        C1(1,"1"),
        C1(11,"11"),
        C1(111,"111"),
        C1(2,"22"),
        C1(22,"22"),
        C1(222,"222")

    };

    sort(v2.begin(),v2.end(),mySort1());

    //sort(v2.begin(),v2.end(), not2(mySort1()));
    for(auto start = v2.begin();start != v2.end();start++){
        cout<<(*start).id<<" "<<(*start).name<<"   ";
    }


}



int main(){
    func2();
    return 0;
}
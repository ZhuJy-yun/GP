#include <iostream>
#include<string>
using namespace std;

/*
 *
 * 是一个结构体模板，有两个公有的成员，first 和 second
 * 主要用来处理 k-v 这种数据结构
 *
 * pair<T,T>;
 * pair<T,T>(const pair<T,T> &p);
 *
 * pair<T,T>(val,val);
 *
 * pair<T,T>{};
 * pair<T,T>{val,val};
 * pair<T,T>{const pair<T,T> &p};
 *
 *
 * p.first=val;
 * p.second=val;
 *
 * p = make_pair(val,val);
 *
 *
 * 这种写法只能是 0/1 因为只有两个成员
 * get<0>(p);  get<0>(p)=val;
 * get<1>(p);
 *
 * get<0>(p)=val;
 * get<1>(p)=val;
 *
 *
 * swap(pair<T,T> &p);
 *
 *
 *  123=>"tom";
 *  456=>"jerry";
 *
 *  "tom"=>123;
 *  "jerry"=>456;
 *
 * */

int main(){

    pair<int,string>p1;

    pair<int,string>p2(123,"tom");
    pair<int,string>p3(p2);

    pair<int,string>p4{};
    pair<int,string>p5{456,"jerry"};
    pair<int,string>p6{p5};

    p1=p6;

    cout<<p6.first<<"--"<<p6.second<<endl;

    p6.first=789;
    p6.second="TOM";


    cout<<p6.first<<"--"<<p6.second<<endl;

    pair<int,string>p7;
    p7= make_pair(123,"tom");
    cout<<p7.first<<"--"<<p7.second<<endl;

    /*
    cout<<get<0>(p6)<<endl;
    cout<<get<1>(p6)<<endl;

    get<0>(p6)=789;
    get<1>(p6)="JERRY";

    cout<<get<0>(p6)<<endl;
    cout<<get<1>(p6)<<endl;
    */
    //cout<<get<2>(p6)<<endl;


    return 0;

}
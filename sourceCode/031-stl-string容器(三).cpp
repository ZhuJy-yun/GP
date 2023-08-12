#include <iostream>
#include<string>
using namespace std;

/*
 *
* 查找和替换--常量string::npos
 *
 * int find(const string &str,int pos=0);
 * int find(const char *p,int pos=0);
 * int find(const char *p,int pos,int n);   从pos 处找 char *p 中前 n 个字符第一次出现的位置
 * int find(const char c,int pos=0);
 *
 * int rfind(const string &str,int pos=npos);  查找str 最后一次出现的位置，从pos 处开始
 * int rfind(const char *p,int pos=npos);
 * int rfind(const char *p,int pos,int n);
 * int rfind(const char c,int pos=npos);
 *
 *
    str1.find_first_of();
    str1.find_last_of();
    str1.find_first_not_of();
    str1.find_last_not_of();
 *
 *
 *
 *
 * string &replace(int pos,int n,const string &str);//替换从pos 开始的n个字符为字符串str
 * string &replace(int pos,int n,const char *p);//替换从pos 开始的n个字符为字符串p

 * */

void func1(){

    string str1="axyzbcd1234abcdbc";
    string str2="BCD";
    cout<<str1<<endl;
    str1.replace(1,2,"BCD");
    cout<<str1<<endl;

    /*
    str1.find_first_of();
    str1.find_last_of();
    str1.find_first_not_of();
    str1.find_last_not_of();
    */
    //cout<<str1.rfind(str2,10)<<endl;
    //cout<<str1.rfind("bcxyz",4,2)<<endl;

    //cout<<string::npos<<endl;//看作是string 里面的一个常量，用来表示没找到

    /*
    if(str1.find("123") == string::npos){
        cout<<"找不到"<<endl;
    }else{
        cout<<"找到了"<<endl;
    }*/


    //cout<<str1.find("bcxy",2,2)<<endl;//表示在str1 从0位置开始，去找bcxy 中的前两个字符首次出现的位置

}


int main(){
    func1();

    return 0;
}
#include <iostream>
#include<string>
using namespace std;

/*
 * 是否为空 bool empty();  字节长度 int size(); int length();
 *
 * 获取  越界处理方式不一样
 * char &operator[n];    没有异常
 * char &at(n);         抛出异常，中止程序
 *
 * for(auto c:str1){ }
 *
 *
 * 拼接
 * string &operator+=(const char *p);
 * string &operator+=(const string &str);
 * string &operator+=(const char c);
 * string &append(const char *p);
 * string &append(const char *p, int n);
 * string &append(const string &str);
 * string &append(const string &str,int start,int n);
 * string &append(int n, char c);
 *
 *  * 比较
 * int compare(const string &str);
 * int compare(const char *p);
 *
 * 插入和删除
 * string &insert(int pos,const char *p);
 * string &insert(int pos,const string &str);
 *
 * string &erase(int pos,int n);//从pos处删除个字符
 *
 * string &clear(); 清空
 *
 * 截取子串
 * string substr(int pos=0,int n);
 *
 */

void func4(){
    string str1="abc";
    string str2="XYZ";

    str1.insert(0,"ABC");
    cout<<str1<<endl;

    str1.insert(3,str2);
    cout<<str1<<endl;

    str1.erase(3,3);
    cout<<str1<<endl;


    str2=str1.substr(0,5);
    cout<<str2<<endl;

    str2.clear();
    cout<<str2<<endl;

}

void func3(){
    string str1="abc";
    string str2="abc";
    const char *p="abc";

    cout<<str1.compare(str2)<<endl;
    cout<<str1.compare("abc")<<endl;
    cout<<str1.compare(p)<<endl;
    cout<<string(p).compare(str1)<<endl;

    cout<<(str1=="abc")<<endl;
    cout<<(p=="abc")<<endl;
    cout<<(p==str1)<<endl;



}

void func2(){


    string str1="abc";
    string str2="123";

    str1.append("xyz");
    cout<<str1<<endl;

    str1.append("ABCD",2);
    cout<<str1<<endl;

    str1.append(str2);
    cout<<str1<<endl;

    str1.append(str2,1,2);
    cout<<str1<<endl;

    str1.append(2,'C');
    cout<<str1<<endl;

    /*
    str1+="xyz";
    cout<<str1<<endl;
    str1+=str2;
    cout<<str1<<endl;
    str1+='W';
    cout<<str1<<endl;
    */
}

void func1(){

    string str1;
    //cout<<str1.empty()<<"--"<<str1.length()<<"--"<<str1.size()<<endl;

    str1="abcd";
    //cout<<str1.empty()<<"--"<<str1.length()<<"--"<<str1.size()<<endl;

    //cout<<str1.at(100)<<endl;
    //cout<<str1[100]<<endl;
    //cout<<"endl"<<endl;

    for(int i=0;i<str1.length();i++){
        cout<<str1[i]<<"--";
    }
    cout<<endl;
    for(auto &c:str1){
        cout<<c<<"--";
        c=toupper(c);
    }
    cout<<endl;
    cout<<str1<<endl;

}


int main(){
    func4();
    return 0;
}
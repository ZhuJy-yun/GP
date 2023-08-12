#include <iostream>
#include<string>
using namespace std;


//string 不是c语言里面的标准数据类型，是stl 库里面的一个类模板的封装，要引头文件

/*
 *
 * 构造
 * string
 * string(const char *p);
 * string(const string &str);
 * string(int n,char c);
 *
 *
 * 赋值
 * string &operator=(const char *p);
 * string &operator=(const string &str);
 * string &operator=(char c);
 *
 * string &assign(const char *p);
 * string &assign(const char *p,int n);
 * string &assign(const string &str);
 * string &assign(int n char c);
 * string &assign(const string &str,int start,int n);
 *
 *
 * c++风格字符串与c风格字符串转换
 *
 *
 * */


void func3(){

    const char *p="abcd";
    string str=string(p);//c风格转c++风格
    cout<<str<<endl;

    const char *p2=str.c_str();//c++风格转c风格

    cout<<p2<<endl;//这里不用解引用


}

void func2(){

    string str1;
    str1.assign("abcd");
    string str2;
    str2.assign("abcd",3);

    string str3;
    str3.assign(str1);

    string str4;
    str4.assign(4,'a');

    string str5;
    str5.assign(str1,1,2);

    cout<<str1<<"--"<<str2<<"--"<<str3<<"--"<<str4<<"--"<<str5<<endl;


    /*
    string str1;
    str1="abcd";
    string str2;
    str2=str1;
    string str3;
    str3='a';
    cout<<str1<<"-"<<str2<<"--"<<str3<<endl;
    */

}

void func1(){
    string str1;
    string str2("abcd");
    string str3(str2);
    string str4(3,'a');

    cout<<str1<<"--"<<str2<<"--"<<str3<<"--"<<str4<<endl;

}

int main(){

    //func1();
    //func2();
    func3();
    return 0;
}
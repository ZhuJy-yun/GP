#include <iostream>
using namespace std;

template<class T>
T funcT1(T a, T b){
    return a+b;
}

/*
 *  objdump -DC a.out>c1.txt  将二进制文件以可读的方式导出（反编译）
 *  win dumpbin /all abc.obj>abc.txt
 *
 *
 *  实例化
 * int funcT1<int>(int, int)
 * double funcT1<double>(double, double)
 *
 * 返回值类型 模板名<具体类型>(参数类型)
 *
 *
 * 如果函数定义完了，但是没有调用，编译器会优化掉，同理，如果一个参数没有被使用，也会被编译器优化
 *
 * */

int main(){

    int a=1;
    int b=2;
    double c=1.1;
    double d=2.2;

    cout<<funcT1(a,b)<<endl;    // 42   <int funcT1<int>(int, int)>:
    cout<<funcT1(c,d)<<endl;    //91    <double funcT1<double>(double, double)>:
    //cout<<funcT1<int>(c,d)<<endl;

    return 0;
}
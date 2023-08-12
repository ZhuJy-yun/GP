#include <iostream>
#include<string>
using namespace std;


/*
 *
 * 返回左值引用的运算一般有 赋值=,取特定索引[],解引用&,前置自增自减运算++i 这些，我们可以将一个左值引用绑定到这些运算的返回值上
 *
 * 返回非引用类型的运算一般有  算术+-* /,关系,位,后置自增自减运算i++ 这些，返回的都是右值，可以用右值引用或 const 左值引用绑定
 *
 * 不管是左值引用还是右值引用，其本身也是左值，还是可以被左值引用绑定
 *
 * 所有的变量，都要看成是左值，都可以被左值引用来绑定（虽然有时候当作右值来使用）
 *
 * 函数里面的参数，都要看成左值
 *
 *
 * */

//++i, i++
void func1(){

    int i=123;

    //++i 左值-可以用左值引用绑定
/*
    int &b=++i;//先++ 再返回  i(取地址)=i(取值123)+1; int &b=i;

    printf("%d-%d--%p-%p\n",i,b,&i,&b);

    //左值可以被赋值
    (++i)=456;

    printf("%d-%d--%p-%p\n",i,b,&i,&b);
    */


    //i++ 右值-可以被右值引用接收
    int &&c=i++;//int tmp=i;i=i+1;int &&c=tmp;   tmp 临时变量 -- 临时变量是右值  且有新的内存地址
    printf("%d-%d--%p-%p\n",i,c,&i,&c);


}

void func2(){

    int a=123;
    int &b=a;//左值引用 变量b本身也是左值
    int &c=b;//还是能被左值引用

    int &&e = 456;//右值引用 变量本身e 也是左值
    int &f=e; //还是能被左值引用

    //int &&g=b;

}

void func4(int a,int &b,int &&c){

}


//左值转右值-c++11新引入
//std::move()  左值转右值，没有移动的意思
void func5(){
    int a=123;
    int &b=a;

    /*
    //int &&c=a;
    int &&c=std::move(a);

    printf("%d-%d-%d---%p-%p-%p\n",a,b,c,&a,&b,&c);

    c=456;
    printf("%d-%d-%d---%p-%p-%p\n",a,b,c,&a,&b,&c);
    */

    /*
    int &&d=789;
    //int &&e=d;
    int &&e=std::move(d);
    printf("%d-%d---%p-%p\n",d,e,&d,&e);
    e=123;
    printf("%d-%d---%p-%p\n",d,e,&d,&e);
*/

    /*
    int f=a;
    int g=std::move(a);
    printf("%d-%d-%d---%p-%p-%p\n",a,f,g,&a,&f,&g);
*/

    string h="abc";
    string i=h;
    //string g=std::move(h);//string g = std::move(string h) 之后  h里面的数据没有了 不是移走了
                            //std::move 只是把左值转右值 但是加上 string g= 则是触发了string里面的移动构造，然后 h 里面的值被干掉了
    string g;
    std::move(h);

    printf("%s-%s-%s===%p-%p-%p\n",h.c_str(),i.c_str(),g.c_str(),&h,&i,&g);


}


int main(){

    //int x=123;
    //func4(x,x,123);

    //func2();
    func5();

    return 0;
}
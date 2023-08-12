#include <iostream>
#include<stack>
#include<vector>
#include<deque>
using namespace std;

/*
 * 线性容器，但只是看起来是，其底层是用 deque 封装的
 * 单向开口，先进后出
 * 不提供迭代器，自然也没有遍历，也没有按位置操作
 * 只能操作栈顶元素，当前栈顶元素失效或被替换后，有会有新的栈顶元素产生
 *
 * stack<T>;
 * stack(const dequen &s);
 *
 * stack<T>{}
 * stack<T>={}
 * stack<T>={val...} 不支持这种写法
 * stack<T>={const stack &s}
 *
 * stack<T>&operator=(const stack &s);
 *
 *
 * size();元素个数
 * empty(); 是否为空
 * top();返回栈顶元素，不删除，相当于读取，如果是空栈，会报错
 * push(val); 向栈顶追加元素，压栈，操作成功后，当前元素将成为新的栈顶元素
 * pop();删除栈顶元素，出栈，操作成功后，会更新栈顶元素,如果没有元素可出栈，会报错
 * emplace(val);向栈顶追加元素，压栈，可自动生成临时对象，操作成功后，当前元素将成为新的栈顶元素  c++11
 *
 * swap(stack &s); 交换空间
 * */


class C1{
    public:
        C1(int id){
            this->id=id;
        }
        int id;
};

void func4(){


    stack<C1>s1;
    s1.push(C1(1));
    s1.push(C1(2));
    s1.emplace(3);
    s1.emplace(4);
    //s1.emplace(C1(3));
    //s1.emplace(C1(4));

    int size = s1.size();
    for(int i=0;i<size;i++){
        C1 tmp = s1.top();
        cout<<tmp.id<<"--"<<endl;
        s1.pop();
    }


}


void func3(){

    stack<int>s1;
    stack<int>s2;
    s2.push(1);
    s2.push(2);
    s2.push(3);
    s2.emplace(4);

    cout<<s2.top()<<endl;
    //s2.pop();

    //cout<<s2.top()<<endl;



}

void func2(){
    stack<int>s1{};
    stack<int>s2={};
    s2.push(1);
    s2.push(2);
    s2.push(3);
    //stack<int>s3{1,2,3};
    //stack<int>s4={1,2,3};
    stack<int>s5={s2};

    stack<int>s6;
    s6=s5;






}


void func1(){
    stack<int>s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    stack<int>s2(s1);

    stack<int>s3;
    cout<<s2.empty()<<"--"<<s2.size()<<endl;
    cout<<s3.empty()<<"--"<<s3.size()<<endl;

}



int main(){
    func4();
    return 0;
}
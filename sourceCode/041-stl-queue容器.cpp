#include <iostream>
#include<queue>
using namespace std;
/*
 * 线性容器，但只是看起来是，其底层是用 deque 封装的，也可以用list 来实现
 * 双向开口，但是每端只提供单一功能，一端进，一端出，先进先出
 * 不提供迭代器，自然也没有遍历，也没有按位置操作
 * 只提供入队出队操作
 *
 * queue<T>;
 * queue(const queue &q);
 *
 * queue<T>{}
 * queue<T>={}
 * queue<T>={val...} 不支持这种写法
 * queue<T>={const queue &q}
 *
 * queue<T>&operator=(const queue &q);
 *
 * push(val); 向队尾插入元素，入队，会更新队尾元素
 * emplace(val);向队尾插入元素，入队，可自动生成临时对象  c++11
 * pop();从队首删除元素，无返回值，会更新队首元素，如果容器没有数据，会报错
 * back();返回队尾元素，只读取，不删除
 * front();返回队首元素，只读取，不删除，如果容器没有数据，会报错
 *
 * size();元素个数
 * empty(); 是否为空
 * swap(queue &s); 交换空间
 *
 * */


void func2(){
    queue<int>q1;
    q1.push(1);
    q1.push(2);
    q1.push(3);

    cout<<q1.back()<<endl;
    cout<<q1.back()<<endl;
    /*
    int size = q1.size();
    for(int i=0;i<size;i++){
        cout<<q1.front()<<endl;
        q1.pop();
    }
    */
    queue<int>q2;
    //q2.front();
    //q2.pop();


}

void func1(){
    queue<int>q1;

    //cout<<q1.size()<<"--"<<q1.empty()<<endl;

    q1.push(1);
    q1.push(2);
    q1.push(3);
    queue<int>q2(q1);

    //cout<<q2.size()<<"--"<<q2.empty()<<endl;

    queue<int>q3{};
    queue<int>q4={};
    //queue<int>q5{1,2,3};

    queue<int>q6{q2};

    queue<int>q7;
    q7=q2;



}


int main(){

    func2();

    return 0;
}




#include <iostream>
#include<array>
#include<vector>
using namespace std;


/*
 *
 * 构造和赋值
 *
 * vector<T>;
 * vector<T>(v.begin(),v.end());
 * vector<T>(n,elem);
 * vector<T>(const vector &vec);
 *
 * vector<T>{}
 * vector<T>={}
 * vector<T>={val...}
 * vector<T>={const vector &vec}
 * assign(begin,end);
 * assign(n,elem);//不给elem，默认是0值或空值
 * vector<T>&operator=(const vector &vec);
 * swap(vec);  交换       size()和  capacity() 都会交换,  其实是交换指针，只能在相同数据类型的vector 之间交换
 *
 *
 * size();元素个数
 * empty(); 是否为空
 * capacity();容器容量
 * resize(int n,elem);重新指定长度，如果增加元素个数，则以默认值填充，如果减少元素长度，则超出长度的元素会被删除，但占用的空间不会释放
 * reserve(int n);预留n个元素长度，预留位置不初始化，元素不可访问
 *
 * 返回下标处元素引用 at(n);          自动检查 n 是否在有效范围内,不是抛出 out_of_range 异常
 * 返回下标处元素引用 &operator[n];   不检查越界没有异常
 * 返回首元素引用 front();            v.front()=123;
 * 返回最后一个元素引用 back();        v.back()=456;
 *
 * insert(const_iterator pos,int n,elem); // 向pos处插入n 个 值为elem的元素
 * push_back(elem);//尾部插入元素
 * pop_back(); 尾部删除元素，无返回值，不会改变容量
 * erase(const_iterator start,const_iterator end)；//删除迭代器start -- end 之间的元素
 * erase(const_iterator pos);//删除迭代器指向的元素
 * clear();删除容器中所有元素，不会改变容量
 *
 * 迭代器
 *
 * */

void func3(){
    vector<int>v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    cout<<v1.size()<<"--"<<v1.capacity()<<"--"<<v1.back()<<endl;
    v1.pop_back();
    cout<<v1.size()<<"--"<<v1.capacity()<<"--"<<v1.back()<<endl;
    v1.clear();
    cout<<v1.size()<<"--"<<v1.capacity()<<"--"<<v1.back()<<endl;



    /*
    cout<<v1.size()<<"--"<<v1.capacity()<<endl;
    v1.reserve(5);
    cout<<v1.size()<<"--"<<v1.capacity()<<endl;
    cout<<endl<<endl;
    cout<<v1.front()<<"--"<<v1.back()<<endl;

    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    cout<<v1.front()<<"--"<<v1.back()<<endl;
    v1.front()=123;
    v1.back()=456;
    cout<<v1.front()<<"--"<<v1.back()<<endl;
    */
}

void func2(){
    vector<int>v1;
    //cout<<v1.empty()<<"--"<<v1.size()<<"--"<<v1.capacity()<<endl;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    //cout<<v1.empty()<<"--"<<v1.size()<<"--"<<v1.capacity()<<endl;
/*
    v1.resize(10,100);//小变大，原空间不够，则需要扩容
    cout<<v1.size()<<"--"<<v1.capacity()<<endl;
    for(auto start = v1.begin();start != v1.end();start++){
        cout<<*start<<"--";
    }

    cout<<endl;
    v1.resize(2);//大变小，会删除多余的元素，但不会缩减空间
    cout<<v1.size()<<"--"<<v1.capacity()<<endl;
    for(auto start = v1.begin();start != v1.end();start++){
        cout<<*start<<"--";
    }
    */



}

void func1(){

    vector<int>v1;
    vector<int>v2(4,2);
    vector<int>v3(v2.begin(),v2.end());
    vector<int>v4(v3);


    vector<int>v5{1,2,3,4};
    vector<int>v6={v5};

    vector<int>v7;
    v7.assign(v6.begin(),v6.end());

    vector<int>v8;
    v8.assign(3,1);

    vector<int>v9;
    v9=v8;

    vector<int>v11{1,2,3};
    vector<int>v12{11,22};
    cout<<v11.size()<<"--"<<v11.capacity()<<endl;
    cout<<v12.size()<<"--"<<v12.capacity()<<endl;
    v11.swap(v12);
    cout<<endl<<endl;
    cout<<v11.size()<<"--"<<v11.capacity()<<endl;
    cout<<v12.size()<<"--"<<v12.capacity()<<endl;


    //* swap(vec);  交换       size()和  capacity() 都会交换,  其实是交换指针，只能在相同数据类型的vector 之间交换


}

int main(){
    func3();

    return 0;
}
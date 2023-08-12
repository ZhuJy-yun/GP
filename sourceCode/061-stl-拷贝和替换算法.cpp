#include <iostream>
#include<vector>
#include<functional>
#include<algorithm>
#include<string>

using namespace std;

/*
 *
 * 将begin1,end1 范围内的元素cp到容器2中，从begin2处开始填充，目标容器使用前要先确定空间
 *
 * iterator copy(begin1,end1,begin2);
 *
 *
 * 将begin,end 范围内的，等于oldVal的元素，替换成newVal
 *
 * void replace(begin,end,oldVal,newVal);
 *
 *
 *
 * 将begin,end 范围内的，符合func条件的元素，替换成newVal
 *
 * void replace_if(begin,end,func,newVal);
 *
 *
 *
 * 将begin1,end1 范围内的元素cp到容器2中，从begin2处开始填充，当源容器中的元素等于oldVal时，目标容器中用newVal替换，目标容器使用前要先确定空间
 * iterator replace_copy(begin1,end1,begin2,oldVal,newVal);
 *
 *
 *
 * 将begin1,end1 范围内的元素cp到容器2中，从begin2处开始填充，当源容器中的元素符合条件func 时，目标容器中用newVal替换，目标容器使用前要先确定空间
 * iterator replace_copy_if(begin1,end1,begin2,func,newVal);
 *
 *
 *
 * 交换元素
 * void swap(v1,v2);
 *
 * */
class C1{
public:
    C1(int id,string name){
        this->id=id;
        this->name=name;
    }
    C1(){}

    bool operator==(const C1 &a){
        return (a.id == this->id && a.name == this->name);
    }

    int id;
    string name;
};


typedef struct myComp1:public binary_function<int,int,bool>{
    bool operator()(int a,int b)const{
        return a<b;
    }
};

void func5(){
    vector<int>v1{1,2,3};
    vector<int>v2{4,5,6};

    auto start1 = v1.begin();
    auto start2 = v2.begin();


    printf("%p--%d\n",start1,*start1);
    printf("%p--%d\n",start2,*start2);


    swap(v1,v2);


    cout<<endl;

    auto start3 = v1.begin();
    auto start4 = v2.begin();
    printf("%p--%d\n",start3,*start3);
    printf("%p--%d\n",start4,*start4);

}

void func4(){

    vector<int>v1{1,2,3,4,5,1,1};
    vector<int>v2;
    v2.resize(v1.size());

    replace_copy(v1.begin(),v1.end(),v2.begin(),1,100);

    for(auto start = v2.begin();start != v2.end();start++){
        cout<<*start<<" ";
    }
    cout<<endl;


    vector<C1>v3{
            C1(1,"1"),
            C1(11,"11"),
            C1(111,"111"),
            C1(1,"1"),
            C1(1,"1"),
    };
    vector<C1>v4;
    v4.resize(v3.size());

    replace_copy(v3.begin(),v3.end(),v4.begin(),C1(1,"1"),C1(100,"100"));
    for(auto start = v4.begin();start != v4.end();start++){
        cout<<(*start).id<<" "<<(*start).name<<"   ";
    }


}

void func3(){
    vector<int>v1{1,2,3,4,5,1,1};
    //replace_if(v1.begin(),v1.end(),myComp1(),100);
    replace_if(v1.begin(),v1.end(), bind2nd(myComp1(),3),100);
    for(auto start = v1.begin();start != v1.end();start++){
        cout<<*start<<" ";
    }
    cout<<endl;

}

void func2(){
    vector<int>v1{1,2,1,1,5};
    replace(v1.begin(),v1.end(),1,100);
    for(auto start = v1.begin();start != v1.end();start++){
        cout<<*start<<" ";
    }
    cout<<endl;

    vector<C1>v2{
            C1(1,"1"),
            C1(11,"11"),
            C1(111,"111"),
            C1(12,"1"),
            C1(12,"1"),
    };
    replace(v2.begin(),v2.end(),C1(1,"1"),C1(100,"100"));
    for(auto start = v2.begin();start != v2.end();start++){
        cout<<(*start).id<<" "<<(*start).name<<"   ";
    }

}

void func1(){

    vector<int>v1{1,2,3,4,5};
    vector<int>v2;
    v2.resize(v1.size());
    auto rs1 = copy(v1.begin()+2,v1.end(),v2.begin());

    for(auto start = v2.begin();start != v2.end();start++){
        cout<<*start<<" ";
    }
    cout<<endl<<(rs1 == v2.end())<<endl;

    vector<C1>v3{
            C1(1,"1"),
            C1(11,"11"),
            C1(111,"111")
    };
    vector<C1>v4;
    v4.resize(v3.size());

    copy(v3.begin(),v3.end(),v4.begin());
    for(auto start = v4.begin();start != v4.end();start++){
        cout<<(*start).id<<" "<<(*start).name<<"   ";
    }
}



int main(){
    func5();
    return 0;
}
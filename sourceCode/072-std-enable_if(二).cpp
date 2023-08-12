#include <iostream>
#include<string>
using namespace std;

class C1{

    public:
        template<
                class T1,
                //class T2= typename enable_if< is_convertible<T1,string>::value >::type
                class T2 = std::enable_if_t<std::is_convertible<T1,string>::value>    //当 T1 为 string 的时候，给T2 赋值为void  T2 是个工具人，只要有值就行
              >
        C1(T1 && name){
            this->name= std::forward<T1>(name);
            cout<<"构造函数模板"<<endl;
        }

        C1(const C1 &c1){
            this->name=c1.name;
            cout<<"拷贝构造函数"<<endl;
        }

    string name;
};


/*
 *
 * bool rs = std::is_convertible<T1,T2>::value
 * 判断T1类型 是否能隐式的转为T2类型，返回值是bool
 *
 * */

int main(){

    string name="tom";

    //C1 c1;
    //c1.C11<string,void>(std::move(name));//这里己经不是万能引用了，这里是右值引用

    //c1.C11(name);
    //c1.C11(c1);


    C1 c1(name);//构造函数模板
    C1 c2(c1);//拷贝构造函数


    bool rs = std::is_convertible<double ,int>::value;
    cout<<(rs == true)<<endl;


    return 0;
}
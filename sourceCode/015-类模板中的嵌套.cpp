#include <iostream>
using namespace std;

template<class T1>
class C1{

    public:
        void func1(){
            cout<<"C1-T1-func1"<<endl;
        }

   //C1泛化--C2类内泛化
    template<class T2>
    class C2{
        public:
            void func1(){
                cout<<"C1-T1---C2-T2-func1"<<endl;
            }
    };

    //C1泛化--C2类内特化
    template<>
    class C2<int>{
    public:
        void func1(){
            cout<<"C1-T1---C2-int-func1"<<endl;
        }
    };

};

//C1-特化-double---C2 泛化
template<>
class C1<double>{
    public:
        template<class T2>
        class C2{
            public:
            void func1(){
                cout<<"C1-double---C2-T2-func1"<<endl;
            }
        };
};

//C1-特化-float---C2-特化-float

template<>
template<>
class C1<float>::C2<float>{
    public:
    void func1(){
        cout<<"C1-float---C2-float-func1"<<endl;
    }
};

/*
template<>
class C1<float>{
public:
    template<>
    class C2<float>{
    public:
        void func1(){
            cout<<"C1-float---C2-float-func1"<<endl;
        }
    };
};
*/


int main(){

    C1<int>::C2<double>C1T1C2T2;
    C1T1C2T2.func1();

    C1<int>::C2<int>C1T1C2Int;
    C1T1C2Int.func1();

    C1<double>::C2<int>C1DoubleC2T2;
    C1DoubleC2T2.func1();

    C1<float>::C2<float>C1FloatC2Float;
    C1FloatC2Float.func1();

    return 0;
}



/*
template<class T1>
class C1{
    public:
        void func1(){
            cout<<"C1-T1-func1"<<endl;
        }
        template<class T33>
        void func3(){
            C3<T33>c33;
            c33.func1();
        }

    template<class T2>
    class C2{
        public:
            void func1(){
                cout<<"C1-T1-C2-T2-func1"<<endl;
            }
    };

private:
    template<class T3>
    class C3{
    public:
        void func1(){
            cout<<"C1-T1-C3-T3-func1"<<endl;
        }
    };

};
*/

/*
int main(){

    C1<int>c1;
    c1.func1();
    c1.func3<int>();

    C1<double>::C2<int>c2;
    c2.func1();

    return 0;
}
 */
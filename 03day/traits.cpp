#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <array>
#include <cxxabi.h>
using namespace std;

// 固定萃取
namespace TraitsFixedTraits
{
    template<typename T, typename U>
    T func1(U *begin,U *end)
    {
        T Sum = {};
        for (; ;)
        {
            Sum += *begin;
            if (begin == end)
            {
                break;
            }
            begin++;
        }
        return Sum;
    }

    template <typename T>
    T func1(T *begin, T *end)
    {
        T Sum = {};
        for (;;)
        {
            Sum += *begin;
            if (begin == end)
            {
                break;
            }
            begin++;
        }
        return Sum;
    }

    template <typename T>
    struct SumType;

    template <>
    struct SumType<int>
    {
        using type = int64_t;
    };

    template <>
    struct SumType<char>
    {
        using type = int;
    };

    template <typename T>
    auto func2(T *begin, T *end)
    {
        using SumT = typename SumType<T>::type;
        SumT Sum{};
        for (;;)
        {
            Sum += *begin;
            if (begin == end)
            {
                break;
            }
            begin++;
        }
        return Sum;
    }

    template<typename T>
    struct GetType
    {
        using type = typename T::value_type;
    };

    template <typename T, size_t size>
    struct GetType<array<T,size>>
    {
        using type = T;
    };

    template <typename T>
    using TYPE = typename GetType<T>::type;

    template <typename T>
    void func3(const T &t)
    {
        cout << abi::__cxa_demangle(typeid(TYPE<T>).name(), 0, 0, 0) << endl;
    }

    void test()
    {
        int a[] = {1, 2, 3};
        int b[] = {1000000000, 2000000000, 2000000000};
        char c[] = "abc"; // 97，98，99

        cout << func1(&a[0], &a[2]) << endl;
        cout << func1(&b[0], &b[2]) << endl; // 越界
        cout << func1(&c[0], &c[2]) << endl; // 越界

        cout << endl;
        cout << func1<int,int>(&a[0], &a[2]) << endl;
        cout << func1<int64_t,int>(&b[0], &b[2]) << endl; // 越界
        cout << func1<int,char>(&c[0], &c[2]) << endl; // 越界

        cout << endl;
        cout << func2(&a[0], &a[2]) << endl;
        cout << func2(&b[0], &b[2]) << endl;
        cout << func2(&c[0], &c[2]) << endl;

        vector<int> v1{};
        list<double> l1{};
        array<string, 10> a1{};
        func3(v1);
        func3(l1);
        func3(a1);
    }
} // namespace TraitsFixedTraits


// 退化技术的演示
namespace TraitsDecay
{
    template <typename T>
    struct clearConst
    {
        using type = T;
    };

    template <typename T>
    struct clearConst<T const>
    {
        using type = T;
    };

    template <typename T>
    struct clearReference
    {
        using type = T;
    };

    template <typename T>
    struct clearReference<T &>
    {
        using type = T;
    };

    // 退化左值引用
    template <typename T>
    struct clearReference<T &&>
    {
        using type = T;
    };

    template <class T1>
    struct myDecay : clearReference<clearConst<T1>>::type
    {
    };

    // 数组转化为指针
    template <typename T, size_t size>
    struct myDecay<T[size]>
    {
        using type = T*;
    };

    //函数转化为指针
    template <typename T, class...args>
    struct myDecay<T(args...)>
    {
        using type = T(*)(args...);
    };

    int func1(int a, int b)
    {
        cout << "func1--" << a << "---" << b << endl;
        return a + b;
    }

    void test()
    {
        int a = 123;
        const int b = 123;
        int &c = a;
        int &&d = 123;
        const int &e = b;

        // 去掉const
        cout << is_same<clearConst<decltype(b)>::type, int>::value << endl;

        // 去掉引用
        cout << is_same<clearReference<decltype(c)>::type, int>::value << endl;
        cout << is_same<clearReference<decltype(d)>::type, int>::value << endl;

        cout << endl;

        // 组合--得先去掉引用，再去掉const
        cout << is_same<clearConst<clearReference<decltype(e)>::type>::type, int>::value << endl;

        int f[4]{};
        const int g[5]{};

        cout << abi::__cxa_demangle(typeid(decltype(d)).name(), 0, 0, 0) << endl;
        cout << abi::__cxa_demangle(typeid(decay<decltype(d)>::type).name(), 0, 0, 0) << endl;
        cout << abi::__cxa_demangle(typeid(myDecay<decltype(d)>::type).name(), 0, 0, 0) << endl;

        cout << "----------------" << endl;

        cout << abi::__cxa_demangle(typeid(decltype(e)).name(), 0, 0, 0) << endl;
        cout << abi::__cxa_demangle(typeid(decay<decltype(e)>::type).name(), 0, 0, 0) << endl;
        cout << abi::__cxa_demangle(typeid(myDecay<decltype(e)>::type).name(), 0, 0, 0) << endl;

        cout << "----------------" << endl;
        cout << abi::__cxa_demangle(typeid(decltype(f)).name(), 0, 0, 0) << endl;
        cout << abi::__cxa_demangle(typeid(decay<decltype(f)>::type).name(), 0, 0, 0) << endl;
        cout << abi::__cxa_demangle(typeid(myDecay<decltype(f)>::type).name(), 0, 0, 0) << endl;

        cout << "----------------" << endl;
        cout << abi::__cxa_demangle(typeid(decltype(g)).name(), 0, 0, 0) << endl;
        cout << abi::__cxa_demangle(typeid(decay<decltype(g)>::type).name(), 0, 0, 0) << endl;
        cout << abi::__cxa_demangle(typeid(myDecay<decltype(g)>::type).name(), 0, 0, 0) << endl;
        cout << "----------------" << endl;

        cout << abi::__cxa_demangle(typeid(decltype(func1)).name(), 0, 0, 0) << endl;
        cout << abi::__cxa_demangle(typeid(decay<decltype(func1)>::type).name(), 0, 0, 0) << endl;
        cout << abi::__cxa_demangle(typeid(myDecay<decltype(func1)>::type).name(), 0, 0, 0) << endl;
    }
} // namespace TraitsDecay

// 值萃取
namespace TraitsValueTraits
{
    class C1
    {
    private:
        /* data */
        int m_a;
        int m_b;

    public:
        explicit C1(const int &a = 0, const int &b = 0) : m_a(a), m_b(b){};
        int GetA() const
        {
            return m_a;
        }
        int GetB() const
        {
            return m_b;
        }
        ~C1(){};

        C1 &operator+=(const C1 &c)
        {
            m_a += c.m_a;
            m_b += c.m_b;
            return *this;
        }

        friend ostream &operator<<(ostream &os, const C1 &c)
        {
            os << c.GetA() << " -- " << c.GetB() << endl;
            return os;
        }
    };

    template <typename T>
    struct SumType
    {
        using type = T;
    };

    template <typename T>
    T func2(T *begin, T *end)
    {
        T Sum{};
        for (;;)
        {
            Sum += *begin;
            if (begin == end)
            {
                break;
            }
            begin++;
        }
        return Sum;
    }

    void test()
    {
        C1 d[]{C1(1, 11), C1(2, 22), C1(3, 33)};
        cout << func2<C1>(&d[0], &d[2]);
    }

} // namespace TraitsValueTraits

// 类型萃取
namespace TraitsTypedTraits
{
    template <class T1, class T2>
    struct myIsSame
    {
        using type = bool;
        static const type value = false;
    };

    template <class T1>
    struct myIsSame<T1, T1>
    {
        using type = bool;
        static const type value = true;
    };

    int func1()
    {

        int a = 123;
        int b = 456;
        double c = 7.89;

        const int e = 789;

        cout << is_same<decltype(a), decltype(b)>::value << endl;
        cout << is_same<decltype(a), decltype(c)>::value << endl;
        cout << endl;

        cout << myIsSame<decltype(a), decltype(b)>::value << endl;
        cout << myIsSame<decltype(a), decltype(c)>::value << endl;

        return 0;
    }
} // namespace TraitsTypedTraits



int main()
{
    // TraitsFixedTraits::test();
    // TraitsDecay::test();
    // TraitsValueTraits::test();
    TraitsTypedTraits::func1();
}

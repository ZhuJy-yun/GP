#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <array>
#include <cxxabi.h>
using namespace std;

// 固定萃取
namespace TraiarsFixedTraits
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
} // namespace TraiarsFixedTraits


// 退化技术的演示
namespace TraiarsClear
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

    void test()
    {
        int a = 123;
        const int b = 123;
        int &c = a;
        int &&d = 123;
        const int &e = b;

        // 去掉const
        cout << is_same<TraiarsClear::clearConst<decltype(b)>::type, int>::value << endl;

        // 去掉引用
        cout << is_same<TraiarsClear::clearReference<decltype(c)>::type, int>::value << endl;
        cout << is_same<TraiarsClear::clearReference<decltype(d)>::type, int>::value << endl;

        cout << endl;

        // 组合--得先去掉引用，再去掉const
        cout << is_same<TraiarsClear::clearConst<TraiarsClear::clearReference<decltype(e)>::type>::type, int>::value << endl;
    }
} // namespace TraiarsClear


int main()
{
    TraiarsFixedTraits::test();
}

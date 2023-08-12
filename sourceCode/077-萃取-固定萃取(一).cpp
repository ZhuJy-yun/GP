#include <iostream>
#include <string>
using namespace std;

template <class T1, class T2>
T1 func1(const T2 *start, const T2 *end)
{
    T1 sum{};
    for (;;)
    {
        sum += (*start);
        if (start == end)
        {
            break;
        }
        start++;
    }
    return sum;
}

template <class T1>
struct sumType
{
};

template <>
struct sumType<char>
{
    using type = int;
};

template <>
struct sumType<int>
{
    using type = int64_t;
};

//........

template <class T1>
auto func2(const T1 *start, const T1 *end)
{
    using sumT = typename sumType<T1>::type;
    sumT sum{};
    for (;;)
    {
        sum += (*start);
        if (start == end)
        {
            break;
        }
        start++;
    }
    return sum;
}

int main()
{

    int a[] = {1, 2, 3};
    int b[] = {1000000000, 2000000000, 2000000000};
    char c[] = "abc"; // 97，98，99

    cout << func1<int>(&a[0], &a[2]) << endl;
    cout << func1<int>(&b[0], &b[2]) << endl; // 越界
    cout << func1<int64_t>(&b[0], &b[2]) << endl;
    cout << func1<int>(&c[0], &c[2]) << endl;     // 越界

    cout << endl;
    cout << func2(&a[0], &a[2]) << endl;
    cout << func2(&b[0], &b[2]) << endl;
    cout << func2(&c[0], &c[2]) << endl;

    return 0;
}

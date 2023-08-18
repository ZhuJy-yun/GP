#include <functional>
#include <iostream>
#include <string>
#include <vector>
#include <list>
using namespace std;
using namespace std::placeholders;

namespace AdaptersBind
{
    double my_divide(double x, double y)
    {
        return x / y;
    }
    struct myPair
    {
        double a,b;
        double mutiplay() { return a / b; }
        /* data */
    };

    void func()
    {
        auto fn_five = bind(my_divide, 10, 2); // returns 10 / 2
        cout << fn_five() << endl;

        auto fn_half = bind(my_divide, _1, 2); // ∥returns x / 2
        cout << fn_half(10) << endl;

        auto fn_invert = bind(my_divide, _2, _1); // returns y/x
        cout << fn_invert(10, 2) << endl;

        auto fn_rounding = bind<int>(my_divide, _1, _2); // returns int(x/y)
        cout << fn_rounding(10, 3) << endl;

        //  binding members : MyPair ten two
        myPair ten_two{10, 2};

        auto bound_memfn = bind(&myPair::mutiplay, _1); // returns x.multiply()
        cout << bound_memfn(ten_two) << endl;

        auto bound_memdata = bind(&myPair::a, ten_two); // returns ten_two.a
        cout << bound_memdata() << endl;

        auto bound_memdata2 = bind(&myPair::b, _1); // returns x.a
        cout << bound_memdata2(ten_two) << endl;

        vector<int> v{15, 37, 94, 58, 73, 58, 28, 98};
        int n = count_if(v.cbegin(), v.cend(), not1(bind2nd(less<int>(), 50)));
        cout << "n=" << n << endl;
        // // 5
        auto fn_ = bind(less<int>(), _1, 50);
        cout << count_if(v.cbegin(), v.cend(), fn_) << endl;
        cout << count_if(v.begin(), v.end(), bind(less<int>(), _1, 50)) << endl; // 3
    }
} // namespace AdaptersBind

// namespace ReverseIterator
// {
//     template <class Iterator>
//     class reverse_iterator
//     {
//     protected:
//         Iterator current;//對應之正向迭代器
//     public:
//     // 逆向迭代器的5種associated types都和其對應之正向迭代器相同
//         typedef typename iterator_traits<Iterator>::iterator_category iterator_category;
//         typedef typename iterator_traits<Iterator>::value_type value_type;
//         typedef typename iterator_traits<Iterator>::difference_type difference_type;
//         typedef typename iterator_traits<Iterator>::reference reference;
//         typedef typename iterator_traits<Iterator>::pointer pointer;
//         typedef Iterator iterator_type;          // 代表正向迭代器
//         typedef reverse_iterator<Iterator> self; // 代表逆向迭代器
//     public:
//         explicit reverse_iterator(iterator_type x) : current(x) {}
//         reverse_iterator(const self &x) : current(x.current) {}
//         iterator_type base() const { return current; } // ∥取出對應的正向迭代器

//         reference operator*() const
//         {
//             Iterator tmp = current;
//             return *--tmp;
//         }
//         // 以上爲關鍵所在。對逆向迭代器取值，就是
//         // 將「對應之正向迭代器」退一一位取值。
//         pointer operator->() const { return &(operator*()); }
//         // 意義同上。
//         // 前進變成後退，後退孌成前進
//         self &operator++()
//         {
//             --current;
//             return *this;
//         }
//         self &operator--()
//         {
//             ++current;
//             return *this;
//         }
//         self operator+(difference_type n) const { return self(current - n); }
//         self operator-(difference_type n) const { return self(current + n); }
//     };
// } // namespace ReverseIterator

// namespace AdaptersInserter
// {
//     // 這個adapter將iterator的赋值(assign) 操作改變爲
//     // 安插(insert) 操作，並將iterator右移一個位置。如此便可
//     // 讓user連續執行「表面上assign而實傺上insert」的行爲
//     template <class Container>
//     class insert_iterator
//     {
//     protected:
//         Container *container; // 底層容器
//         typename Container::iterator iter;

//     public:
//         typedef output_iterator_tag iterator_category; // ∥注意類型
//         insert_iterator(Container &x, typename Container::iterator i)
//             : container(&x), iter(i) {}
//         insert_iterator<Container> &
//         operator=(const typename Container::value_type &value)
//         {
//             iter = container->insert(iter, value); // ∥關键：轉調用insert()
//             ++iter;                                // ∥令insert iterator永遠随其target贴身移動
//             return *this;
//         }
//     };

    // template <class InputIterator, class OutputIterator>
    // OutputIterator
    // copy(InputIterator first,
    //      InputIterator last,
    //      OutputIterator result)
    // {
    //     while (first != last)
    //     {
    //         *result = *first;
    //         ++result;
    //         ++first;
    //     }
    //     return result;
    // }
    // 輔助函式，幫助user使用insert iterator.
//     template <class Container, class Iterator>
//     inline insert_iterator<Container>
//     myinserter(Container &x, Iterator i)
//     {
//         typedef typename Container::iterator iter;
//         return insert_iterator<Container>(x, iter(i));
//     }

//     void func()
//     {
//         list<int> foo, bar;
//         for (int i = 1; i <= 5; i++)
//         {
//             foo.push_back(i);
//             bar.push_back(i * 10);
//             list<int>::iterator it = foo.begin();
//             advance(it, 3);
//             copy(bar.begin(), bar.end(), myinserter(foo, it));
//         }
//     }
// }

// namespace Ostream
// {
//     template <class T, class charT = char, class traits = char_traits<charT>>
//     class ostream_iterator:
//     public iterator<output_iterator_tag, void, void, void, void>
//     {
//         basic_ostream<charT, traits> *out_stream;
//         const charT *delim;

//     public:
//         typedef charT char_type;
//         typedef traits traits_type;
//         typedef basic_ostream<charT, traits> ostream_type;

//         ostream_iterator(ostream_type &s) : out_stream(&s), delim(0) {}
//         ostream_iterator(ostream_type &s, const charT *delimiter) : out_stream(&s), delim(delimiter) {}
//         ostream_iterator(const ostream_iterator<T, charT, traits> &x) : out_stream(x.out_stream), delim(x.delim) {}

//         ~ostream_iterator(){}

//         ostream_iterator<T, charT, traits> &operator=(const T &value)
//         {
//             *out_stream << value;
//             if (delim != 0)
//                 *out_stream << delim;
//             return *this;
//         }
//         ostream_iterator<T, charT, traits> &operator*() { return *this; }
//         ostream_iterator<T, charT, traits> &operator++() { return *this; }
//         ostream_iterator<T, charT, traits> &operator++(int) { return *this; }
//     };
// }

// namespace Istream
// {
//     template <class T, class charT = char, class traits = char_traits<charT>, class Distance = ptrdiff_t>
//     class istream_iterator : public iterator<input_iterator_tag, T, Distance, const T *, const T &>
//     {
//         basic_istream<charT, traits> *in_stream;
//         T *value;

//     public:
//         typedef charT char_type;
//         typedef traits traits_type;
//         typedef basic_istream<charT, traits> istream_type;

//         istream_iterator() : in_stream(0) {}
//         istream_iterator(istream_type &s) : in_stream(&s) {}
//         istream_iterator(const istream_iterator<T, charT, traits, Distance> &x) : in_stream(x.in_stream), value(x.value) {}

//         ~istream_iterator() {}
//         const T &operator*() const { return value; }
//         const T *operator->() const { return &value; }

//         istream_iterator<T, charT, traits, Distance> &operator++()
//         {
//             if (in_stream && !(in_stream >> value))
//             {
//                 in_stream = 0;
//             }
//             return *this;
//         }
//         istream_iterator<T, charT, traits, Distance> &operator++(int)
//         {
//             istream_iterator<T, charT, traits, Distance> tmp = *this;
//             ++*this;
//             return *this;
//         }
//     };
// }

namespace MyTuple
{
    template<typename T>
    class complex
    {
    private:
        /* data */
        T A_;
        T B_;
    public:
    };
    void func()
    {
        complex<double> c;

        cout << sizeof(c) << endl;

        tuple<string, int, int, complex<double>> t;
        cout << sizeof(t) << endl;
    }
}

int main()
{
    MyTuple::func();
}

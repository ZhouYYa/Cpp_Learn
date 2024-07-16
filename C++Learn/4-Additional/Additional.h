#pragma once
#include <iostream>
#include <string>
class Additional
{
};

class Account {
public:
    static double m_rate;
    static void set_rate(const double& x) { m_rate = x; }
};

double Account::m_rate = 8.0;

// Singleton

//class A {
//public:
//    static A& getInstance();
//private:
//
//    A();
//    a(const a& rhs);
//    static A a;
//};


class A {
public:
    static A& getInstance();

private:
    A();
    A(const A& rhs);
};

A& A::getInstance()
{
    static A a;
    return a;
}


// Template 
// class template
template<typename T>
class complex
{
public:
    complex(T r = 0, T i = 0)
        :re(r), im(i)
    {}
    T real() {};
    T imag() {};
private:
    T re, im;
};  
complex<double> c1, c2;

// function template 
template <class T>
const T& min(const T& a, const T& b)
{
    return b < a ? a : b;
}

// member template 成员模板
template <class T1, class T2>
struct pair {
    typedef T1 first_type;
    typedef T2 second_type;
    T1 first;
    T2 second;

    pair()
        : first(T1()), second(T2()) {}
    pair(const T1& a, const T2& b)
        :first(a), second(b) {}


    template<class U1, class U2>
    pair(const pair<U1, U2>& p)
        : first(p.first), second(p.second) {}
};

// specialization，模板特化
template <class key> 
struct hash {};

template<>
struct hash<char> {
    size_t operator() (char x) const { return x; }
};

template<>
struct hash<int> {
    size_t operator() (int x) const { return x; }
};

template<>
struct hash<long> {
    size_t operator() (long x) const { return x; }
};

//std::cout << hash<long>() (1000);

// partial specialization, 模板偏特化 -- 个数的偏
template<typename T, typename Alloc=...>
class vector
{
    //...
};
template<typename Alloc = ...>
class vector<bool, Alloc>  // T特化为bool
{
    //...
}
//partial specialization, 模板偏特化 -- 范围的偏
template <typename T>
class C
{
    //...
};
template <typename U>
class C<U*>
{
    //...
};

//C<string> obj1;
//C<string*> obj2;

// template template parameter, 模板模板参数
template<typename T,
        template<typename T>
           class Container
        >
class XCls
{
private:
    constainer<T> c;
public:
    /......
};
template<typename T>
using Lst = list<T, allocator<T>>;
XCls<string, list> mylst1;
XCls<string, Lst> mylst2;

// class中不可以定义namespace，但是可以再声明定义class
namespace std
{
    //...
}

int main()
{
    Account::set_rate(5.0);

    Account a;
    a.set_rate(7.0);
    //std::cout << "" << std::endl;
}


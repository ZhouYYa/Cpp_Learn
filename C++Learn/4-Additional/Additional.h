#pragma once
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

namespace std
{
    //...
}

int main()
{
    Account::set_rate(5.0);

    Account a;
    a.set_rate(7.0);
}


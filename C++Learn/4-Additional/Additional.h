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

// member template ³ÉÔ±Ä£°å
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


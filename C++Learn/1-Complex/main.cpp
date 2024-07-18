#include <iostream>

namespace testRef{
    int test(int& a, int& b) 
    {
        int c = a + b;
        return c;
    }

    int test2(int a, int b)
    {
        int c = a + b;
        return c;
    }

    int test3(int&& a, int&& b)
    {
        int c = a + b;
        return c;
    }

    int& test4(const int& a, const int& b)
    {
        int c = a + b;
        return c;
    }

    void test()
    {
        //int sum = test(1, 2);   // error, because right value can not be non-const variable referenced.
        int sum2 = test2(1, 2);
        int sum3 = test3(1, 2);
        int sum4 = test4(1, 2);

        int a = 1;
        int b = 2;
        int sum = test(a, b);
        sum2 = test2(a, b);
        //sum3 = test3(a, b);
        sum4 = test4(a, b);
    }
}


namespace testReturnRef {
    class testP
    {
    public:
        testP(const int& _m, const int& _n) :m(_m), n(_n) {};
    public:
        int m;
        int n;
    };
    // 传递者无需知道接收者是以reference形式接受。
    inline testP& test(const testP* a, const testP& b)
    {
        testP* c;
        c->m = a->m + b.m;
        c->n = a->n + b.n;
        
        return *c;
    }
    // 这种类型的函数绝对不可以return by reference, 因为返回的必定是个local object。
    // typename()  -> temp object(临时对象）
    inline testP 
        operator + (const testP& a, const testP& b)
    {
        return testP(a.m + a.m, a.n + a.n);
    }


}
#ifndef  __COMPLEX__
#define  __COMPLEX__
namespace complex {
    class complex {

    public:
        complex(const double& re, const double& im) : real(re), imag(im) {};

        // const 只能用在成员函数，不能用于全局函数
        // 当成员函数的const版本和非const版本同时存在时，
        // const对象调用const函数，非const对象调用非const
        // const 成员函数不必考虑COW(copy on wirte).
        double GetReal() const { return this->real; }
        double GetImag() const { return this->imag; }


        complex& operator += (const complex& r)
        {
            this->imag += r.imag;
            this->real += r.real;
            return *this;
        }

    private:
        double real;
        double imag;
    };

    inline complex operator + (const complex & l, const complex & r);
    
    complex operator + (const complex& l, const complex& r)
    {
        return complex(l.GetReal() + r.GetReal(), l.GetImag() + r.GetImag());
    }
}

#endif // ! __COMPLEX__


int main()
{
    testRef::test();
    
    return 0;
}
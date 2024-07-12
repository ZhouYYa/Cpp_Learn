#pragma once
#include <iostream>
class Fraction
{
public:
    Fraction(int num, int den = 1)
        :m_numerator(num), m_denominator(den) {}
    operator double() const {
        return (double)(m_numerator / m_denominator);
    }
private:
    int m_numerator;
    int m_denominator;
};

Fraction f(3, 4);
double d = 4 + f;

// non-explicit-one-argument ctor
class Fraction {
public:
    Fraction(int num, int den = 1)
        :m_numerator(num), m_denominator(den) {}
    Fraction operator+(const Fraction& f) {
        return Fraction(...);
    }
private:
    int m_numerator;
    int m_denominator;
};
Fraction f(3, 5);
Fraction d2 = f + 4;  // ����non-explicit ctor��4תΪFraction(4, 1)
                        // Ȼ�����operator+;

class Fraction {
public:
    Fraction(int num, int den = 1)
        :m_numerator(num), m_denominator(den) {}
    operator double() const {
        return (double)(m_numerator / m_denominator);
    }
    Fraction operator+(const Fraction& f) {
        return Fraction(...);
    }
private:
    int m_numerator;
    int m_denominator;
};
Fraction f(3, 5);
Fraction d2 = f + 4;  // Error ambiguous

// explicit-one-argument ctor
class Fraction {
public:
    explicit Fraction(int num, int den = 1)
        :m_numerator(num), m_denominator(den) {}
    operator double() const {
        return (double)(m_numerator / m_denominator);
    }
    Fraction operator+(const Fraction& f) {
        return Fraction(...);
    }
private:
    int m_numerator;
    int m_denominator;
};
Fraction f(3, 5);
Fraction d2 = f + 4;  // Error conversion from double to Fraction request
// explicit ���ڷ�ֹ��ʽת��

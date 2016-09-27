#include <iostream>

#include "fraction.h"

void Fraction::print()
{
    std::cout << m_numerator << '/' << m_denominator << '\n';
}

void Fraction::reduce()
{
    int gcd = Fraction::gcd(m_numerator, m_denominator);
    m_numerator /= gcd;
    m_denominator /= gcd;
}

Fraction operator*(const Fraction &f1, const Fraction &f2)
{
    return Fraction(
        f1.m_numerator*f2.m_numerator,
        f1.m_denominator*f2.m_denominator
    );
}

Fraction operator*(const Fraction &f1, int value)
{
    return Fraction(
        f1.m_numerator*value,
        f1.m_denominator
    );
}

Fraction operator*(int value, const Fraction &f2)
{
    return Fraction(
        value*f2.m_numerator,
        f2.m_denominator
    );
}

int Fraction::gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

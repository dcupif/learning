#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

class Fraction
{
private:
    int m_numerator;
    int m_denominator;

public:
    Fraction(int numerator = 0, int denominator = 1)
        : m_numerator{numerator}, m_denominator{denominator}
    {
        reduce();
    }

    void print();
    void reduce();

    static int gcd(int a, int b);

    friend Fraction operator*(const Fraction &f1, const Fraction &f2);
    friend Fraction operator*(const Fraction &f, int value);
    friend Fraction operator*(int value, const Fraction &f);

    friend std::ostream& operator<<(std::ostream &out, const Fraction &f);
    friend std::istream& operator>>(std::istream &in, Fraction &f);
};

#endif

#ifndef FRACTION_H
#define FRACTION_H

class Fraction
{
private:
    int m_numerator = 0;
    int m_denominator = 1;

public:
    Fraction(int numerator, int denominator = 1)
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
};

#endif

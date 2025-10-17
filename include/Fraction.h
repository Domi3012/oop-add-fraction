#ifndef FRACTION_H
#define FRACTION_H

#include <string>
#include <expected>

class Fraction {
private:
    int _numerator;
    int _denominator;

    Fraction();
    Fraction(int num, int den);
    Fraction(int num);

    int gcd(int a, int b);
    void reduce();
public:
    std::expected<Fraction, std::string> createFraction(int num, int den);
    std::expected<Fraction, std::string> createFraction(int num);
    std::string toString();
    Fraction operator+(const Fraction &other);
};



#endif
#ifndef FRACTION_H
#define FRACTION_H

#include <string>
#include <expected>
#include <format> // for std::format()
#include <cmath> // for std::abs() inside gcd()

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
    static std::expected<Fraction, std::string> createFraction(int num, int den);
    static std::expected<Fraction, std::string> createFraction(int num);
    static std::expected<Fraction, std::string> createFraction();
    std::string toString();
    Fraction operator+(const Fraction &other);
};



#endif
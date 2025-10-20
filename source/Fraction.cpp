#include "../include/Fraction.h"
#include <string>
#include <expected>
#include <format> // for std::format()
#include <cmath> // for std::abs() inside gcd()

int Fraction::gcd(int a, int b) {
    a = std::abs(a);
    b = std::abs(b);
    while (b != 0) {
        int temp = b;
        b = a % temp;
        a = temp;
    }
    return a;
}

void Fraction::reduce() {
    int g = gcd(_numerator, _denominator);
    _numerator /= g;
    _denominator /= g;

    if (_denominator < 0) { // Xử lí để mẫu luôn là số dương
        _numerator *= -1;
        _denominator *= -1;
    }
}

std::expected<Fraction, std::string> Fraction::createFraction(int num, int den) {
    if (den == 0) {
        return std::unexpected("Mẫu số không được là số 0");
    }
    return Fraction(num, den);
}

Fraction::Fraction(int num, int den) : _numerator(num), _denominator(den) {
    reduce();
}

std::expected<Fraction, std::string> Fraction::createFraction(int num) {
    return Fraction(num);
}

Fraction::Fraction(int num) : _numerator(num), _denominator(1) {}

std::expected<Fraction, std::string> Fraction::createFraction() {
    return Fraction();
}

Fraction::Fraction() : _numerator(0), _denominator(1) {}

std::string Fraction::toString() {
    // Case 1: Complete Fraction:
    if (_numerator % _denominator == 0) {
        return std::format("{0}", _numerator / _denominator);
    }

    // Case 2: Mixed Fraction:
    if (abs(_numerator) > _denominator) {
        int whole = _numerator / _denominator; // Phần nguyên của phân số
        int remainder = abs(_numerator) % _denominator; // Phần dư sau phần nguyên
        return std::format("{0} {1}/{2}", whole, remainder, _denominator);
    }

    // Case 3: Normal Fraction:
    return std::format("{0}/{1}", _numerator, _denominator);
}

Fraction Fraction::operator+(const Fraction& other) {
    int a1 = this->_numerator, b1 = this->_denominator; // frac1 = a1/b1
    int a2 = other._numerator, b2 = other._denominator; // frac2 = a2/b2
    Fraction result(
        a1*b2/gcd(b1, b2) + a2*b1/gcd(b1, b2),
        b1*b2/gcd(b1, b2)
    );
    result.reduce();
    return result;
}
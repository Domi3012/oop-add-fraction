#include "Fraction.h"
#include "../bus/Fraction.h"
#include <iostream>
#include <regex>
#include <sstream>

std::expected<Fraction, std::string> ui::getFractionLoop(std::string message, int maxAttempts) {
    std::cout << '\n' << message << '\n';

    int attempted = 0;
    while (attempted < maxAttempts) {
        std::cout << std::format("(Bạn còn {0} lần thử)\n", maxAttempts - attempted);
        std::cout << "Hãy nhập số dưới định dạng 'a/b' (Phân số), hoặc 'c' (Số nguyên): ";
        std::string buffer; getline(std::cin, buffer);
        auto result = bus::parseFraction(buffer);
        if (result) {
            return result;
        } else {
            std::cout << "Error: " << result.error() << '\n';
            attempted++;
        }
    }
    return std::unexpected("Đã quá số lần nhập phân số.");
}


std::string ui::fracToString(const Fraction& frac) {
    // Case 1: Complete Fraction:
    if (frac.numerator() % frac.denominator() == 0) {
        return std::format("{0}", frac.numerator() / frac.denominator());
    }

    // Case 2: Mixed Fraction:
    if (abs(frac.numerator()) > frac.denominator()) {
        int whole = frac.numerator() / frac.denominator(); // Phần nguyên của phân số
        int remainder = abs(frac.numerator()) % frac.denominator(); // Phần dư sau phần nguyên
        return std::format("{0} {1}/{2}", whole, remainder, frac.denominator());
    }

    // Case 3: Normal Fraction:
    return std::format("{0}/{1}", frac.numerator(), frac.denominator());
}
#ifndef FRACTION_INPUT_H
#define FRACTION_INPUT_H

#include "Fraction.h"
#include <iostream>
#include <regex>
#include <sstream>

class FractionInput {
public:
    static std::expected<Fraction, std::string> parseFraction(std::string &input);
    static std::expected<Fraction, std::string> getFractionLoop(std::string message, int maxAttempts = 3);
};

#endif
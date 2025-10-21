#ifndef FRACTION_INPUT_H
#define FRACTION_INPUT_H

#include "../dto/Fraction.h"
#include "Fraction.h"
#include <expected>
#include <string> 

namespace ui {
    //std::expected<Fraction, std::string> parseFraction(std::string &input);
    std::string fracToString(const Fraction& frac);
    std::expected<Fraction, std::string> getFractionLoop(std::string message, int maxAttempts = 3);
};

#endif
#ifndef FRACTION_BUS_H
#define FRACTION_BUS_H

#include "../dto/Fraction.h"
namespace bus {
    std::expected<Fraction, std::string> parseFraction(std::string& input);
};

#endif
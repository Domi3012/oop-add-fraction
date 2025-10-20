#ifndef FRACTION_INPUT_H
#define FRACTION_INPUT_H

#include "Fraction.h"
#include <expected>
#include <string> 

/**
 * @class FractionInput
 * @brief A utility class providing static methods for parsing and
 * retrieving Fraction objects from user input.
 */
class FractionInput {
public:

    /**
     * @brief Tries to parse a single string into a Fraction object.
     *
     * This "worker" function uses regex to validate and parse a string.
     * It handles whole numbers (e.g., "5"), simple fractions (e.g., "1/2"),
     * and fractions with spaces (e.g., " -3 / 4 "). It does not use cin/cout,
     * making it suitable for unit testing.
     *
     * @param input The raw string to parse.
     * @return A std::expected object which either contains the valid Fraction
     * on success or a std::string error message on failure (e.g.,
     * invalid format or denominator is zero).
     */
    static std::expected<Fraction, std::string> parseFraction(std::string &input);

    /**
     * @brief Prompts the user in a loop to get a valid Fraction.
     *
     * This "manager" function repeatedly asks the user for input until they
     * provide a valid fraction string (as validated by parseFraction) or
     * they exhaust their allowed attempts.
     *
     * @param message The initial message to display to the user.
     * @param maxAttempts The maximum number of tries the user has.
     * @return A std::expected object which either contains the valid Fraction
     * on success or a std::string error message if the user
     * failed all attempts.
     */
    static std::expected<Fraction, std::string> getFractionLoop(std::string message, int maxAttempts = 3);
};

#endif
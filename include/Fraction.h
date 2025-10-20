#ifndef FRACTION_H
#define FRACTION_H

#include <expected>
#include <string>

/**
 * @class Fraction
 * @brief Represents a mathematical fraction with a numerator and denominator.
 *
 * This class models a fraction, storing it in a reduced and normalized
 * (positive denominator) form. It ensures fractions are always in a valid
 * state by using private constructors and safe, validating static factory methods.
 * It also supports addition and string conversion.
 */
class Fraction {
private:
    int _numerator;
    int _denominator;

    // these constructors are not accesable from outside and they themselves do not check for denominator error
    Fraction();
    Fraction(int num, int den);
    Fraction(int num);

    /**
     * @brief (Private) Calculates the Greatest Common Divisor (GCD) of two integers.
     * * Uses the Euclidean algorithm. Input values are treated as absolute.
     * @param a The first integer.
     * @param b The second integer.
     * @return The positive GCD of a and b.
     */
    int gcd(int a, int b);

    /**
     * @brief (Private) Reduces the fraction to its lowest terms and normalizes the sign.
     * * This method simplifies the fraction by dividing both the numerator and
     * denominator by their GCD. It also ensures the denominator is always positive,
     * moving any negative sign to the numerator.
     */
    void reduce();
public:

    /**
     * @brief Static method to create a fraction from a numerator and denominator.
     * * This is the primary safe way to create a fraction. It validates the input
     * to prevent division by zero.
     * @param num The desired numerator.
     * @param den The desired denominator.
     * @return A std::expected object containing the Fraction on success, 
     * or an error string if the denominator is zero.
     */
    static std::expected<Fraction, std::string> createFraction(int num, int den);

    /**
     * @brief Static factory method to create a fraction from a whole number.
     * * Creates a fraction with the given number as the numerator and 1 as the denominator.
     * @param num The whole number.
     * @return A std::expected object containing the new Fraction.
     */
    static std::expected<Fraction, std::string> createFraction(int num);

    /**
     * @brief Static factory method to create a default (zero) fraction.
     * * Creates a fraction with the value 0/1.
     * @return A std::expected object containing the zero Fraction.
     */
    static std::expected<Fraction, std::string> createFraction();

    /**
     * @brief Converts the fraction to a human-readable string.
     * * The format depends on the value:
     * 1. If it's a whole number (e.g., 6/3), it returns "2".
     * 2. If the magnitude is > 1 (e.g., 7/2), it returns a mixed fraction "3 1/2".
     * 3. If the magnitude is < 1 (e.g., 1/3), it returns a simple fraction "1/3".
     * Handles negative mixed fractions correctly (e.g., -7/2 is "-3 1/2").
     * @return A std::string representation of the fraction.
     */
    std::string toString();

    /**
     * @brief Overloads the addition operator (+) to add two fractions.
     * * Calculates the sum of this fraction and another fraction.
     * The resulting fraction is automatically reduced by its constructor.
     * @param other The fraction to add (right-hand side of the operator).
     * @return A new Fraction object representing the sum.
     */
    Fraction operator+(const Fraction &other);
};



#endif
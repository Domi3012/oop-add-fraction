#include <gtest/gtest.h>

#include "../include/Fraction.h"
#include "../include/FractionInput.h"

TEST(FractionTest, AdditionSimple) {
    auto frac1_result = Fraction::createFraction(1, 4);
    auto frac2_result = Fraction::createFraction(2, 4);

    Fraction sum = frac1_result.value() + frac2_result.value();
    std::string output = sum.toString();

    EXPECT_EQ(output, "3/4");
}

TEST(FractionTest, AdditionWithReduction) {
    auto frac1 = Fraction::createFraction(1, 2).value();
    auto frac2 = Fraction::createFraction(1, 2).value();

    Fraction sum = frac1 + frac2;
    std::string output = sum.toString();
    
    EXPECT_EQ(output, "1");
}

TEST(FractionTest, ToStringNegativeMixed) {
    auto frac = Fraction::createFraction(-5, 2).value();

    std::string output = frac.toString();

    EXPECT_EQ(output, "-2 1/2");
}

TEST(FractionInputTest, ParseValidFraction) {
    std::string input = " 3/2 ";

    auto result = FractionInput::parseFraction(input);

    EXPECT_TRUE(result.has_value());
    EXPECT_EQ(result.value().toString(), "1 1/2");
}

TEST(FractionInputTest, ParseValidWholeNumber) {
    std::string input = " -5    ";

    auto result = FractionInput::parseFraction(input);

    EXPECT_TRUE(result.has_value());
    EXPECT_EQ(result.value().toString(), "-5");
}

TEST(FractionInputTest, ParseInvalidFormat) {
    std::string input = "hello";

    auto result = FractionInput::parseFraction(input);

    EXPECT_FALSE(result.has_value());
    EXPECT_EQ(result.error(), "Phân số nhập không đúng định dạng.");
}

TEST(FractionInputTest, ParseDenominatorZero) {
    std::string input = "10 / 0";

    auto result = FractionInput::parseFraction(input);

    EXPECT_FALSE(result.has_value());
    EXPECT_EQ(result.error(), "Mẫu số không được là số 0");
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
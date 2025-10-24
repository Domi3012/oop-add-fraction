#include <gtest/gtest.h>
#include "../fraction/dto/Fraction.h"
#include "../fraction/bus/Fraction.h"
#include "../fraction/ui/Fraction.h"
#include "../fraction/useCase/useCase.h"

#include <string>
#include <sstream>
#include <format>

///////////////////////////////////////////////////////////////////////
// Test Suite: DTO ////////////////////////////////////////////////////
class FractionDTOTest : public ::testing::Test {
protected:
    void SetUp() override {}
    void TearDown() override {}
};

TEST_F(FractionDTOTest, ParameterlessConstructor) {
    auto result = Fraction::createFraction();
    Fraction f = result.value();
    EXPECT_EQ(f.numerator(), 0);
    EXPECT_EQ(f.denominator(), 1);
}

TEST_F(FractionDTOTest, OneParameterConstructor) {
    auto result = Fraction::createFraction(-10);
    Fraction f = result.value();
    EXPECT_EQ(f.numerator(), -10);
    EXPECT_EQ(f.denominator(), 1);
}

TEST_F(FractionDTOTest, TwoParameterConstructor) {
    auto result = Fraction::createFraction(3, 5);
    Fraction f = result.value();
    EXPECT_EQ(f.numerator(), 3);
    EXPECT_EQ(f.denominator(), 5);
}

TEST_F(FractionDTOTest, ZeroDenominator) {
    auto result = Fraction::createFraction(1, 0);
    EXPECT_EQ(result.error(), "Mẫu số không được là số 0");
}

TEST_F(FractionDTOTest, NumericRedcution) {
    auto result = Fraction::createFraction(8, 6);
    Fraction f = result.value();
    EXPECT_EQ(f.numerator(), 4);
    EXPECT_EQ(f.denominator(), 3);
}

TEST_F(FractionDTOTest, OneMinusSignRedcution) {
    auto result = Fraction::createFraction(1, -3);
    Fraction f = result.value();
    EXPECT_EQ(f.numerator(), -1);
    EXPECT_EQ(f.denominator(), 3);
}

TEST_F(FractionDTOTest, TwoMinusSignReduction) {
    auto result = Fraction::createFraction(-1, -3);
    Fraction f = result.value();
    EXPECT_EQ(f.numerator(), 1);
    EXPECT_EQ(f.denominator(), 3);
}

TEST_F(FractionDTOTest, NormalAddition) {
    auto result1 = Fraction::createFraction(1, 4);
    auto result2 = Fraction::createFraction(2, 4);
    Fraction f1 = result1.value();
    Fraction f2 = result2.value();
    Fraction f3 = f1 + f2;
    EXPECT_EQ(f3.numerator(), 3);
    EXPECT_EQ(f3.denominator(), 4);
}

TEST_F(FractionDTOTest, AdditionWithReduction) {
    auto result1 = Fraction::createFraction(5, 8);
    auto result2 = Fraction::createFraction(1, 8);
    Fraction f1 = result1.value();
    Fraction f2 = result2.value();
    Fraction f3 = f1 + f2;
    EXPECT_EQ(f3.numerator(), 3);
    EXPECT_EQ(f3.denominator(), 4);
}




//////////////////////////////////////////////////////////////////////
// Test Suite: UI ////////////////////////////////////////////////////
class FractionUITest : public :: testing::Test {
protected:
    void SetUp() override {}
    void TearDown() override {}
};

TEST_F(FractionUITest, ParseFraction) {
    std::string input = "3/4";
    auto result = ui::parseFraction(input);
    Fraction f = result.value();
    EXPECT_EQ(f.numerator(), 3);
    EXPECT_EQ(f.denominator(), 4);
}

TEST_F(FractionUITest, ParseFractionWithSpaces) {
    std::string input = "      3     /     4     ";
    auto result = ui::parseFraction(input);
    Fraction f = result.value();
    EXPECT_EQ(f.numerator(), 3);
    EXPECT_EQ(f.denominator(), 4);
}

TEST_F(FractionUITest, ParseFractionWithMinusSign) {
    std::string input = "      -3     /     -4     ";
    auto result = ui::parseFraction(input);
    Fraction f = result.value();
    EXPECT_EQ(f.numerator(), 3);
    EXPECT_EQ(f.denominator(), 4);
}

TEST_F(FractionUITest, FractionToString_Normal) {
    auto result = Fraction::createFraction(3, 4);
    Fraction f = result.value();
    std::string output = ui::fracToString(f);
    EXPECT_EQ(output, "3/4");
}

TEST_F(FractionUITest, FractionToString_WholeNumber) {
    auto result = Fraction::createFraction(6, -3);
    Fraction f = result.value();
    std::string output = ui::fracToString(f);
    EXPECT_EQ(output, "-2");
}

TEST_F(FractionUITest, FractionToString_Mixed) {
    auto result = Fraction::createFraction(8, 7);
    Fraction f = result.value();
    std::string output = ui::fracToString(f);
    EXPECT_EQ(output, "1 1/7");
}

TEST_F(FractionUITest, FractionToString_NegativeMixed) {
    auto result = Fraction::createFraction(-7, 3);
    Fraction f = result.value();
    std::string output = ui::fracToString(f);
    EXPECT_EQ(output, "-2 1/3");
}


// toi day la 16 tests

///////////////////////////////////////////////////////////////////////////
// Test Suite: useCase ////////////////////////////////////////////////////
class AddFractionUseCaseTest : public :: testing::Test {
protected:
    // 2 con tro tro ve cin va cout goc
    std::streambuf* cinBuf;
    std::streambuf* coutBuf;

    // 2 stream dung de luu tru gia tri tren cin va cout
    std::istringstream simulatedInput;
    std::ostringstream capturedOutput;

    void SetUp() { 

        cinBuf = std::cin.rdbuf();
        coutBuf = std::cout.rdbuf();
        std::cin.rdbuf(simulatedInput.rdbuf());
        std::cout.rdbuf(capturedOutput.rdbuf());
    }

    void TearDown() {
        std::cin.rdbuf(cinBuf);
        std::cout.rdbuf(coutBuf);
    }
};

TEST_F(AddFractionUseCaseTest, HappyUseCase) {
    std::string frac1 = ui::fracToString(Fraction::createFraction(1, 3).value());
    std::string frac2 = ui::fracToString(Fraction::createFraction(1, 3).value());
    simulatedInput.str(std::format("\n{}\n{}\n\n", frac1, frac2));

    addFractionsUseCase useCase;
    useCase.execute();

    std::string expectedString = "Kết quả: 2/3";
    std::string actualString = capturedOutput.str();
    EXPECT_NE(actualString.find(expectedString), std::string::npos);
}

TEST_F(AddFractionUseCaseTest, FirstFraction3Attempts) {
    std::string invalidFraction = "abc";
    simulatedInput.str(std::format("\n{}\n{}\n{}\n", invalidFraction, invalidFraction, invalidFraction));

    addFractionsUseCase useCase;
    useCase.execute();

    std::string expectedString = "Không thể nhập phân số thứ nhất. Error: Đã quá số lần nhập phân số.";
    std::string actualString = capturedOutput.str();
    EXPECT_NE(actualString.find(expectedString), std::string::npos);
}

TEST_F(AddFractionUseCaseTest, SecondFraction3Attempts) {
    std::string validFraction = "3/4";
    std::string invalidFraction = "abc";
    simulatedInput.str(std::format("\n{}\n{}\n{}\n{}\n", validFraction, invalidFraction, invalidFraction, invalidFraction));

    addFractionsUseCase useCase;
    useCase.execute();

    std::string expectedString = "Không thể nhập phân số thứ hai. Error: Đã quá số lần nhập phân số.";
    std::string actualString = capturedOutput.str();
    EXPECT_NE(actualString.find(expectedString), std::string::npos);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
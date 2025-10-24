#include "../dto/Fraction.h"
#include "../ui/Fraction.h"
#include "useCase.h"
#include <iostream>

void addFractionsUseCase::execute() {
    auto result1 = ui::getFractionLoop("Hãy nhập phân số đầu tiên:\n");

    if (!result1.has_value()) {
        std::cout << "Không thể nhập phân số thứ nhất. Error: " << result1.error() << "\n";
        return; // Stop the use case
    }

    auto result2 = ui::getFractionLoop("Hãy nhập phân số thứ hai:\n");
    if (!result2.has_value()) {
        std::cout << "Không thể nhập phân số thứ hai. Error: " << result2.error() << "\n";
        return;
    }

    Fraction frac1 = result1.value();
    Fraction frac2 = result2.value();

    Fraction sum = frac1 + frac2;
    std::string result = ui::fracToString(sum);

    std::cout << "\nKết quả: " << result << "\n";
}
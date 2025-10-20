#include "../include/useCase.h"
#include "../include/Fraction.h"
#include "../include/FractionInput.h"

#include <iostream>

void greet() {
    std::cout << "CHƯƠNG TRÌNH TÍNH TỔNG 2 PHÂN SỐ.\n";
    std::cout << "Nhấn Enter để tiếp tục...";
    std::cin.get();
}

void bye() {
    std::cout << "CHƯƠNG TRÌNH ĐANG THOÁT.\n";
    std::cout << "Nhấn Enter để tiếp tục...";
    std::cin.get();
}

void addFractionsUseCase() {
    auto result1 = FractionInput::getFractionLoop("Hãy nhập phân số đầu tiên:\n");

    if (!result1.has_value()) {
        std::cout << "Không thể nhập phân số thứ nhất. Error: " << result1.error() << "\n";
        return; // Stop the use case
    }

    auto result2 = FractionInput::getFractionLoop("Hãy nhập phân số thứ hai:\n");
    if (!result2.has_value()) {
        std::cout << "Không thể nhập phân số thứ hai. Error: " << result2.error() << "\n";
        return;
    }

    Fraction frac1 = result1.value();
    Fraction frac2 = result2.value();

    Fraction sum = frac1 + frac2;
    std::string result = sum.toString();

    std::cout << "\nKết quả: " << result << "\n";
}
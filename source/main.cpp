#include "../include/Fraction.h"
#include "../include/FractionInput.h"
#include <iostream>

int main() {
    auto result = FractionInput::getFractionLoop("Hãy nhập phân số thứ nhất.");
    if (result) {
        std::cout << (*result).toString();
    }
    

    return 0;
}
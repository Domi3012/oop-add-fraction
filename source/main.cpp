#include "../include/Fraction.h"
#include <iostream>

int main() {
    int num, den;
    std::cin >> num >> den;
    auto result = Fraction::createFraction(num, den);
    if (result) std::cout << (*result).toString();
    else std::cout << "Error: " << result.error() << std::endl; 

    

    return 0;
}
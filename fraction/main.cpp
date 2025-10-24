#include "useCase/useCase.h"
#include <iostream>

void greet();
void bye();

int main() {
    greet();
    
    addFractionsUseCase useCase;
    useCase.execute();

    bye();
    return 0;
}

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
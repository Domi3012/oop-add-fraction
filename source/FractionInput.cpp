#include "../include/FractionInput.h"
#include <iostream>
#include <regex>
#include <sstream>

std::expected<Fraction, std::string> FractionInput::parseFraction(std::string& input) {
    std::regex fractionPattern(R"(^\s*([\-]?\d+)\s*(\/\s*([\-]?\d+))?\s*$)"); 
    std::smatch match;
    /*
        Giải thích pattern này: Mỗi () là một nhóm được lưu vào match
        - Nhóm 1: ([\-]?\d+) bắt buộc phải có mặt. Đây chính là tử số và được lưu vào match[1]. Dấu âm có thể có 1 hoặc không có.
        - Nhóm 2: (\/\s*([\-]?\d+))? có thể có hoặc không. Đây chính là phần chuỗi chứa dấu gạch chéo và phần mẫu đằng sau.
        - Nhóm 3: ([\-]?\d+) là mẫu số, có thể có dấu âm hoặc không. Lưu vào match[3].
        - \s* được đặt vào các vị trí cho phép có khoảng trống
        - ^ ở đầu và $ ở cuối báo rằng toàn bộ string phải match pattern này thì mới thỏa mãn.
    */
    if (std::regex_match(input, match, fractionPattern)) {
        int num = stoi(match[1]);
        if (match[3].matched) { // Người dùng có nhập mẫu số.
            int den = stoi(match[3]);
            return Fraction::createFraction(num, den);
        } else {
            return Fraction::createFraction(num);
        }
    } else {
        return std::unexpected("Phân số nhập không đúng định dạng.");
    }
}

std::expected<Fraction, std::string> FractionInput::getFractionLoop(std::string message, int maxAttempts) {
    std::cout << '\n' << message << '\n';

    int attempted = 0;
    while (attempted < maxAttempts) {
        std::cout << std::format("(Bạn còn {0} lần thử)\n", maxAttempts - attempted);
        std::cout << "Hãy nhập số dưới định dạng 'a/b' (Phân số), hoặc 'c' (Số nguyên): ";
        std::string buffer; getline(std::cin, buffer);
        auto result = parseFraction(buffer);
        if (result) {
            return result;
        } else {
            std::cout << "Error: " << result.error() << '\n';
            attempted++;
        }
    }
    return std::unexpected("Đã quá số lần nhập phân số.");
}
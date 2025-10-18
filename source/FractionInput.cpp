#include "../include/FractionInput.h"

std::expected<Fraction, std::string> FractionInput::parseFraction(std::string& input) {
    std::regex fractionPattern("(\s*[\-]?\d+\s*/\s*[\-]?\d+\s*)");
    std::regex wholeNumberPattern("(\s*[\-]?\d\s*)");

    if (!std::regex_match(input, fractionPattern) && !std::regex_match(input, wholeNumberPattern)) {
        return std::unexpected("Phân số được nhập không đúng định dạng.");
    } 
    else if (std::regex_match(input, fractionPattern)) { // Người dùng nhập a/b
        std::stringstream buffer(input);
        int num, den;
        buffer >> num; std::cin.ignore(10000, '/');
        buffer >> den;
        return Fraction::createFraction(num, den); // createFraction sẽ xử lí mẫu = 0 và trả về unexpected nếu cần.
    } 
    else { // Người dùng nhập 1 số nguyên
        return Fraction::createFraction(stoi(input));
    }
}


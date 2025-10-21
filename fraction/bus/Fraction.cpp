#include "../dto/Fraction.h"
#include "Fraction.h"
#include <regex>

std::expected<Fraction, std::string> bus::parseFraction(std::string& input) {
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


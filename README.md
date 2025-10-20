# oop-add-fraction

Bài tập thực hành \#1 môn "Phương pháp Lập trình Hướng đối tượng", lớp 24CTT1, học kỳ 1/2025-2026

## Thông tin sinh viên:

  - Họ và tên: **Nguyễn Đức Anh Khôi**
  - MSSV: **24120076**

## 1\. Mô tả Project

Đây là một ứng dụng console C++ thực hiện phép cộng hai phân số do người dùng nhập vào. Chương trình yêu cầu người dùng nhập hai phân số (có thể là phân số, số nguyên, hoặc hỗn số). Sau đó, chương trình tính tổng và hiển thị kết quả ở dạng rút gọn và chuẩn hóa.

Chương trình được thiết kế để tập trung vào việc xử lý lỗi đầu vào một cách an toàn và định dạng kết quả đầu ra theo yêu cầu của bài tập.

## 2\. Tính năng chính

  * **Tính toán phân số**: Cộng chính xác hai phân số, bao gồm cả các phân số có mẫu số khác nhau.
  * **Xử lý đầu vào linh hoạt**: Sử dụng C++ `<regex>` để xử lý chuỗi đầu vào. Cho phép nhập:
      * Phân số đơn (`a/b`)
      * Số nguyên (`a`)
      * Xử lý các trường hợp có khoảng trắng (ví dụ: `5 / 2`)
      * Xử lý số âm (ví dụ: `-1/2` hoặc `-3`)
  * **Xác thực đầu vào**: Cung cấp thông báo lỗi rõ ràng cho đầu vào không hợp lệ (ví dụ: "hello", "1/", "5/0"). Sử dụng `std::expected` để xử lý lỗi thay vì exception.
  * **Logic thử lại**: Cho phép người dùng nhập lại tối đa 3 lần nếu nhập sai.
  * **Rút gọn phân số**: Tất cả kết quả đều được tự động rút gọn về dạng tối giản (ví dụ: `2/4` thành `1/2`).
  * **Chuẩn hóa đầu ra**: Kết quả được định dạng theo yêu cầu:
      * **Số nguyên**: `4/2` hiển thị là `2`
      * **Hỗn số**: `7/3` hiển thị là `2 1/3` (hỗ trợ cả hỗn số âm)
      * **Phân số đơn**: `1/3` hiển thị là `1/3`
  * **Kiểm thử (Unit Test)**: Các logic cốt lõi (tính toán và xử lý chuỗi) được xác minh bằng Google Test (Gtest).

## 3\. Cấu trúc Thư mục

```
.
├── build/             # Chứa các file thực thi đã biên dịch
├── include/           # Chứa các file header (.h)
│   ├── Fraction.h       # Model (Xử lý toán học)
│   ├── FractionInput.h  # Utility (Xử lý input)
│   └── useCase.h        # Use Case (Xử lý logic ứng dụng)
├── source/            # Chứa các file triển khai (.cpp)
│   ├── Fraction.cpp
│   ├── FractionInput.cpp
│   ├── useCase.cpp
│   └── main.cpp         # File main (Điểm vào chương trình)
├── test/
│   ├── test.cpp         # Chứa các file kiểm thử Gtest
│   └── ...
└── README.md
```

## 4\. Cách biên dịch và chạy

### Yêu cầu

  * Trình biên dịch C++ hỗ trợ `C++23` (ví dụ: g++ 13 trở lên)
  * Đã cài đặt thư viện `gtest` và `gtest_main`

### Biên dịch chương trình chính

Tạo thư mục build (nếu chưa có):

```bash
$ mkdir -p build
```

Chạy lệnh sau từ thư mục gốc của đồ án:

```bash
$ g++ -std=c++23 source/*.cpp -o build/app
```

### Biên dịch kiểm thử (tests)

Chạy lệnh sau từ thư mục gốc của đồ án:

```bash
$ g++ -std=c++23 -Wall -g -pthread test/test.cpp source/Fraction.cpp source/FractionInput.cpp -Iinclude -lgtest_main -lgtest -lpthread -o test/tests
```

### Thực thi

```bash
# Chạy chương trình chính
./build/app

# Chạy các bài kiểm thử
./test/tests
```
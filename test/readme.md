Lệnh build test từ folder test:

```Bash
$ g++ -std=c++23 -Wall -g -pthread test.cpp ../source/Fraction.cpp ../source/FractionInput.cpp -I../include -lgtest_main -lgtest -lpthread -o tests
```

Lệnh thực thi test từ folder test:

```Bash
$ ./tests
'''
Lệnh build test từ folder test:

```Bash
$ g++ -std=c++23 -Wall -g -pthread main.cpp ../fraction/dto/*.cpp ../fraction/ui/*.cpp ../fraction/useCase/*.cpp -lgtest_main -lgtest -lpthread -o ./out/tests
```

Lệnh thực thi test từ folder test:

```Bash
$ ./out/tests
'''
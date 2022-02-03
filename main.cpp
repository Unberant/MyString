#include <iostream>
#include <string>
#include "myString.h"
#include <cstring>

int main() {
    char temp[] = "Hello";
    int mas_i[] = {1, 5, 9, 4, 5, 6, 7};
    std::vector<int> vec_1 = {0, 1, 2, 3, 4, 5, 6, 7, 8};

    myString<int> str_1(57, 3);                             // str_1 = "575757"
    myString<double> str_2(33.23);                          // str_2 = "33.23"
    myString<char> str_3('f', 3);                           // str_3 = "f"
    myString<char> str_4("text");                           // str_4 = "text"
    myString<bool> str_5(true);                             // str_5 = "0"
    myString<char> str_6(temp);                             // str_6 = "Hello"
    myString<int> str_7(vec_1);                             // str_7 = "012345678"
    myString<int> str_8(std::begin(mas_i), std::end(mas_i));// str_8 = "1594567"
}

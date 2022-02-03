//
// Created by appig on 15-Dec-21.
//

#include "myString.h"
#include <cstring>
#include <iostream>

template
class myString<int>;

template
class myString<char>;

template
class myString<double>;

template
class myString<float>;

template
class myString<bool>;


template<typename T>
myString<T>::~myString() {
    delete str;
}

template<typename T>
myString<T>::myString() : str(nullptr) {
    str = new char[1];
    str[0] = '\0';
}

template<typename T>
myString<T>::myString(T value) {
    if (typeid(char) == typeid(value)) {
        str = new char[2];
        str[0] = value;
        str[1] = '\0';
    } else {
        std::string _value = std::to_string(value);
        str = new char[_value.size() + 1];
        strcpy(str, _value.c_str());
        str[_value.size()] = '\0';
    }
}

template<typename T>
myString<T>::myString(std::vector<T> &value) {
    str = new char[value.size() + 1];
    int j = 0;
    while (j < value.size()) {
        auto value_j = value.at(j);
        std::string _value = std::to_string(value_j);
        for (auto value_i: _value) {
            str[j++] = value_i;
        }
    }
    str[value.size()] = '\0';
}

template<typename T>
myString<T>::myString(T value, int quantity) {
    if (typeid(char) == typeid(value)) {
        str = new char[quantity + 1];
        for (int i = 0; i < quantity; ++i) {
            str[i] = value;
        }
        str[quantity] = '\0';
    } else {
        std::string _value = std::to_string(value);
        str = new char[_value.size() * quantity + 1];
        int j = 0;
        while (j < _value.size() * quantity) {
            for (auto value_i: _value) {
                str[j++] = value_i;
            }
        }
        str[_value.size() * quantity] = '\0';
    }
}

template<typename T>
myString<T>::myString(char *value) {
    if (value == nullptr) {
        str = new char[1];
        str[0] = '\0';
    } else {
        str = new char[strlen(value) + 1];
        strcpy(str, value);
        str[strlen(value)] = '\0';
    }
}

template<typename T>
myString<T>::myString(T *begin, T *end) {
    if (begin == nullptr) {
        str = new char[1];
        str[0] = '\0';
    } else {
        int length = 0;
        while ((begin + length++) < end);
        str = new char[length];
        for (int i = 0; i < length - 1; ++i) {
            str[i] = char((begin[i] + '0'));
        }
        str[length - 1] = '\0';
    }
}

template<typename T>
// Copy Constructor
myString<T>::myString(const myString &that) {
    str = new char[that.get_length() + 1];
    strcpy(str, that.get_point());
    str[that.get_length()] = '\0';
}

template<typename T>
// Move Constructor
myString<T>::myString(myString &&other) noexcept {
    str = other.str;
    other.wanish_ptr();
}

template<typename T>
void myString<T>::show() const {
    std::cout << str << std::endl;
}

template<typename T>
char myString<T>::get_element(int coord) const {
    return str[coord];
}


template<typename T>
void myString<T>::wanish_ptr() {
    str = nullptr;
}

template<typename T>
int myString<T>::get_length() const {
    return strlen(str);
}

template<typename T>
char *myString<T>::get_point() const {
    return str;
}

template<typename T>
bool myString<T>::is_empty() const{
    if (str[0] == '\0') return true;
    else return false;
}


template<typename T>
void myString<T>::clear() {
    delete[] str;
    str = new char[1];
    str[0] = '\0';
}

template<typename T>
myString<T> myString<T>::part_of(int index, unsigned int length) {
    if (index + length > get_length() || index > get_length()) {
        std::cout << "Error: out of range\n";
        return *this;
    }// normal range
    char *new_str = new char[length + 1];
    int j = 0;
    for (int i = index; i < index + length; ++i) {
        new_str[j++] = str[i];
    }
    new_str[j] = '\0';
    myString new_object(new_str);
    delete[] new_str;
    return new_object;
}


//
// Created by appig on 15-Dec-21.
//

#ifndef LAB_4_MYSTRING_H
#define LAB_4_MYSTRING_H

#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <typeinfo>

template<typename T>
class myString {
protected:
    char *str;
public:

    ~myString();

    myString();

    explicit myString(T value);

    explicit myString(std::vector<T> &value);

    explicit myString(T value, int quantity);

    explicit myString(char *value);

    explicit myString(T *begin, T *end);

    //  template<typename U> // Copy Constructor
    myString(const myString &that);

    //template<typename U> // Move Constructor
    myString(myString &&other) noexcept;

    void show() const;

    char get_element(int coord) const;

    void wanish_ptr();

    int get_length() const;

    char *get_point() const;

    bool is_empty() const;

    void clear();

    myString part_of(int index, unsigned int length);

    template<typename U>
    friend std::ostream &operator<<(std::ostream &out, const myString<U> &point);

    template<typename U>
    friend std::istream &operator>>(std::istream &is, myString<U> &point);

    template<typename L, typename R>
    // myString + myString
    friend myString<L> operator+(const myString<L> &left, const myString<R> &right);

    template<typename L, typename R>
    // myString + 3
    friend myString<L> operator+(const myString<L> &left, R right);

    template<typename L, typename R>
    // 3 + myString
    friend myString<R> operator+(L left, const myString<R> &right);

    template<typename L>
    // myString * 4
    friend myString<L> operator*(const myString<L> &left, int right);

    template<typename R>
    // 4 * myString
    friend myString<R> operator*(int left, const myString<R> &right);

    template<typename L, typename R>
    // myString == myString
    friend bool operator==(const myString<L> &left, const myString<R> &right);

    template<typename L, typename R>
    // myString != myString
    friend bool operator!=(const myString<L> &left, const myString<R> &right);

    template<typename L, typename R>
    // myString > myString
    friend bool operator>(const myString<L> &left, const myString<R> &right);

    template<typename L, typename R>
    // myString >= myString
    friend bool operator>=(const myString<L> &left, const myString<R> &right);

    template<typename L, typename R>
    // myString < myString
    friend bool operator<(const myString<L> &left, const myString<R> &right);

    template<typename L, typename R>
    // myString <= myString
    friend bool operator<=(const myString<L> &left, const myString<R> &right);

    template<typename U>
    // myString<T> = myString<U>
    myString<T> &operator=(const myString<U> &right) {
        delete[] str;
        str = new char[right.get_length() + 1];
        strcpy(str, right.get_point());
        str[right.get_length()] = '\0';
        return *this;
    }

    template<typename U>
    // myString<T> = MOVE(myString<U>)
    myString<T> &operator=(myString<U> &&right) noexcept {
        delete[] str;
        str = right.get_point();
        right.wanish_ptr();
//        right.str = nullptr;
        return *this;
    }

    // myString<T> = MOVE(myString<T>)
    myString<T> &operator=(const myString<T> &right) {
        delete[] str;
        str = new char[right.get_length() + 1];
        strcpy(str, right.get_point());
        str[right.get_length()] = '\0';
        return *this;
    }

    // myString<T> = myString<T>
    myString<T> &operator=(myString<T> &&right) noexcept {
        delete[] str;
        str = right.get_point();
//        right.set_element(0, '\0');
        right.wanish_ptr();
        return *this;
    }

    //myString<T>(myString<T>)
    void operator()(const myString<T> &other) {
        delete[] str;
        str = new char[other.get_length() + 1];
        strcpy(str, other.get_point());
        str[other.get_length()] = '\0';
    }

    template<typename U>
    //myString<T>(myString<U>)
    void operator()(const myString<U> &other) {
        delete[] str;
        str = new char[other.get_length() + 1];
        strcpy(str, other.get_point());
        str[other.get_length()] = '\0';
    }

    //myString<?> = myString<T>(myString<T>)
    myString<T> operator()(const myString<T> &other, const bool &some_bool) const {
        int length = other.get_length();
        char *new_str = new char[length + 1];
        strcpy(new_str, other.get_point());
        new_str[length] = '\0';

        myString<T> new_object(new_str);
        delete[]new_str;
        return new_object;
    }

    template<typename U>
    //myString<?> = myString<T>(myString<U>)
    myString<T> operator()(const myString<U> &other, const bool &some_bool) const {
        int length = other.get_length();
        char *new_str = new char[length + 1];
        strcpy(new_str, other.get_point());
        new_str[length] = '\0';

        myString<T> new_object(new_str);
        delete[]new_str;
        return new_object;
    }

    char &operator[](int index);
};

template<typename T>
std::ostream &operator<<(std::ostream &out, const myString<T> &point) {
    out << point.str;
    return out;
}

template<typename T>
std::istream &operator>>(std::istream &is, myString<T> &point) {
    char *new_str = new char[100];
    memset(&new_str[0], 0, sizeof(new_str));
    is >> new_str;
    point = myString<T>(new_str);
    delete[] new_str;
    return is;
}

template<typename L, typename R>
myString<L> operator+(const myString<L> &left, const myString<R> &right) {
    int length = left.get_length() + right.get_length();
    char *new_str = new char[length + 1];

    strcpy(new_str, left.get_point());
    strcat(new_str, right.get_point());
    new_str[length] = '\0';

    myString<L> new_object(new_str);
    delete[]new_str;
    return new_object;
}

template<typename L, typename R>
myString<L> operator+(const myString<L> &left, R right) {
    int length = left.get_length() + 1;
    char *new_str = new char[length + 1];
    std::string _right;
    if (typeid(char) == typeid(right)) _right = right;
    else _right = std::to_string(right);

    strcpy(new_str, left.get_point());
    strcat(new_str, _right.c_str());

    new_str[length] = '\0';

    myString<L> new_object(new_str);
    delete[]new_str;
    return new_object;
}

template<typename L, typename R>
myString<R> operator+(L left, const myString<R> &right) {
    int length = right.get_length() + 1;
    char *new_str = new char[length + 1];
    std::string _left;
    if (typeid(char) == typeid(left)) _left = left;
    else _left = std::to_string(left);

    strcpy(new_str, _left.c_str());
    strcat(new_str, right.get_point());

    new_str[length] = '\0';
    myString<R> new_object(new_str);
    delete[]new_str;
    return new_object;
}


template<typename L>
myString<L> operator*(const myString<L> &left, int right) {
    if (right == 0) return myString<L>();
    int length = left.get_length() * right;
    char *new_str = new char[length + 1];

    strcpy(new_str, left.get_point());
    while ((--right) > 0) {
        strcat(new_str, left.get_point());
    }
    new_str[length] = '\0';

    myString<L> new_object(new_str);
    delete[]new_str;
    return new_object;
}

template<typename R>
myString<R> operator*(int left, const myString<R> &right) {
    if (left == 0) return myString<R>();
    int length = right.get_length() * left;
    char *new_str = new char[length + 1];

    strcpy(new_str, right.get_point());
    while ((--left) > 0) {
        strcat(new_str, right.get_point());
    }
    new_str[length] = '\0';

    myString<R> new_object(new_str);
    delete[]new_str;
    return new_object;
}

template<typename L, typename R>
bool operator==(const myString<L> &left, const myString<R> &right) {
    if (left.get_length() != right.get_length()) return false;
    for (int i = 0; i < left.get_length(); ++i) {
        if (left.str[i] != right.str[i]) return false;
    }
    return true;
}

template<typename L, typename R>
bool operator!=(const myString<L> &left, const myString<R> &right) {
    if (bool(left == right)) return false;
    return true;
}

template<typename L, typename R>
bool operator>(const myString<L> &left, const myString<R> &right) {
    if (left.get_length() < right.get_length()) return false;
    for (int i = 0; i < right.get_length(); ++i) {
        if (left.str[i] > right.str[i]) return false;
    }
    return true;
}

template<typename L, typename R>
bool operator>=(const myString<L> &left, const myString<R> &right) {
    if (left == right) return true;
    if (left > right) return true;
    return false;
}

template<typename L, typename R>
bool operator<(const myString<L> &left, const myString<R> &right) {
    if (left.get_length() > right.get_length()) return false;
    for (int i = 0; i < left.get_length(); ++i) {
        if (left.str[i] > right.str[i]) return false;
    }
    return true;
}

template<typename L, typename R>
bool operator<=(const myString<L> &left, const myString<R> &right) {
    if (left == right) return true;
    if (left < right) return true;
    return false;
}

template<typename T>
char &myString<T>::operator[](int index) {
    return str[index];
}


#endif //LAB_4_MYSTRING_H

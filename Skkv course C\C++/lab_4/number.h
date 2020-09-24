#pragma once

#include <cstdlib>
#include <fstream>
#include <vector>

struct number {
private:
    static constexpr int base = 1'000'000'000;
    std::vector<int> num;
    bool sign;

    void no_zero();

    friend number short_div(number a, int b);

    int operator[](int i) const;

public:
    number() {};

    number(int a);

    number(const std::string &a);

    size_t size() const;

    friend std::istream &operator>>(std::istream &is, number &a);

    friend std::ostream &operator<<(std::ostream &os, number a);

    friend number operator+(number a, number b);

    number &operator+=(number a);

    friend number operator-(number a, number b);

    number &operator-=(number a);

    friend number operator*(const number &a, const number &b);

    number &operator*=(const number &a);

    friend number operator/(const number &a, const number &b);

    number &operator/=(const number &a);

    friend number operator%(const number &a, const number &b);

    number &operator%=(const number &a);

    friend number sqrt(const number &a);

    friend bool operator==(const number &a, const number &b);

    friend bool operator!=(const number &a, const number &b);

    friend bool operator<(const number &a, const number &b);

    friend bool operator<=(const number &a, const number &b);

    friend bool operator>(const number &a, const number &b);

    friend bool operator>=(const number &a, const number &b);
};

const number NaN("-0");




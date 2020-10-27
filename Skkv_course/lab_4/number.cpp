#include <algorithm>

#include "number.h"

int number::operator[](int i) const {
    return i < this->num.size() ? this->num[i] : 0;
}

size_t number::size() const {
    return this->num.size();
}

void number::no_zero() {
    while (this->size() > 1 && this->num.back() == 0) {
        this->num.pop_back();
    }
}

number::number(int a) {
    if (a < 0) {
        this->sign = false;
        a *= -1;
    } else {
        this->sign = true;
    }
    while (a > 0) {
        this->num.emplace_back(a % number::base);
        a /= number::base;
    }
}

number::number(const std::string &a) {
    this->sign = a.front() != '-';
    this->num.resize(((a.size() - !this->sign) + 8) / 9);

    for (int i = static_cast<int>(a.size()) - 1; i >= !this->sign; i -= 9) {
        if (i >= 9) {
            this->num[(i - !this->sign) / 9] = atoi(a.substr(i - 8, 9).c_str());
        } else {
            this->num[0] = atoi(a.substr(!this->sign, i + this->sign).c_str());
        }
    }
    reverse(this->num.begin(), this->num.end());
}

std::istream &operator>>(std::istream &is, number &a) {
    std::string n;
    is >> n;
    a = number(n);
    return is;
}

std::ostream &operator<<(std::ostream &os, number a) {
    if (a == NaN) {
        os << "NaN";
    } else {
        if (!a.sign) os << "-";
        for (int i = static_cast<int>(a.size()) - 1; i > -1; i--) {
            if (i != a.size() - 1) {
                int h[9];
                int tmp = a.num[i];
                for (int j = 0; j < 9; j++) {
                    h[j] = tmp % 10;
                    tmp /= 10;
                }
                for (int j = 8; j > -1; j--) {
                    os << h[j];
                }
            } else {
                os << a.num[i];
            }
        }
    }
    return os;
}

number operator+(number a, number b) {
    if (a == NaN || b == NaN) {
        return NaN;
    }
    if (a.sign == b.sign) {
        int carry = 0;
        number c;
        c.num.resize(std::max(a.size(), b.size()) + 1);
        for (size_t i = 0; (i < std::max(a.size(), b.size())) || carry; i++) {
            long long tmp = static_cast<long long>(a[i]) + b[i] + carry;
            c.num[i] = tmp % number::base;
            carry = tmp / number::base;
        }
        c.sign = a.sign;
        c.no_zero();
        return c;
    } else if (a.sign && !b.sign) {
        b.sign = true;
        return a - b;
    } else if (!a.sign && b.sign) {
        a.sign = true;
        return b - a;
    }
}

number &number::operator+=(number a) {
    *this = *this + a;
    return *this;
}

number operator-(number a, number b) {
    if (a == NaN || b == NaN) {
        return NaN;
    }
    if (!a.sign && b.sign) {
        b.sign = false;
        return a + b;
    }
    if ((a.sign && !b.sign) || (!a.sign && !b.sign)) {
        b.sign = true;
        return a + b;
    }
    number c;
    c.sign = true;
    if (a < b) {
        std::swap(a, b);
        c.sign = false;
    }

    c.num.resize(a.size());
    int carry = 0;
    for (int i = 0; i < a.size() || carry; i++) {
        long long tmp = static_cast<long long>(a[i]) - b[i] - carry;
        if (tmp < 0) {
            carry = 1;
        } else {
            carry = 0;
        }
        if (carry) {
            tmp += number::base;
        }
        c.num[i] = tmp;
    }
    c.no_zero();
    return c;
}

number &number::operator-=(number a) {
    *this = *this - a;
    return *this;
}

number operator*(const number &a, const number &b) {
    if (a == NaN || b == NaN) {
        return NaN;
    }
    number c;
    c.num.resize(a.size() + b.size());
    for (int i = 0; i < a.size(); i++) {
        int carry = 0;
        for (int j = 0; j < b.size() || carry != 0; j++) {
            long long tmp = static_cast<long long>(a[i]) * b[j] + carry + c[i + j];
            c.num[i + j] = tmp % number::base;
            carry = tmp / number::base;
        }
    }
    c.sign = (a.sign && b.sign) || (!a.sign && !b.sign);
    c.no_zero();
    if (c.size() == 1 && c[0] == 0 && !c.sign) {
        c.sign = true;
    }
    return c;
}

number &number::operator*=(const number &a) {
    *this = *this * a;
    return *this;
}

number short_div(number a, int b) {
    if (a == NaN || b == NaN) {
        return NaN;
    }
    if (b == 0) {
        return NaN;
    }
    int carry = 0;
    for (int i = static_cast<int>(a.size()) - 1; i >= 0; i--) {
        long long tmp = a[i] + static_cast<long long>(carry) * number::base;
        a.num[i] = static_cast<int>(tmp / b);
        carry = static_cast<int>(tmp % b);
    }
    a.no_zero();
    return a;
}

number operator/(const number &a, const number &b) {
    if (a == NaN || b == NaN) {
        return NaN;
    }
    number l = -1;
    number r = a + 1;

    if (b == 0) {
        return NaN;
    }

    while (r - l > 1) {
        number mid = short_div(r + l, 2);
        if (mid * b <= a) {
            l = mid;
        } else {
            r = mid;
        }
    }

    l.sign = (a.sign == b.sign);
    return l;
}

number &number::operator/=(const number &a) {
    *this = *this / a;
    return *this;
}

number operator%(const number &a, const number &b) {
    if (a == NaN || b == NaN) {
        return NaN;
    }
    if (b == 0) {
        return NaN;
    }
    return a - (a / b * b);
}

number &number::operator%=(const number &a) {
    *this = *this % a;
    return *this;
}

number sqrt(const number &a) {
    if (a == NaN) {
        return NaN;
    }
    number l = -1;
    number r = a + 1;

    if (!a.sign) {
        return NaN;
    }

    while (r - l > 1) {
        number mid = short_div(r + l, 2);
        if (mid * mid <= a) {
            l = mid;
        } else {
            r = mid;
        }
    }
    l.sign = true;
    return l;
}

bool operator==(const number &a, const number &b) {
    return (!(a < b) && !(b < a));
}

bool operator!=(const number &a, const number &b) {
    return !(a == b);
}

bool operator<(const number &a, const number &b) {
    if (a.sign != b.sign) {
        return !(a.sign && !b.sign);
    }
    if (a.size() != b.size()) {
        return a.size() < b.size();
    }
    for (int i = static_cast<int>(a.size()) - 1; i > -1; i--) {
        if (a[i] < b[i]) {
            return true;
        } else if (a[i] > b[i]) {
            return false;
        }
    }
    return false;
}

bool operator<=(const number &a, const number &b) {
    return ((a < b) || (a == b));
}

bool operator>(const number &a, const number &b) {
    return !(a <= b);
}

bool operator>=(const number &a, const number &b) {
    return !(a < b);
}


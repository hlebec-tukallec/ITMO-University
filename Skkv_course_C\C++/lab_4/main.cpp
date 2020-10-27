#include <iostream>

#include "number.h"

int main(int argc, char **argv) {
    //lab4 input.txt output.txt

    if (argc < 3) {
        std::cout << "Wrong arguments! Try again.";
        return 1;
    }

    std::ifstream r(argv[1]);
    if (!(r.is_open())) {
        std::cout << "Can't open the input file";
        return 2;
    }

    std::ofstream w(argv[2]);
    if (!(w.is_open())) {
        std::cout << "Can't open the output file";
        return 3;
    }

    number num1, num2;
    r >> num1;

    std::string symbol;
    r >> symbol;

    if (symbol != "#") {
        r >> num2;
    }
    r.close();

    if (symbol == "+") {
        w << num1 + num2;
    } else if (symbol == "-") {
        w << num1 - num2;
    } else if (symbol == "*") {
        w << num1 * num2;
    } else if (symbol == "/") {
        w << num1 / num2;
    } else if (symbol == "%") {
        w << num1 % num2;
    } else if (symbol == "#") {
        w << sqrt(num1);
    } else if (symbol == "<") {
        w << (num1 < num2);
    } else if (symbol == "<=") {
        w << (num1 <= num2);
    } else if (symbol == ">") {
        w << (num1 > num2);
    } else if (symbol == "=>") {
        w << (num1 >= num2);
    } else if (symbol == "==") {
        w << (num1 == num2);
    } else if (symbol == "!=") {
        w << (num1 != num2);
    }

    w.close();
    return 0;
}



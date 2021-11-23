#include <iostream>
#include "addition.hpp"

int sum(int a, int b) {
    return a + b;
}

int add(int a, int b) {
    std::cerr << "log: add(" << a << ", " << b << ")\n";
    return a + b;
}

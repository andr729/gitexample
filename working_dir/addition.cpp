#include <iostream>
#include "addition.hpp"

int add(int a, int b) {
    std::cerr << "log: add(" << a << ", " << b << ")\n";
    return a + b;
}
